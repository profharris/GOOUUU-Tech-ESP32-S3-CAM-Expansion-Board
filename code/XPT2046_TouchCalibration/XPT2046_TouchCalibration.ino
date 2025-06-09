// XPT2046_TouchCalibration.ino
// ILI9341 2.8in 240×320 TFT Display with Touch
// GOOUUU Tech ESP32-S3-CAM Expansion Board

/*******************************************************************************
 * The “XPT2046_Calibrated” library can be found here:
 * https://github.com/ardnew/XPT2046_Calibrated/tree/master
 *
 * The process of calibrating a Touchscreen, at a high-level, consists of:
 *
 * (ONE-TIME)
 *   1. Pick three random points A,B,C (not co-linear) in -Screen- coordinates.
 *   2. For each point p, obtain the corresponding -Touchscreen- coorindate p_t.
 *
 * (ALWAYS/RUNTIME)
 *   3. With all six points (A, B, C, A_t, B_t, C_t), along with the screen
 *      Height and Width for the current orientation (per ‘setRotation()’),
 *      pass a calibration object to the Touchscreen via ‘calibrate()’.
 *
 * Any subsequent calls to get a Touch position (‘getPoint()’ or ‘readData()’)
 * after calling ‘calibrate()’ will return (x,y)-points in -Screen- coordinates
 * instead of -Touchscreen- coordinates - also corrected for Screen orientation!
 *
 * How to use the ‘XPT2046_Calibrated’ library:
 *
 *   1. Usage of this library is identical to ‘XPT2046_Touchscreen’. However,
 *      to enable calibration, after calling ‘begin()’ and ‘setRotation()’,
 *      you must then call ‘calibrate()’ with an appropriate ‘TS_Calibration’
 *      object as the parameter. Afterwards, all calls to obtain Touch positions
 *      (‘getPoint()’ or ‘readData()’) will return (x,y) points in -Screen-
 *      coordinates rather than -Touchscreen- coordinates. This sketch simply
 *      assists with obtaining the parameters required to construct your
 *      ‘TS_Calibration’ object. These parameters are fixed hardware descriptors
 *      that should never change for a given Touchscreen. So once the parameters
 *      are obtained ‘one’ time, you should never have to calculate them again
 *      unless your Screen is moved or removed for some reason.
 *
 * How to use this sketch:
 *
 *   1. The sketch below assists performing Steps 1 & 2 above. Simply update
 *      the GPIO pin defines below per your specific configuration. Ensure the
 *      ‘VERIFY_CALIBRATION’ macro is commented out, then compile and Flash.
 *
 *   2. Once running, “Touch” the center of each crosshair. You will see the
 *      needed point-translation mapping drawn to the Screen (and also printed
 *      to the Serial Console if open). The point on the Left-hand side of each
 *      line is the -Screen- coordinate of the crosshair, and on the Right-hand
 *      side is the -Touchscreen- coordinate for the last Touch.
 *
 *   3. Once all three lines have been drawn, substitute your -Touchscreen-
 *      coordinates into the ‘_touchPoint[]’ array below, and uncomment the
 *      ‘VERIFY_CALIBRATION’ macro below, and then compile and Flash.
 *
 *   4. Now when you “Touch” the crosshairs, both points listed on each line
 *      will be in -Screen- coordinates --one for the crosshair and one for the
 *      Touch!  Verify that the distance between crosshair and Touch coordinate
 *      approaches zero as you approach closer to the center of the crosshair.
 *
 * Be sure to use something pokey, fine-tipped to “Touch” the crosshair center.
 *
 * *** NOTE *** IMPORTANT ***
 *   I seem to get best calibration results by performing Steps 1-2 in Landscape
 *   orientation (rotation=1) with Screen Width×Height=320×240. Then for Step 3,
 *   I can re-use those same 6 points obtained while in Landscape even if I flip
 *   or change the orientation or Screen dimensions to Portrait when calling to
 *   ‘calibrate()’ in my actual project. This is the default configuration for
 *   the sketch below.
 ******************************************************************************/

#include <XPT2046_Calibrated.h>     // XPT2046 Touchscreen Calibration library
#include <Adafruit_ILI9341.h>       // Adafruit ILI9341 TFT Display library
#include <SPI.h>

#define TS_IRQ       -1             // LCD XPT2046 Touchscreen IRQ
#define TS_CS         1             // CS      "   Touchscreen CS
#define TS_DIN        2             // DIN     "   Touchscreen MOSI
#define TS_CLK       42             // CLK     "   Touchscreen SCK
#define TS_DO        41             // DO      "   Touchscreen MISO

#define TFT_CLK      3              // LCD 240×320 ILI9341 TFT SCLK
#define TFT_MISO    46              // SDO     "           TFT MISO
#define TFT_CS      14              // CS      "           TFT CS
#define TFT_MOSI    45              // SDI     "           TFT MOSI
#define TFT_DC      47              // D/C     "           TFT DC
#define TFT_RST     21              // Reset   "           TFT RST
#define TFT_BL      -1              // to 3V3 (always On)  TFT BL

static uint16_t const TFT_WIDTH    = 320;    // Landscape
static uint16_t const TFT_HEIGHT   = 240;    // Orientation
static uint8_t  const TFT_ROTATION = 1U;     // Rotation=1

enum class PointID { NONE = -1, A, B, C, COUNT };

static TS_Point _screenPoint[] = {  // Source points for Calibration
  TS_Point( 13,  11),               // point a
  TS_Point(312, 113),               // point b
  TS_Point(167, 214)                // point c
};

//#define VERIFY_CALIBRATION        // ...initially commemted out
#ifdef VERIFY_CALIBRATION

// Touchscreen points used for Calibration Verification
static TS_Point _touchPoint[] = {
  TS_Point(3795, 3735),             // point a_t
  TS_Point( 482, 2200),             // point b_t
  TS_Point(2084,  583),             // point c_t
};

static TS_Calibration cal(
    _screenPoint[(int)PointID::A], _touchPoint[(int)PointID::A],
    _screenPoint[(int)PointID::B], _touchPoint[(int)PointID::B],
    _screenPoint[(int)PointID::C], _touchPoint[(int)PointID::C],
    TFT_WIDTH, TFT_HEIGHT
);
#endif // VERIFY_CALIBRATION

// -- LOCAL VARIABLES --
#ifdef TS_IRQ
XPT2046_Calibrated ts(TS_CS, TS_IRQ);
#else
XPT2046_Calibrated ts(TS_CS);
#endif // TS_IRQ

//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// -----------------------------------------------------------------------------

// -- UTILITY ROUTINES (DECLARATION) --
inline bool touched();
void crosshair(TS_Point p);
uint16_t distance(TS_Point a, TS_Point b);
void drawMapping(PointID n, TS_Point p);
void updateScreenEdges(TS_Point p);
PointID nearestScreenPoint(TS_Point touch);

// -- ARDUINO MAIN --
void setup() {
  Serial.begin(115200);
  while(!Serial && (millis() <= 1000U)) { continue; }

  tft.begin();
  tft.setRotation(TFT_ROTATION);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_WHITE);

  ts.begin();
  ts.setRotation(TFT_ROTATION);
#ifdef VERIFY_CALIBRATION
  ts.calibrate(cal);
#endif

  // Draw the crosshair on Screen only once
  for(int i=(int)PointID::NONE + 1; i < (int)PointID::COUNT; ++i) {
    crosshair(_screenPoint[i]);
  }
}

void loop() {
  if(touched()) {
    TS_Point p = ts.getPoint();
    //updateScreenEdges(p);
    // Determine which Screen point is closest to this Touch event
    PointID n = nearestScreenPoint(p);

    // Update the corresponding line mapping
    drawMapping(n, p);
    delay(30);
  }
}

// -- UTILITY ROUTINES ---------------------------------------------
inline bool touched() {
#ifdef TIRQ_PIN
  if(ts.tirqTouched()) {
    return ts.touched();
  }
  return false;
#else
  return ts.touched();
#endif
}

void crosshair(TS_Point p) {
  tft.drawCircle   (p.x,     p.y,     6, ILI9341_WHITE);
  tft.drawFastHLine(p.x - 4, p.y,     9, ILI9341_WHITE);
  tft.drawFastVLine(p.x,     p.y - 4, 9, ILI9341_WHITE);
}

uint16_t distance(TS_Point a, TS_Point b) {
  // Calculate the distance between points a and b in whatever 2D coordinate
  // system they both exist. Return an integer distance with native rounding.
  static uint16_t const MAX = ~((uint16_t)0U);
  int32_t dx = b.x - a.x;
  int32_t dy = b.y - a.y;
  uint32_t dsq = (uint32_t)sq(dx) + (uint32_t)sq(dy);
  double d = sqrt(dsq);                 // add 1/2 for rounding
  if(d > ((double)MAX - 0.5)) {
    return MAX;
  } else {
    return (uint16_t)(d + 0.5);         // poor-man's rounding
  }
}

void drawMapping(PointID n, TS_Point tp) {
  static uint8_t const BUF_LEN = 64;
  static char buf[BUF_LEN]     = { '\0' };
  static uint16_t lineHeight   = (uint16_t)(1.5F * 8.0F + 0.5F);
  static uint16_t lineSpace    = 1U;

  int16_t  posX, posY;
  uint16_t sizeW, sizeH;
  uint16_t posLeft = 6U;
  uint16_t posTop  =
    TFT_HEIGHT - (3U - (uint16_t)n) * (lineHeight + lineSpace);

  TS_Point sp = _screenPoint[(int)n];

  // Construct the line buffer
  snprintf(buf, BUF_LEN, "%c (%u,%u) = (%u,%u)",
           (uint8_t)n + 'A', sp.x, sp.y, tp.x, tp.y);

  // Print the current line to Serial port for debugging
  Serial.printf("%s\n", buf);

  // Erase the previous line
  tft.getTextBounds(buf, posLeft, posTop, &posX, &posY, &sizeW, &sizeH);
  tft.fillRect(posX, posY, sizeW, sizeH, ILI9341_BLACK);

  // Draw the current line
  tft.setCursor(posLeft, posTop);
  tft.printf("%s", buf);
}

// -- NOT FOR GENERAL USAGE -- IGNORE THESE --------------------------- BEGIN --
// Approximate calibration only used for determining distance from Touch to
// crosshair while calibrating. You can determine these values by using the
// updateScreenEdges() routine below -- Just call it with the position of
// every Touch event while scrubbing all 4 edges of the Screen with a stylus.
#define XPT2046_X_LO 3963
#define XPT2046_X_HI 338
#define XPT2046_Y_LO 4031
#define XPT2046_Y_HI 211
#define MAP_2D_PORTRAIT(x, y)                                     \
  TS_Point(                                                       \
    (int16_t)map((x), XPT2046_X_LO, XPT2046_X_HI, 0, TFT_WIDTH),  \
    (int16_t)map((y), XPT2046_Y_LO, XPT2046_Y_HI, 0, TFT_HEIGHT)  \
  )
#define MAP_2D_LANDSCAPE(x, y)                                    \
  TS_Point(                                                       \
    (int16_t)map((x), XPT2046_Y_LO, XPT2046_Y_HI, 0, TFT_WIDTH),  \
    (int16_t)map((y), XPT2046_X_LO, XPT2046_X_HI, 0, TFT_HEIGHT)  \
  )

void updateScreenEdges(TS_Point p) {
  static uint16_t xHi = 0xFFFF;
  static uint16_t yHi = 0xFFFF;
  static uint16_t xLo = 0x0;
  static uint16_t yLo = 0x0;
  if(p.x < xHi) { xHi = p.x; }
  if(p.x > xLo) { xLo = p.x; }
  if(p.y < yHi) { yHi = p.y; }
  if(p.y > yLo) { yLo = p.y; }
  Serial.printf("[X_LO, X_HI] = [%u, %u], [Y_LO, Y_HI] = [%u, %u]\n",
                xLo, xHi, yLo, yHi);
}
// -- NOT FOR GENERAL USAGE -- IGNORE THESE ----------------------------- END --

PointID nearestScreenPoint(TS_Point touch) {
#ifdef VERIFY_CALIBRATION
  // The input point is already in Screen coordinates because the
  // Touchscreen has been calibrated. No need to perform translation.
  TS_Point tp = touch;
#else
  // Translate the input point (in Touch coordinates) to Screen
  // coordinates using the hardcoded ranges defined in these macros.
  // Not particularly accurate, but it doesn't need to be.
  TS_Point tp = (TFT_ROTATION & 1U)
    ? MAP_2D_LANDSCAPE(touch.x, touch.y)
    : MAP_2D_PORTRAIT(touch.x, touch.y);
  Serial.printf(
    "Touch{%u, %u} => Screen{%u, %u}\n", touch.x, touch.y, tp.x, tp.y);
#endif

  PointID  near = PointID::NONE;
  uint16_t dist = 0U;
  for(int id=(int)PointID::NONE + 1; id < (int)PointID::COUNT; ++id) {
    // Compute the distance from our (translated) input Touch point
    // to each Screen point to determine minimum distance.
    uint16_t d = distance(tp, _screenPoint[id]);
    if((near == PointID::NONE) || (d < dist)) {
      // New min distance, this is the nearest point to our Touch (so far)
      near = (PointID)id;
      dist = d;
    }
  }
  return near;
}

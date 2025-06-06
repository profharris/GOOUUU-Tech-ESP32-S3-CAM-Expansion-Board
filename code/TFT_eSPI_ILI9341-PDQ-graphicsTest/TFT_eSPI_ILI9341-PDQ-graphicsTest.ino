/* TFT_eSPI_ILI9341-PDQ-graphicsTest.ino
 * LCD 2.8in 240×320 ILI9341 with XPT2046 Touchscreen
 * GOOUUU Tech ESP32-S3-CAM Development Board
 * GOOUUU Tech ESP32-S3-CAM Expansion Board
 *             (...Not required, but it helps.)
 *
 * Adapted from the Adafruit and Xark's PDQ graphicsTest sketch.
 * https://github.com/mboehmerm/Touch-Display-ili9341-320x240/blob/main/Arduino/TFT_graphicstest_PDQ_ili9341_Touch/TFT_graphicstest_PDQ_ili9341_Touch.ino
 * Adapted by: Prof. Michael P. Harris
 *
 * NOTE: TFT_eSPI XPT2046 Touch controller support
 * ¯¯¯¯¯ “The XPT2046 Touchscreen controller is supported for SPI based
 *       displays only. The SPI bus for the Touch controller is SHARED
 *       with the TFT & only an additional Chip Select line is needed.
 *       This support will eventually be deprecated when a suitable
 *       Touchscreen library is available.”
 *
 *       ---This means that Touchscreen support for the GOOUUU Tech
 *       ESP32-S3-CAM Expansion Board is probably not possible since
 *       the SPI pins are NOT SHARED with the TFT on this board.
 *
 * This sketch will work with the TFT_eSPI graphic drivers 【or】
 * the Lovyan LGFX TFT drivers.   ¯¯¯¯¯¯¯¯
 *     ¯¯¯¯¯¯¯¯¯¯¯
 * See end of file for original header text and MIT license info.
 *
 * This sketch uses the GLCD font only.
 *                      ¯¯¯¯¯¯¯¯¯
 * Make sure all the display driver and pin connections are correct
 * by editing the User_Setup.h file in the TFT_eSPI library folder.
 *                ¯¯¯¯¯¯¯¯¯¯¯¯
 * #################################################################
 * ## DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ##
 * #################################################################
 *
 * Serial Monitor output is shown below:
 */

/*******************************************************************
Type-C USB Data cable plugged into Left-side ESP32-S3 USB-OTG port.
                                   ¯¯¯¯¯¯¯¯¯          ¯¯¯¯¯¯¯
Arduino IDE > Tools                                  [CONFIGURATION]
                   Board: "ESP32S3 Dev Module"
         USB CDC On Boot: "Enabled"  **Cable plugged into Left USB**
           CPU Frequency: "240MHz (WiFi)"                 ¯¯¯¯
         USB DFU On Boot: "Disabled"
              Flash Mode: "QIO 80MHz"
              Flash Size: "16MB 128Mb"  【or】
              Flash Size: "8MB 64Mb"    ...check your board!
USB Firmware MSC On Boot: "Disabled"
        Partition Scheme: "16M Flash (2MB APP/12.5MB FATFS)"  【or】
        Partition Scheme: "8MB with spiffs (3MB APP/1.5MB SPIFFS)"
                   PSRAM: "OPI PSRAM"
             Upload Mode: "UART0/Hardware CDC"
            Upload Speed: "115200"
                USB Mode: "Hardware CDC and JTAG"
*******************************************************************/

#include "SPI.h"

//#define Lovyan                    // uncomment to use Lovyan LGFX
#ifdef Lovyan
  #include <LGFX_ESP32_ILI9341.hpp>
  #include <LGFX_TFT_eSPI.hpp>
#else
  #include <TFT_eSPI.h>             // use TFT_eSPI drivers
#endif

// TFT_eSPI pins definition is done in the “User_Setup.h” file!
// Pins: GOOUUU Tech ESP32-S3-CAM Expansion Board
//#define TFT_CLK      3            // LCD 240×320 ILI9341 TFT SCK
//#define TFT_MISO    46            // SDO     "           TFT MISO
//#define TFT_CS      14            // CS      "           TFT CS
//#define TFT_MOSI    45            // SDI     "           TFT MOSI
//#define TFT_DC      47            // D/C     "           TFT DC
//#define TFT_RST     21            // Reset   "           TFT RST
//#define TFT_BL      -1            // to 3V3 (always On)  TFT BL

TFT_eSPI tft = TFT_eSPI();

unsigned long total = 0;
unsigned long tn    = 0;

void setup() {
  Serial.begin(115200);             // Initialize Serial Monitor
  while(!Serial);                   // Wait for Serial Port to open

  tft.init();                       // Initialize TFT Display
  tft.setRotation(0);               // Portrait orientation

  Serial.println(""); Serial.println("");
#ifdef Lovyan
  Serial.println("LovyanGFX library Test!");
  uint16_t calData[8] = {3890, 340, 3900, 3895, 235, 340, 235, 3900};
  tft.setTouchCalibrate(calData);
#else
  Serial.println("Bodmers’ TFT_eSPI library Test!");
  uint16_t calData[5] = { 255, 3560, 355, 3540, 4 }; // Rotation 0
  tft.setTouch(calData);
#endif
} // END: setup()


void loop(void) {
    // First Run, Benchmark test results sent to the Serial Monitor:

    Serial.println(F("Benchmark                Time (microseconds)"));
    Serial.println(F("---------                -------------------"));

    uint32_t usecHaD = testHaD();
    Serial.print(F("HaD pushColor            "));
    Serial.println(usecHaD);
    delay(300);

    uint32_t usecFillScreen = testFillScreen();
    Serial.print(F("Screen fill              "));
    Serial.println(usecFillScreen);
    delay(300);

    uint32_t usecText = testText();
    Serial.print(F("Text                     "));
    Serial.println(usecText);
    delay(300);

    uint32_t usecPixels = testPixels();
    Serial.print(F("Pixels                   "));
    Serial.println(usecPixels);
    delay(300);

    uint32_t usecLines = testLines(TFT_BLUE);
    Serial.print(F("Lines                    "));
    Serial.println(usecLines);
    delay(300);

    uint32_t usecFastLines = testFastLines(TFT_RED, TFT_BLUE);
    Serial.print(F("Horiz/Vert Lines         "));
    Serial.println(usecFastLines);
    delay(300);

    uint32_t usecRects = testRects(TFT_GREEN);
    Serial.print(F("Rectangles     (outline) "));
    Serial.println(usecRects);
    delay(300);

    uint32_t usecFilledRects = testFilledRects(TFT_YELLOW, TFT_MAGENTA);
    Serial.print(F("Rectangles     (filled)  "));
    Serial.println(usecFilledRects);
    delay(300);

    uint32_t usecFilledCircles = testFilledCircles(10, TFT_MAGENTA);
    Serial.print(F("Circles        (filled)  "));
    Serial.println(usecFilledCircles);
    delay(300);

    uint32_t usecCircles = testCircles(10, TFT_WHITE);
    Serial.print(F("Circles        (outline) "));
    Serial.println(usecCircles);
    delay(300);

    uint32_t usecTriangles = testTriangles();
    Serial.print(F("Triangles      (outline) "));
    Serial.println(usecTriangles);
    delay(300);

    uint32_t usecFilledTrangles = testFilledTriangles();
    Serial.print(F("Triangles      (filled)  "));
    Serial.println(usecFilledTrangles);
    delay(300);

    uint32_t usecRoundRects = testRoundRects();
    Serial.print(F("Rounded rects  (outline) "));
    Serial.println(usecRoundRects);
    delay(300);

    uint32_t usedFilledRoundRects = testFilledRoundRects();
    Serial.print(F("Rounded rects  (filled)  "));
    Serial.println(usedFilledRoundRects);
    delay(300);

    Serial.println(F("\nPass 1, Done!"));
    /* ---------------------------------------------------------- */

    // Next Run, Benchmark test results sent to the TFT LCD Display:
    uint16_t c = 4;
    int8_t   d = 1;
    for(int32_t i=0; i < tft.height(); i++) {
      tft.drawFastHLine(0,i, tft.width(), c);
      c += d;
      if(c <= 4 || c >= 11) d = -d;
    }
    tft.setCursor(0,0);
    tft.setTextColor(TFT_MAGENTA);
    tft.setTextSize(2);             // Double the text size

#ifdef Lovyan
    tft.println(F("   LovyanGFX test"));
#else
    tft.println(F("   TFT_eSPI test "));
#endif

    tft.setTextSize(1);             // Normal text size
    tft.setTextColor(TFT_WHITE);
    tft.println(F(""));
    tft.println(F(""));
    tft.setTextColor(tft.color565(0x80, 0x80, 0x80)); // RGB565
    tft.println(F(""));

    tft.setTextColor(TFT_GREEN);
    tft.println(F("Benchmark                Time (µsec)"));
    tft.println(F("---------                -----------"));
    tft.setTextColor(TFT_YELLOW);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("HaD pushColor      "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecHaD);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Screen fill        "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecFillScreen);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Text               "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecText);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Pixels             "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecPixels);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Lines              "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecLines);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Horiz/Vert Lines   "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecFastLines);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Rectangles         "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecRects);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Rectangles-filled  "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecFilledRects);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Circles            "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecCircles);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Circles-filled     "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecFilledCircles);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Triangles          "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecTriangles);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Triangles-filled   "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecFilledTrangles);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Rounded rects      "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usecRoundRects);

    tft.setTextColor(TFT_CYAN); tft.setTextSize(1);
    tft.print(F("Rounded rects-fill "));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    printNice(usedFilledRoundRects);

    tft.setTextSize(1);
    tft.println(F(""));
    tft.setTextColor(TFT_GREEN); tft.setTextSize(2);
    tft.println(F("Benchmark Complete!"));
    delay(3000);
    /* ---------------------------------------------------------- */

//    tft.setTextColor(TFT_RED);
//    tft.print(F(">>> Touch to repeat !"));

//    uint16_t x=0, y=0;        // Touch coordinates for Touch test
//    bool pressed;
//    do {
//      pressed = tft.getTouch(&x, &y);
//    } while(!pressed);        // Touch to repeat Benchmark tests

} // END: loop()

static inline uint32_t micros_start() __attribute__ ((always_inline));
static inline uint32_t micros_start() {
    uint8_t oms = millis();
    while((uint8_t)millis() == oms)
        ;
    return micros();
} // END: micros_start()

void printNice(int32_t v) {
    char str[32] = { 0 };
    sprintf(str, "%d", v);
    for(char *p = (str+strlen(str))-3; p > str; p -= 3) {
        memmove(p+1, p, strlen(p)+1);
        *p = ',';
    }
    while(strlen(str) < 10) {
        memmove(str+1, str, strlen(str)+1);
        *str = ' ';
    }
    tft.println(str);
} // END: printNice()

uint32_t testHaD() {
    // pseudo-code for cheesy RLE
    // start with color1
    // while more input data remaining
    //  count =  0nnnnnnn = 1 byte or 1nnnnnnn nnnnnnnn 2 bytes (0 - 32767)
    //  repeat color count times
    //  toggle color1/color2
    static const uint8_t HaD_240x320[] PROGMEM = {
        0xb9, 0x50, 0x0e, 0x80, 0x93, 0x0e, 0x41, 0x11, 0x80, 0x8d, 0x11, 0x42, 0x12, 0x80, 0x89, 0x12,
        0x45, 0x12, 0x80, 0x85, 0x12, 0x48, 0x12, 0x80, 0x83, 0x12, 0x4a, 0x13, 0x7f, 0x13, 0x4c, 0x13,
        0x7d, 0x13, 0x4e, 0x13, 0x7b, 0x13, 0x50, 0x13, 0x79, 0x13, 0x52, 0x13, 0x77, 0x13, 0x54, 0x13,
        0x75, 0x13, 0x57, 0x11, 0x75, 0x11, 0x5a, 0x11, 0x73, 0x11, 0x5c, 0x11, 0x71, 0x11, 0x5e, 0x10,
        0x71, 0x10, 0x60, 0x10, 0x6f, 0x10, 0x61, 0x10, 0x6f, 0x10, 0x60, 0x11, 0x6f, 0x11, 0x5e, 0x13,
        0x6d, 0x13, 0x5c, 0x14, 0x6d, 0x14, 0x5a, 0x15, 0x6d, 0x15, 0x58, 0x17, 0x6b, 0x17, 0x37, 0x01,
        0x1f, 0x17, 0x6b, 0x17, 0x1f, 0x01, 0x17, 0x02, 0x1d, 0x18, 0x6b, 0x18, 0x1d, 0x02, 0x17, 0x03,
        0x1b, 0x19, 0x6b, 0x19, 0x1b, 0x03, 0x17, 0x05, 0x18, 0x1a, 0x6b, 0x1a, 0x18, 0x05, 0x17, 0x06,
        0x16, 0x1b, 0x6b, 0x1b, 0x16, 0x06, 0x17, 0x07, 0x14, 0x1c, 0x6b, 0x1c, 0x14, 0x07, 0x17, 0x08,
        0x12, 0x1d, 0x6b, 0x1d, 0x12, 0x08, 0x17, 0x09, 0x10, 0x1e, 0x6b, 0x1e, 0x10, 0x09, 0x17, 0x0a,
        0x0e, 0x1f, 0x6b, 0x1f, 0x0e, 0x0a, 0x17, 0x0b, 0x0c, 0x20, 0x6b, 0x20, 0x0c, 0x0b, 0x17, 0x0c,
        0x0b, 0x21, 0x69, 0x21, 0x0b, 0x0c, 0x18, 0x0d, 0x08, 0x23, 0x67, 0x23, 0x08, 0x0d, 0x19, 0x0e,
        0x06, 0x26, 0x63, 0x26, 0x06, 0x0e, 0x19, 0x0f, 0x04, 0x28, 0x61, 0x28, 0x04, 0x0f, 0x19, 0x10,
        0x02, 0x2a, 0x5f, 0x2a, 0x02, 0x10, 0x1a, 0x3c, 0x5d, 0x3c, 0x1b, 0x3d, 0x5b, 0x3d, 0x1c, 0x3d,
        0x59, 0x3d, 0x1d, 0x3e, 0x57, 0x3e, 0x1e, 0x3e, 0x55, 0x3e, 0x1f, 0x40, 0x51, 0x40, 0x20, 0x40,
        0x4f, 0x40, 0x22, 0x40, 0x22, 0x09, 0x22, 0x40, 0x24, 0x40, 0x1a, 0x17, 0x1a, 0x40, 0x26, 0x40,
        0x16, 0x1d, 0x16, 0x40, 0x28, 0x40, 0x12, 0x23, 0x12, 0x40, 0x2a, 0x40, 0x0f, 0x27, 0x0f, 0x40,
        0x2c, 0x41, 0x0b, 0x2b, 0x0b, 0x41, 0x2f, 0x3f, 0x09, 0x2f, 0x09, 0x3f, 0x32, 0x3d, 0x08, 0x33,
        0x08, 0x3d, 0x35, 0x3a, 0x08, 0x35, 0x08, 0x3a, 0x3a, 0x36, 0x07, 0x39, 0x07, 0x36, 0x41, 0x09,
        0x05, 0x23, 0x07, 0x3b, 0x07, 0x23, 0x05, 0x09, 0x54, 0x21, 0x07, 0x3d, 0x07, 0x21, 0x64, 0x1f,
        0x06, 0x41, 0x06, 0x1f, 0x66, 0x1d, 0x06, 0x43, 0x06, 0x1d, 0x68, 0x1b, 0x06, 0x45, 0x06, 0x1b,
        0x6b, 0x18, 0x06, 0x47, 0x06, 0x18, 0x6e, 0x16, 0x06, 0x49, 0x06, 0x16, 0x70, 0x14, 0x06, 0x4b,
        0x06, 0x14, 0x72, 0x13, 0x06, 0x4b, 0x06, 0x13, 0x74, 0x11, 0x06, 0x4d, 0x06, 0x11, 0x76, 0x0f,
        0x06, 0x4f, 0x06, 0x0f, 0x78, 0x0e, 0x05, 0x51, 0x05, 0x0e, 0x7a, 0x0c, 0x06, 0x51, 0x06, 0x0c,
        0x7d, 0x09, 0x06, 0x53, 0x06, 0x09, 0x80, 0x80, 0x08, 0x05, 0x55, 0x05, 0x08, 0x80, 0x82, 0x06,
        0x05, 0x57, 0x05, 0x06, 0x80, 0x84, 0x05, 0x05, 0x57, 0x05, 0x05, 0x80, 0x86, 0x03, 0x05, 0x59,
        0x05, 0x03, 0x80, 0x88, 0x02, 0x05, 0x59, 0x05, 0x02, 0x80, 0x8f, 0x5b, 0x80, 0x95, 0x5b, 0x80,
        0x94, 0x5d, 0x80, 0x93, 0x5d, 0x80, 0x92, 0x5e, 0x80, 0x92, 0x5f, 0x80, 0x91, 0x5f, 0x80, 0x90,
        0x61, 0x80, 0x8f, 0x61, 0x80, 0x8f, 0x61, 0x80, 0x8e, 0x63, 0x80, 0x8d, 0x63, 0x80, 0x8d, 0x63,
        0x80, 0x8d, 0x63, 0x80, 0x8c, 0x19, 0x07, 0x25, 0x07, 0x19, 0x80, 0x8b, 0x16, 0x0d, 0x1f, 0x0d,
        0x16, 0x80, 0x8b, 0x14, 0x11, 0x1b, 0x11, 0x14, 0x80, 0x8b, 0x13, 0x13, 0x19, 0x13, 0x13, 0x80,
        0x8b, 0x12, 0x15, 0x17, 0x15, 0x12, 0x80, 0x8a, 0x12, 0x17, 0x15, 0x17, 0x12, 0x80, 0x89, 0x11,
        0x19, 0x13, 0x19, 0x11, 0x80, 0x89, 0x11, 0x19, 0x13, 0x19, 0x11, 0x80, 0x89, 0x10, 0x1b, 0x11,
        0x1b, 0x10, 0x80, 0x89, 0x0f, 0x1c, 0x11, 0x1c, 0x0f, 0x80, 0x89, 0x0f, 0x1c, 0x11, 0x1c, 0x0f,
        0x80, 0x89, 0x0f, 0x1c, 0x11, 0x1c, 0x0f, 0x80, 0x89, 0x0e, 0x1d, 0x11, 0x1d, 0x0e, 0x80, 0x89,
        0x0e, 0x1c, 0x13, 0x1c, 0x0e, 0x80, 0x89, 0x0e, 0x1b, 0x15, 0x1b, 0x0e, 0x80, 0x89, 0x0e, 0x1b,
        0x15, 0x1b, 0x0e, 0x80, 0x89, 0x0e, 0x1a, 0x17, 0x1a, 0x0e, 0x80, 0x89, 0x0e, 0x18, 0x1b, 0x18,
        0x0e, 0x80, 0x89, 0x0e, 0x16, 0x1f, 0x16, 0x0e, 0x80, 0x89, 0x0e, 0x14, 0x23, 0x14, 0x0e, 0x80,
        0x89, 0x0f, 0x11, 0x27, 0x11, 0x0f, 0x80, 0x89, 0x0f, 0x0e, 0x2d, 0x0e, 0x0f, 0x80, 0x89, 0x0f,
        0x0c, 0x31, 0x0c, 0x0f, 0x80, 0x89, 0x0f, 0x0b, 0x33, 0x0b, 0x0f, 0x80, 0x8a, 0x0f, 0x09, 0x35,
        0x09, 0x0f, 0x80, 0x8b, 0x10, 0x08, 0x35, 0x08, 0x10, 0x80, 0x8b, 0x10, 0x07, 0x37, 0x07, 0x10,
        0x80, 0x8b, 0x11, 0x06, 0x37, 0x06, 0x11, 0x80, 0x8b, 0x12, 0x05, 0x37, 0x05, 0x12, 0x80, 0x8c,
        0x13, 0x03, 0x1b, 0x01, 0x1b, 0x03, 0x13, 0x80, 0x8d, 0x30, 0x03, 0x30, 0x80, 0x8d, 0x30, 0x04,
        0x2f, 0x80, 0x8d, 0x2f, 0x05, 0x2f, 0x80, 0x8e, 0x2e, 0x06, 0x2d, 0x80, 0x8f, 0x2d, 0x07, 0x2d,
        0x80, 0x8f, 0x2d, 0x07, 0x2d, 0x80, 0x90, 0x2c, 0x08, 0x2b, 0x80, 0x91, 0x2b, 0x09, 0x2b, 0x80,
        0x8c, 0x01, 0x05, 0x2a, 0x09, 0x2a, 0x05, 0x01, 0x80, 0x85, 0x03, 0x05, 0x2a, 0x09, 0x2a, 0x05,
        0x03, 0x80, 0x82, 0x04, 0x05, 0x2a, 0x09, 0x2a, 0x04, 0x05, 0x80, 0x80, 0x06, 0x05, 0x29, 0x04,
        0x02, 0x03, 0x29, 0x05, 0x06, 0x7e, 0x07, 0x05, 0x29, 0x03, 0x03, 0x03, 0x29, 0x05, 0x07, 0x7c,
        0x09, 0x05, 0x28, 0x02, 0x05, 0x02, 0x28, 0x05, 0x09, 0x7a, 0x0a, 0x05, 0x28, 0x02, 0x05, 0x02,
        0x28, 0x05, 0x0a, 0x78, 0x0c, 0x05, 0x27, 0x02, 0x05, 0x02, 0x27, 0x05, 0x0c, 0x76, 0x0d, 0x06,
        0x26, 0x01, 0x07, 0x01, 0x26, 0x06, 0x0d, 0x73, 0x10, 0x05, 0x55, 0x05, 0x10, 0x70, 0x12, 0x05,
        0x53, 0x05, 0x12, 0x6e, 0x13, 0x06, 0x51, 0x06, 0x13, 0x6c, 0x15, 0x05, 0x51, 0x05, 0x15, 0x6a,
        0x16, 0x06, 0x4f, 0x06, 0x16, 0x68, 0x18, 0x06, 0x4d, 0x06, 0x18, 0x66, 0x1a, 0x06, 0x4b, 0x06,
        0x1a, 0x64, 0x1c, 0x06, 0x49, 0x06, 0x1c, 0x55, 0x07, 0x05, 0x1e, 0x06, 0x49, 0x06, 0x1e, 0x05,
        0x07, 0x42, 0x30, 0x06, 0x47, 0x06, 0x30, 0x3a, 0x34, 0x06, 0x45, 0x06, 0x34, 0x35, 0x37, 0x06,
        0x43, 0x06, 0x37, 0x32, 0x39, 0x07, 0x3f, 0x07, 0x39, 0x2f, 0x3c, 0x07, 0x3d, 0x07, 0x3c, 0x2c,
        0x3e, 0x07, 0x3b, 0x07, 0x3e, 0x2a, 0x40, 0x06, 0x3b, 0x06, 0x40, 0x28, 0x40, 0x06, 0x3c, 0x07,
        0x40, 0x26, 0x3f, 0x08, 0x3d, 0x08, 0x3f, 0x24, 0x3f, 0x09, 0x3d, 0x09, 0x3f, 0x22, 0x3f, 0x0a,
        0x14, 0x01, 0x13, 0x02, 0x13, 0x0a, 0x3f, 0x20, 0x3f, 0x0b, 0x14, 0x01, 0x13, 0x02, 0x13, 0x0b,
        0x3f, 0x1f, 0x3e, 0x0c, 0x14, 0x01, 0x13, 0x02, 0x13, 0x0c, 0x3e, 0x1e, 0x3e, 0x0d, 0x13, 0x02,
        0x13, 0x02, 0x13, 0x0d, 0x3e, 0x1d, 0x3d, 0x0e, 0x13, 0x02, 0x13, 0x02, 0x13, 0x0e, 0x3d, 0x1c,
        0x3c, 0x11, 0x11, 0x04, 0x11, 0x04, 0x11, 0x11, 0x3c, 0x1b, 0x10, 0x01, 0x2a, 0x12, 0x11, 0x04,
        0x11, 0x04, 0x11, 0x12, 0x2a, 0x01, 0x10, 0x1a, 0x0f, 0x04, 0x28, 0x14, 0x0f, 0x06, 0x0f, 0x06,
        0x0f, 0x14, 0x28, 0x04, 0x0f, 0x19, 0x0e, 0x06, 0x26, 0x16, 0x0d, 0x08, 0x0d, 0x08, 0x0d, 0x16,
        0x26, 0x06, 0x0e, 0x19, 0x0d, 0x07, 0x25, 0x18, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x18, 0x25, 0x07,
        0x0d, 0x19, 0x0c, 0x09, 0x23, 0x1c, 0x06, 0x0f, 0x05, 0x10, 0x05, 0x1c, 0x23, 0x09, 0x0c, 0x18,
        0x0c, 0x0b, 0x21, 0x69, 0x21, 0x0b, 0x0c, 0x17, 0x0b, 0x0d, 0x1f, 0x6b, 0x1f, 0x0d, 0x0b, 0x17,
        0x0a, 0x0f, 0x1e, 0x6b, 0x1e, 0x0f, 0x0a, 0x17, 0x09, 0x11, 0x1d, 0x6b, 0x1d, 0x11, 0x09, 0x17,
        0x07, 0x14, 0x1c, 0x6b, 0x1c, 0x14, 0x07, 0x17, 0x06, 0x16, 0x1b, 0x6b, 0x1b, 0x16, 0x06, 0x17,
        0x05, 0x18, 0x1a, 0x6b, 0x1a, 0x18, 0x05, 0x17, 0x04, 0x1a, 0x19, 0x6b, 0x19, 0x1a, 0x04, 0x17,
        0x03, 0x1b, 0x19, 0x6b, 0x19, 0x1b, 0x03, 0x17, 0x02, 0x1d, 0x18, 0x6b, 0x18, 0x1d, 0x02, 0x37,
        0x17, 0x6b, 0x17, 0x58, 0x16, 0x6b, 0x16, 0x5a, 0x14, 0x6d, 0x14, 0x5c, 0x13, 0x6d, 0x13, 0x5e,
        0x12, 0x6d, 0x12, 0x60, 0x10, 0x6f, 0x10, 0x61, 0x10, 0x6f, 0x10, 0x60, 0x11, 0x6f, 0x11, 0x5e,
        0x11, 0x71, 0x11, 0x5c, 0x12, 0x71, 0x12, 0x5a, 0x12, 0x73, 0x12, 0x58, 0x12, 0x75, 0x12, 0x56,
        0x13, 0x75, 0x13, 0x54, 0x13, 0x77, 0x13, 0x51, 0x14, 0x79, 0x14, 0x4e, 0x14, 0x7b, 0x14, 0x4c,
        0x14, 0x7d, 0x14, 0x4a, 0x14, 0x7f, 0x14, 0x48, 0x13, 0x80, 0x83, 0x13, 0x46, 0x13, 0x80, 0x85,
        0x13, 0x44, 0x12, 0x80, 0x89, 0x12, 0x42, 0x11, 0x80, 0x8d, 0x11, 0x40, 0x0f, 0x80, 0x93, 0x0f,
        0x45, 0x04, 0x80, 0x9d, 0x04, 0xb9, 0x56,
    };
    tft.fillScreen(TFT_BLACK);          // Clear the screen          // Clear the screen
    uint32_t start = micros_start();
    for(int i=0; i < 0x10; i++) {
        tft.setAddrWindow(0, 0, 240, 320);
        uint16_t cnt       = 0;
        uint16_t color     = tft.color565((i << 4) | i, (i << 4) | i, (i << 4) | i);
        uint16_t curcolor  = 0;
        const uint8_t *cmp = &HaD_240x320[0];

        tft.startWrite();
        while(cmp < &HaD_240x320[sizeof(HaD_240x320)]) {
            cnt = pgm_read_byte(cmp++);
            if(cnt & 0x80)
              cnt = ((cnt & 0x7f) << 8) | pgm_read_byte(cmp++);
            tft.pushColor(curcolor, cnt);   // PDQ_GFX has count
            curcolor ^= color;
        }
        tft.endWrite();
    }
    uint32_t t = micros() - start;
    tft.setTextColor(TFT_YELLOW);
    tft.setTextSize(2);
    tft.setCursor(8,285);
    tft.print(F("HaD_240x320"));
    tft.setCursor(96,300);
    tft.print(F("testHaD"));
    delay(3 * 1000L);
    return t;
} // END: testHaD()

uint32_t testFillScreen() {
    uint32_t start = micros_start();
    // Shortened this tedious test!
    tft.fillScreen(TFT_WHITE);
    tft.fillScreen(TFT_RED);
    tft.fillScreen(TFT_GREEN);
    tft.fillScreen(TFT_BLUE);
    tft.fillScreen(TFT_BLACK);          // Clear the screen
    return (micros() - start)/5;
} // END: testFillScreen()

uint32_t testText() {
    tft.fillScreen(TFT_BLACK);          // Clear the screen
    uint32_t start = micros_start();
    tft.setCursor(0,0);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);  tft.setTextSize(1);
    tft.println(F("Hello, World!"));
    tft.setTextSize(2);
    tft.setTextColor(tft.color565(0xff, 0x00, 0x00));
    tft.print(F("RED "));
    tft.setTextColor(tft.color565(0x00, 0xff, 0x00));
    tft.print(F("GREEN "));
    tft.setTextColor(tft.color565(0x00, 0x00, 0xff));
    tft.println(F("BLUE"));
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    tft.println(1234.56);
    tft.setTextColor(TFT_RED);      tft.setTextSize(3);
    tft.println(0xDEADBEEF, HEX);
    tft.println();
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(5);
    tft.println(F("Groop"));
    tft.setTextSize(2);
    tft.println(F("I implore thee,"));
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(1);
    tft.println(F("My foonting turlingdromes."));
    tft.println(F("And hooptiously drangle me"));
    tft.println(F("with crinkly bindlewurdles."));
    tft.println(F("Or I will rend thee"));
    tft.println(F("in the gobberwarts"));
    tft.println(F("with my blurglecruncheon,"));
    tft.println(F("See if I don't!"));
    tft.println(F(""));
    tft.println(F(""));
    tft.setTextColor(TFT_MAGENTA);
    tft.setTextSize(6);
    tft.println(F("Woot!"));
    uint32_t t = micros() - start;
    delay(1000);
    return t;
} // END: testText()

uint32_t testPixels() {
    int32_t      w = tft.width();
    int32_t      h = tft.height();
    uint32_t start = micros_start();
    tft.startWrite();
    for(uint16_t y=0; y < h; y++) {
        for(uint16_t x=0; x < w; x++) {
            tft.drawPixel(x,y, tft.color565(x<<3, y<<3, x*y));
        }
    }
    tft.endWrite();
    return micros() - start;
} // END: testPixels()


uint32_t testLines(uint16_t color) {
    uint32_t start, t;
    int32_t x1, y1, x2, y2;
    int32_t w = tft.width();
    int32_t h = tft.height();

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    x1    = y1 = 0;
    y2    = h - 1;
    start = micros_start();

    for(x2=0; x2 < w; x2+=6) {
        tft.drawLine(x1,y1, x2,y2, color);
    }
    x2 = w - 1;
    for(y2=0; y2 < h; y2+=6) {
        tft.drawLine(x1,y1, x2,y2, color);
    }
    t = micros() - start; // fillScreen doesn't count against timing

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    x1    = w - 1;
    y1    = 0;
    y2    = h - 1;
    start = micros_start();

    for(x2=0; x2 < w; x2+=6) {
        tft.drawLine(x1,y1, x2,y2, color);
    }
    x2=0;
    for(y2=0; y2 < h; y2+=6) {
        tft.drawLine(x1,y1, x2,y2, color);
    }
    t += micros() - start;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    x1    = 0;
    y1    = h - 1;
    y2    = 0;
    start = micros_start();

    for(x2=0; x2 < w; x2+=6) {
        tft.drawLine(x1,y1, x2,y2, color);
    }
    x2 = w - 1;
    for(y2=0; y2 < h; y2+=6) {
        tft.drawLine(x1,y1, x2,y2, color);
    }
    t += micros() - start;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    x1    = w - 1;
    y1    = h - 1;
    y2    = 0;
    start = micros_start();

    for(x2=0; x2 < w; x2+=6) {
        tft.drawLine(x1,y1, x2,y2, color);
    }
    x2 = 0;
    for(y2=0; y2 < h; y2+=6) {
        tft.drawLine(x1,y1, x2,y2, color);
    }
    t += micros() - start;

    return t;
} // END: testLines()

uint32_t testFastLines(uint16_t color1, uint16_t color2) {
    uint32_t start;
    int32_t  x, y;
    int32_t  w = tft.width();
    int32_t  h = tft.height();

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    start = micros_start();

    for(y=0; y < h; y += 5)
        tft.drawFastHLine(0, y, w, color1);
    for(x=0; x < w; x += 5)
        tft.drawFastVLine(x, 0, h, color2);

    return micros() - start;
} // END: testFastLines()

uint32_t testRects(uint16_t color) {
    uint32_t start;
    int32_t  n, i, i2;
    int32_t  cx = tft.width() / 2;
    int32_t  cy = tft.height() / 2;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    n = min(tft.width(), tft.height());
    start = micros_start();
    for(i = 2; i < n; i+=6) {
        i2 = i / 2;
        tft.drawRect(cx-i2,cy-i2, i,i, color);
    }

    return micros() - start;
} // END: testRects()

uint32_t testFilledRects(uint16_t color1, uint16_t color2) {
    uint32_t start, t = 0;
    int32_t  n, i, i2;
    int32_t  cx = tft.width() / 2 - 1;
    int32_t  cy = tft.height() / 2 - 1;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    n = min(tft.width(), tft.height());
    for(i=n; i > 0; i-=6) {
        i2 = i / 2;
        start = micros_start();
        tft.fillRect(cx-i2,cy-i2, i,i, color1);
        t += micros() - start;

        // Outlines are not included in timing results
        tft.drawRect(cx-i2,cy-i2, i,i, color2);
    }
    return t;
} // END: testFilledRects()

uint32_t testFilledCircles(uint8_t radius, uint16_t color) {
    uint32_t start;
    int32_t  x, y, w = tft.width(), h = tft.height(), r2 = radius*2;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    start = micros_start();
    for(x = radius; x < w; x += r2) {
        for(y = radius; y < h; y += r2) {
            tft.fillCircle(x,y, radius, color);
        }
    }
    return micros() - start;
} // END: testFilledCircles()

uint32_t testCircles(uint8_t radius, uint16_t color) {
    uint32_t start;
    int32_t  x, y, r2 = radius * 2;
    int32_t  w = tft.width() + radius;
    int32_t  h = tft.height() + radius;

    // Screen is not cleared for this one -- this is
    // intentional and does not affect the reported time.
    start = micros_start();
    for(x=0; x < w; x += r2) {
        for(y=0; y < h; y += r2) {
            tft.drawCircle(x,y, radius, color);
        }
    }
    return micros() - start;
} // END: testCircles()

uint32_t testTriangles() {
    uint32_t start;
    int32_t  n, i;
    int32_t  cx = tft.width()/ 2 - 1;
    int32_t  cy = tft.height() / 2 - 1;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    n = min(cx, cy);
    start = micros_start();
    for(i=0; i < n; i+=5) {
        tft.drawTriangle(
            cx  , cy-i,     // peak
            cx-i, cy+i,     // bottom Left
            cx+i, cy+i,     // bottom Right
            tft.color565(0, 0, i));
    }
    return micros() - start;
} // END: testTriangles()

uint32_t testFilledTriangles() {
    uint32_t start, t = 0;
    int32_t  i;
    int32_t  cx = tft.width() / 2 - 1;
    int32_t  cy = tft.height() / 2 - 1;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    start = micros_start();
    for(i = min(cx,cy); i > 10; i-=5) {
        start = micros_start();
        tft.fillTriangle(cx,cy-i, cx-i,cy+i, cx+i,cy+i,
                         tft.color565(0, i, i));
        t += micros() - start;
        tft.drawTriangle(cx,cy-i, cx-i,cy+i, cx+i,cy+i,
                         tft.color565(i, i, 0));
    }
    return t;
} // END: testFilledTriangles()

uint32_t testRoundRects() {
    uint32_t start;
    int32_t  w, i, i2;
    int32_t  cx = tft.width() / 2 - 1;
    int32_t  cy = tft.height() / 2 - 1;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    w = min(tft.width(), tft.height());
    start = micros_start();
    for(i=0; i < w; i+=6) {
        i2 = i / 2;
        tft.drawRoundRect(cx-i2,cy-i2, i,i, i/8, tft.color565(i,0,0));
    }
    return micros() - start;
} // END: testRoundRects()

uint32_t testFilledRoundRects() {
    uint32_t start;
    int32_t  i, i2;
    int32_t  cx = tft.width() / 2 - 1;
    int32_t  cy = tft.height() / 2 - 1;

    tft.fillScreen(TFT_BLACK);          // Clear the screen
    start = micros_start();
    for(i = min(tft.width(), tft.height()); i > 20; i-=6) {
        i2 = i / 2;
        tft.fillRoundRect(cx-i2,cy-i2, i,i, i/8, tft.color565(0,i,0));
    }
    return micros() - start;
} // END: testFilledRoundRects()

/*******************************************************************
Serial Monitor:
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
Bodmers’ TFT_eSPI library Test!

Benchmark                Time (microseconds)
---------                -------------------
HaD pushColor            265641
Screen fill              15908
Text                     12137
Pixels                   183246
Lines                    198905
Horiz/Vert Lines         8151
Rectangles (outline)     4991
Rectangles (filled)      165534
Circles (filled)         29883
Circles (outline)        19980
Triangles (outline)      12509
Triangles (filled)       61090
Rounded rects (outline)  11062
Rounded rects (filled)   168368

Pass 1, Done!
*******************************************************************/

/* =================================================================
// User_Setup.h

//                   TTF_eSPI USER DEFINED SETTINGS
// Set driver type, fonts to be loaded, pins & SPI control method etc.
//
// See the “User_Setup_Select.h” file if you wish to be able to define
// multiple setups and then easily select which setup file is used by
// the compiler.
//
// If this file is edited correctly then all the library example
// sketches should run without the need to make any more changes for
// a particular hardware setup! Note that some sketches are designed
// for a particular TFT pixel Width/Height
//
// #################################################################
// Section 1. Call up the right driver file and any options for it
// #################################################################

#define ILI9341_DRIVER

//#define TFT_INVERSION_OFF

// #################################################################
// Section 2. Define the pins used to interface with the display
// #################################################################

//#define TFT_BL      -1            // to 3V3 (always On)  TFT BL
//#define TFT_BACKLIGHT_ON HIGH     // Level to turn BackLight ON (HIGH/LOW)

// ## EDIT THE PIN NUMBERS IN THE LINES FOLLOWING TO SUIT YOUR ESP32 SETUP ##

// For ESP32-S3 Dev board (only tested with ILI9341 display)
// The hardware SPI can be mapped to any pins

// Pins: GOOUUU Tech ESP32-S3-CAM Expansion Board
#define TFT_SCLK     3              // LCD 240×320 ILI9341 TFT SCK
#define TFT_MISO    46              // SDO     "           TFT MISO
#define TFT_CS      14              // CS      "           TFT CS
#define TFT_MOSI    45              // SDI     "           TFT MOSI
#define TFT_DC      47              // D/C     "           TFT DC
#define TFT_RST     21              // Reset   "           TFT RST

#define TOUCH_CS     1     // Chip select pin (T_CS) of Touchscreen

// #################################################################
// Section 3. Define the fonts that are to be used here
// #################################################################

#define LOAD_GLCD   // Font 1. Adafruit   8 pixel high font, needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small     16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium    26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large     48 pixel high font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7-Segment 48 pixel high font, needs ~2438 bytes in FLASH, only characters 1234567890:.
#define LOAD_FONT8  // Font 8. Large     75 pixel high font, needs ~3256 bytes in FLASH, only characters 1234567890:-.
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define SMOOTH_FONT

// #################################################################
// Section 4. Other options
// #################################################################

//#define SPI_FREQUENCY        20000000
#define SPI_FREQUENCY        27000000
//#define SPI_FREQUENCY        40000000

// Optional reduced SPI frequency for reading TFT
#define SPI_READ_FREQUENCY   20000000

#define SPI_TOUCH_FREQUENCY  2500000

// #define SUPPORT_TRANSACTIONS
================================================================= */

/*******************************************************************
  Original sketch text:

  This is an example sketch for the Adafruit 2.2" SPI display.
  This library works with the Adafruit 2.2" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/1480

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required
  to interface (RST is optional)
  Adafruit invests time and resources providing this open source
  code, please support Adafruit and open-source hardware by
  purchasing products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ******************************************************************/

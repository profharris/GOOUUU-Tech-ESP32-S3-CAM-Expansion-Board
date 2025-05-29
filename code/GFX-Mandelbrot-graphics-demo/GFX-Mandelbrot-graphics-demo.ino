/* GFX-Mandelbrot-graphics-demo.ino
 * LCD 2.8in 240×320 ILI9341 with Touch
 * GOOUUU Tech ESP32-S3-CAM Development Board
 * GOOUUU Tech ESP32-S3-CAM Expansion Board
 *             (...Not required, but it helps.)
 *
 * Mandelbrot Test Program to exercise the 240×320 ILI9341 TFT LCD
 * with touch, using the GFX graphics and Touch Screen libraries.
 * Based loosely on an Adafruit Mandelbrot example.
 * Adapted by: Prof. Michael P. Harris
 *
 * GOOUUU Tech ESP32-S3-CAM Expansion Board Diagram
.___________________________________________________________________________________.
| Ø  .………. ¬R4        S1·2·3·4      ¬R6   .-----------.  U2  P1·2·3·4             Ø |
|    ¦W Ø¦         GND • • • •           —ô 5V0 DHT11 ¦   Ø¨¨¦•¦ô¦o¦o¦¨¨Ø    I²C    |
|5V0 ¦5  ¦«—|•|VR  5V0 ô ô ô ô  |•|U3 —» —oDATA sensor¦   ¦   G V S S   ¦ Interface |
|    ¦0  ¦  |•|G1  SIG o o o o  |•|G2    —× n/c  temp ¦   ¦   N C C D   ¦ ————————— |
|GND ¦5  ¦  P7         G G G G  P8       —• GND  humi ¦   ¦   D C L A   ¦ GND — GND |
|    ¯¨¨¨¯             3 3 4 3        U3  '-----------'   ¦             ¦ VCC — 5V0 |
| R3 VR/POT            8 9 0 7                            ¦ 0.96″ OLED  ¦ SCL — G41 |
|                        ._______________.                ¦   64×128    ¦ SDA — G42 |
|                        ¦ .….…. .…. .……¯¦   G##~ SD_Card Ø……¨¨¨¨¨¨¨¨………Ø           |
|     DVP Camera ´_G##   ¦ ¦ ¦ ¦_¦ ¦_¦   ¦   G##÷ PSRAM                             |
|                     .——¦ ¦ ¦           ¦——.                                       |
|TXD ¤ ö 3V3       3V3|ö:¦——.··. .————/:•¦:¤|G43  TX› LED      .__SPI-LCD__ESP32-S3_|
|RXD o o EN        RST|o:¦  WiFi ß    '——¦:o|G44  RX‹          ¦_1. T_IRQ      × N/C|
| G1 o © G4      ´_G4 |©:¦  ˜¨¨˜ °       ¦:o|G1   VR• (T_CS)   ¦_2. T_CS       G1   |
| G2 o © G5      ´_G5 |©:¦ ESP32S3-N16R8 ¦:o|G2   U3• (T_DIN)  ¦_3. T_DIN      G2   |
|G42 o © G6      ´_G6 |©:¦         .………….¦:o|G42  SDA (T_CLK)  ¦_4. T_CLK      G42  |
|G41 o © G7      ´_G7 |©:¦ ŒÆ F©   ¦QRCD¦¦:o|G41  SCL (T_DO)   ¦_5. T_DO       G41  |
|G40 õ © G15     ´_G15|©:¦ ° N16R8 '…………'¦:õ|G40~ SD_DATA   •S3¦_6. SDO (MISO) G46  |
|G39 õ © G16     ´_G16|©:'———————————————':õ|G39~ SD_CLK    •S2¦_7. LED (BL)   3V3  |
|G38 õ © G17     ´_G17|© .………………………………………. õ|G38~ SD_CMD    •S1¦_8. SCK        G3   |
|G37 ð © G18     ´_G18|© ¦ ::::::::::::: ¦ ð|G37÷ PSRAM     •S4¦_9. SDI (MOSI) G45  |
|G36 ð © G8      ´_G8 |© ¦    Camera     ¦ ð|G36÷ PSRAM        ¦10. DC         G47  |
|G35 ð o G3  (SCK) G3 |o ¯¯:::::::::::::¯¯ ð|G35÷ PSRAM        ¦11. RST        G21  |
| G0 o o G46 (SDO) G46|o      GOOUUU       o|G0   ‹BOOT›       ¦12. CS         G14  |
|G45 o © G9      ´_G9 |©   ESP32-S3-CAM    o|G45      (SDI)    ¦13. GND        GND  |
|G48 ¤ © G10     ´_G10|©   ¬ ¬     ¤ ¤ ‹¤› ¤|G48  RGB LED      ¦14. VCC        5V0  |
|G47 o © G11     ´_G11|©   ¨ ¨   PWR TX 48 o|G47      (DC)     '————————————————————|
|G21 o © G12     ´_G12|©      ......       o|G21      (RST)                         |
|G20 o © G13     ´_G13|© RST ¦CH304G¦ BOOT ø|G20  D-            GOOUUU              |
|G19 o o G14 (CS)  G14|o ‹•›  ''''''   ‹•› ø|G19  D+     (ESP32-S3-CAM) V1.2        |
|GND • ô 5V0       5V0|ô ._____.O T._____. •|GND      2.8″ SPI TFT LCD 240×320      |
|                     |  | USB |T T| USB |  |                                       |
|G46: Input Only      |  |  C  |G L|  C  |  |                  M     M T   T   T    |
|         ¬   ¬       '——'ESP32'———'CH343'——'        V G   R   O S L I C T D T I    |
|         R5 R7      R1¬ R2¬                         C N C S D S C E S L C I D R    |
|          ¤   ¤      ‹•›   ‹•›  |USB-C|   ¤         C D S T C I K D O K S N O Q    |
| Ø       D2  D3      RST   KEY  '—————'  D1        ¦ô¦•¦o¦o¦o¦o¦o¦ö¦•¦o¦o¦o¦o¦×¦ Ø |
'———————————————————————————————————————————————————————————————————————————————————'
 Pinout:   G   P       E     G             T         5 G G G G G G 3 G G G G G ×
           4   W       N     0             X         V N 1 2 4 4 3 V 4 4 1 2 4
           8   R                                     0 D 4 1 7 5   3 6 2     1
*/

#include "SPI.h"                    // Arduino standard SPI library
#include "Adafruit_GFX.h"           // Adafruit GFX Graphics library
#include "Adafruit_ILI9341.h"       // Adafruit ILI9341 TFT library
#include "XPT2046_Touchscreen.h"    // XPT2046 Touch Screen library

#define TOUCH_IRQ   -1              // LCD 240×320 XPT2046 Touch IRQ
#define TOUCH_CS     1              // CS      "           Touch CS
#define TOUCH_DIN    2              // MISO    "           Touch DIN
#define TOUCH_CLK   42              // SCL     "           Touch CLK
#define TOUCH_DO    41              // MISO    "           Touch DO

#define TFT_SCK      3              // LCD 240×320 ILI9341 TFT SCK
#define TFT_MISO    46              // SDO     "           TFT MISO
#define TFT_MOSI    45              // SDI     "           TFT MOSI
#define TFT_CS      14              //         "           TFT CS
#define TFT_DC      47              //         "           TFT DC
#define TFT_RST     21              //         "           TFT RST
#define TFT_BL      -1              // to 3V3 (always On)  TFT BL

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

XPT2046_Touchscreen ts(TOUCH_CS);

const int16_t
  bits        =  12,    // Fractional resolution
  pixelWidth  = 240,    // TFT dimensions Portrait orientation
  pixelHeight = 320,    //      "           "
  iterations  =  30;    // Fractal iteration limit or 'dwell'
float
  centerReal  =  -0.6,  // Image center point in a complex plane
  centerImag  =   0.0,
  rangeReal   =   3.0,  // Image coverage in a complex plane
  rangeImag   =   3.0;

boolean isTouched = false;  // Touch Screen flag


void setup() {
  Serial.begin(115200);          // Initialize Serial communication
  while(!Serial);                // Wait for the Serial Port to open

  Serial.println("GFX Mandelbrot ~ Tap screen to increase zoom");

  tft.begin();                   // Init TFT LCD screen controller
  tft.setRotation(1);            // LCD TFT Landscape orientation
  tft.fillScreen(ILI9341_BLACK); // Clear the screen

  ts.begin();                    // Init Touch Screen controller
  ts.setRotation(3);             // Match Touch Screen orientation
}

void loop() {
  int64_t  n, a, b, a2, b2, posReal, posImag;
  uint32_t startTime, elapsedTime;

  int32_t
    startReal = (int64_t)((centerReal - rangeReal * 0.5)   * (float)(1 << bits)),
    startImag = (int64_t)((centerImag + rangeImag * 0.5)   * (float)(1 << bits)),
    incReal   = (int64_t)((rangeReal / (float)pixelWidth)  * (float)(1 << bits)),
    incImag   = (int64_t)((rangeImag / (float)pixelHeight) * (float)(1 << bits));

  startTime = millis();   // Calculate time taken to render an image
  posImag   = startImag;
  for(int y=0; y < pixelHeight; y++) {
    posReal = startReal;
    for(int x=0; x < pixelWidth; x++) {
      a = posReal;
      b = posImag;
      for(n=iterations; n > 0 ; n--) {
        a2 = (a * a) >> bits;
        b2 = (b * b) >> bits;
        if((a2 + b2) >= (4 << bits)) break;
        b  = posImag + ((a * b) >> (bits - 1));
        a  = posReal + a2 - b2;
      }
      tft.drawPixel(x,y, (n * 29)<<8 | (n * 67));
      // Adjust the 29 and/or 67 to affect colors...
      posReal += incReal;
    }
    posImag -= incImag;
  }

  elapsedTime = millis() - startTime;
  Serial.print("Mandelbrot Rendering took ");
  Serial.print(elapsedTime/1000.0); Serial.println(" seconds.");

  tft.setCursor(2,10);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("Pass Complete: ");
  tft.println(rangeReal);

  while(isTouched == false) { // When render complete wait for Touch
    isTouched = ts.touched(); // Check for Touch...
  }
  if(isTouched) {
    tft.fillScreen(ILI9341_BLACK); // Clear the screen
    TS_Point p = ts.getPoint();    // ..Touch info to Serial Monitor
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.println(p.y);
    rangeReal *= 0.90;              // Zoom In each iteration
    rangeImag *= 0.90;
    isTouched = false;              // Reset Touch Screen flag
    if(rangeReal < 1.3) {           // Reset the Zoom
       rangeReal = 3.0;
       rangeImag = 3.0;
    }
  }
}

/* GFX_ILI9341-graphicsTest.ino
 * LCD 2.8in 240×320 ILI9341 with XPT2046 Touchscreen
 * GOOUUU Tech ESP32-S3-CAM Development Board
 * GOOUUU Tech ESP32-S3-CAM Expansion Board
 *             (...Not required, but it helps.)
 *
 * Original written by Limor Fried/Ladyada for Adafruit Industries.
 * Adapted by: Prof. Michael P. Harris
 */

/*******************************************************************
Type-C USB Data cable plugged into the Right-side TTL/UART port.

Arduino IDE > Tools                                  [CONFIGURATION]
                   Board: "ESP32S3 Dev Module"
         USB CDC On Boot: "Disabled"  * Sketch locks up if ENABLED *
           CPU Frequency: "240MHz (WiFi)"
         USB DFU On Boot: "Disabled"
              Flash Mode: "QIO 80MHz"
              Flash Size: "16MB 128Mb"  -or-
              Flash Size: "8MB 64Mb"   check your board!
USB Firmware MSC On Boot: "Disabled"
        Partition Scheme: "16M Flash (2MB APP/12.5MB FATFS)"  -or-
        Partition Scheme: "8MB with spiffs (3MB APP/1.5MB SPIFFS)"
                   PSRAM: "QSPI PSRAM"
             Upload Mode: "UART0/Hardware CDC"
            Upload Speed: "115200"
                USB Mode: "Hardware CDC and JTAG"
*******************************************************************/

#include "SPI.h"                    // Arduino standard SPI library
#include "Adafruit_GFX.h"           // Adafruit GFX Graphic library
#include "Adafruit_ILI9341.h"       // Adafruit ILI9341 TFT library

// Pins: GOOUUU Tech ESP32-S3-CAM Expansion Board
#define TFT_CLK      3              // LCD 240×320 ILI9341 TFT SCK
#define TFT_MISO    46              // SDO     "           TFT MISO
#define TFT_CS      14              // CS      "           TFT CS
#define TFT_MOSI    45              // SDI     "           TFT MOSI
#define TFT_DC      47              // D/C     "           TFT DC
#define TFT_RST     21              // Reset   "           TFT RST
#define TFT_BL      -1              // to 3V3 (always On)  TFT BL

//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

void setup() {
  Serial.begin(115200);          // Initialize Serial communication
  while(!Serial);                // Wait for the Serial Port to open

  Serial.println("ILI9341 GFX Test!");
  tft.begin();

  // Read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("       MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("      Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("      Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("   Self Diagnostic: 0x"); Serial.println(x, HEX);

  Serial.println(F("\nBenchmark                Time (microseconds)"));
  delay(10);
  Serial.print(F("Screen fill              "));
  Serial.println(testFillScreen());
  delay(500);

  Serial.print(F("Text                     "));
  Serial.println(testText());
  delay(3000);

  Serial.print(F("Lines                    "));
  Serial.println(testLines(ILI9341_CYAN));
  delay(500);

  Serial.print(F("Horiz/Vert Lines         "));
  Serial.println(testFastLines(ILI9341_RED, ILI9341_BLUE));
  delay(500);

  Serial.print(F("Rectangles (outline)     "));
  Serial.println(testRects(ILI9341_GREEN));
  delay(500);

  Serial.print(F("Rectangles (filled)      "));
  Serial.println(testFilledRects(ILI9341_YELLOW, ILI9341_MAGENTA));
  delay(500);

  Serial.print(F("Circles (filled)         "));
  Serial.println(testFilledCircles(10, ILI9341_MAGENTA));

  Serial.print(F("Circles (outline)        "));
  Serial.println(testCircles(10, ILI9341_WHITE));
  delay(500);

  Serial.print(F("Triangles (outline)      "));
  Serial.println(testTriangles());
  delay(500);

  Serial.print(F("Triangles (filled)       "));
  Serial.println(testFilledTriangles());
  delay(500);

  Serial.print(F("Rounded rects (outline)  "));
  Serial.println(testRoundRects());
  delay(500);

  Serial.print(F("Rounded rects (filled)   "));
  Serial.println(testFilledRoundRects());
  delay(500);

  Serial.println(F("Done!"));
}


void loop(void) {
  for(uint8_t rotation=0; rotation<4; rotation++) {
    tft.setRotation(rotation);
    testText();
    delay(1000);
  }
}

unsigned long testFillScreen() {
  unsigned long start = micros();
  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  yield();
  tft.fillScreen(ILI9341_RED);
  yield();
  tft.fillScreen(ILI9341_GREEN);
  yield();
  tft.fillScreen(ILI9341_BLUE);
  yield();
  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  yield();
  return micros() - start;
}

unsigned long testText() {
  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
  tft.println("Hello, World!");
  tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
  tft.println(1234.56);
  tft.setTextColor(ILI9341_RED);    tft.setTextSize(3);
  tft.println(0xDEADBEEF, HEX);
  tft.println();
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(5);
  tft.println("Groop");
  tft.setTextSize(2);
  tft.println("I implore thee,");
  tft.setTextSize(1);
  tft.println("my foonting turlingdromes.");
  tft.println("And hooptiously drangle me");
  tft.println("with crinkly bindlewurdles.");
  tft.println("Or I will rend thee");
  tft.println("in the gobberwarts,");
  tft.println("with my blurglecruncheon.");
  tft.println("See if I don't!");
  return micros() - start;
}

unsigned long testLines(uint16_t color) {
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = tft.width(),
                h = tft.height();

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  yield();
  x1    = y1 = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2 < w; x2+=6) tft.drawLine(x1,y1, x2,y2, color);
  x2    = w - 1;
  for(y2=0; y2 < h; y2+=6) tft.drawLine(x1,y1, x2,y2, color);
  t     = micros() - start;

  yield(); // fillScreen doesn't count against timing
  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  yield();

  x1    = w - 1;
  y1    = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2 < w; x2+=6) tft.drawLine(x1,y1, x2,y2, color);
  x2    = 0;
  for(y2=0; y2 < h; y2+=6) tft.drawLine(x1,y1, x2,y2, color);
  t    += micros() - start;
  yield();
  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  yield();

  x1    = 0;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1,y1, x2,y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1,y1, x2,y2, color);
  t    += micros() - start;
  yield();
  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  yield();

  x1    = w - 1;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2 < w; x2+=6) tft.drawLine(x1,y1, x2,y2, color);
  x2    = 0;
  for(y2=0; y2 < h; y2+=6) tft.drawLine(x1,y1, x2,y2, color);
  yield();
  return micros() - start;
}

unsigned long testFastLines(uint16_t color1, uint16_t color2) {
  unsigned long start;
  int           x, y, w = tft.width(), h = tft.height();

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  start = micros();
  for(y=0; y < h; y+=5) tft.drawFastHLine(0,y, w, color1);
  for(x=0; x < w; x+=5) tft.drawFastVLine(x,0, h, color2);
  return micros() - start;
}

unsigned long testRects(uint16_t color) {
  unsigned long start;
  int           n, i, i2,
                cx = tft.width()  / 2,
                cy = tft.height() / 2;

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  n     = min(tft.width(), tft.height());
  start = micros();
  for( i=2; i < n; i+=6) {
    i2  = i / 2;
    tft.drawRect(cx-i2,cy-i2, i,i, color);
  }
  return micros() - start;
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  n = min(tft.width(), tft.height());
  for(i=n; i > 0; i-=6) {
    i2    = i / 2;
    start = micros();
    tft.fillRect(cx-i2,cy-i2, i,i, color1);
    t    += micros() - start;
    // Outlines are not included in timing results
    tft.drawRect(cx-i2,cy-i2, i,i, color2);
    yield();
  }
  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = tft.width(), h = tft.height(), r2 = radius * 2;

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  start = micros();
  for(x=radius; x < w; x+=r2) {
    for(y=radius; y < h; y+=r2) {
      tft.fillCircle(x,y, radius, color);
    }
  }
  return micros() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x, y, r2 = radius * 2,
                w = tft.width()  + radius,
                h = tft.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = micros();
  for(x=0; x < w; x+=r2) {
    for(y=0; y < h; y+=r2) {
      tft.drawCircle(x,y, radius, color);
    }
  }
  return micros() - start;
}

unsigned long testTriangles() {
  unsigned long start;
  int           n, i, cx = tft.width()  / 2 - 1,
                      cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  n     = min(cx, cy);
  start = micros();
  for(i=0; i < n; i+=5) {
    tft.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      tft.color565(i, i, i));
  }
  return micros() - start;
}

unsigned long testFilledTriangles() {
  unsigned long start, t = 0;
  int           i, cx = tft.width()  / 2 - 1,
                   cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  start = micros();
  for(i=min(cx,cy); i > 10; i-=5) {
    start = micros();
    tft.fillTriangle(cx,cy-i, cx-i,cy+i, cx+i,cy+i,
                     tft.color565(0, i*10, i*10));
    t += micros() - start;
    tft.drawTriangle(cx,cy-i, cx-i,cy+i, cx+i,cy+i,
                     tft.color565(i*10, i*10, 0));
    yield();
  }
  return t;
}

unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  w     = min(tft.width(), tft.height());
  start = micros();
  for(i=0; i < w; i+=6) {
    i2 = i / 2;
    tft.drawRoundRect(cx-i2,cy-i2, i,i, i/8, tft.color565(i,0,0));
  }
  return micros() - start;
}

unsigned long testFilledRoundRects() {
  unsigned long start;
  int           i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);        // Clear the screen
  start = micros();
  for(i=min(tft.width(),tft.height()); i > 20; i-=6) {
    i2 = i / 2;
    tft.fillRoundRect(cx-i2,cy-i2, i,i, i/8, tft.color565(0,i,0));
    yield();
  }
  return micros() - start;
}

/*******************************************************************
Sketch uses 369762 bytes (28%) of program storage space.
  Maximum is 1310720 bytes.
Global variables use 22092 bytes (6%) of dynamic memory,
  leaving 305588 bytes for local variables. Maximum is 327680 bytes.
esptool.py v4.8.1
Serial port COM6
Connecting.....
Chip is ESP32-S3 (QFN56) (revision v0.2)
Features: WiFi, BLE, Embedded PSRAM 8MB (AP_3v3)
Crystal is 40MHz
MAC: 10:51:db:86:25:18
Uploading stub...
Running stub...
Stub running...
Changing baud rate to 921600
Changed.
Configuring flash size...
Flash will be erased from 0x00000000 to 0x00004fff...
Flash will be erased from 0x00008000 to 0x00008fff...
Flash will be erased from 0x0000e000 to 0x0000ffff...
Flash will be erased from 0x00010000 to 0x0006afff...
Compressed 20208 bytes to 13057...
Writing at 0x00000000... (100 %)
Wrote 20208 bytes (13057 compressed) at 0x00000000 in 0.5 seconds
  (effective 348.4 kbit/s)...
Hash of data verified.
Compressed 3072 bytes to 146...
Writing at 0x00008000... (100 %)
Wrote 3072 bytes (146 compressed) at 0x00008000 in 0.1 seconds
  (effective 482.1 kbit/s)...
Hash of data verified.
Compressed 8192 bytes to 47...
Writing at 0x0000e000... (100 %)
Wrote 8192 bytes (47 compressed) at 0x0000e000 in 0.1 seconds
  (effective 834.2 kbit/s)...
Hash of data verified.
Compressed 369904 bytes to 202116...
Writing at 0x00010000... (7 %)
Writing at 0x0001ba91... (15 %)
Writing at 0x0002a291... (23 %)
Writing at 0x0002fa00... (30 %)
Writing at 0x000353f7... (38 %)
Writing at 0x0003b0d1... (46 %)
Writing at 0x00040926... (53 %)
Writing at 0x000460aa... (61 %)
Writing at 0x0004bcdc... (69 %)
Writing at 0x00051672... (76 %)
Writing at 0x0005c439... (84 %)
Writing at 0x000622ae... (92 %)
Writing at 0x0006831b... (100 %)
Wrote 369904 bytes (202116 compressed) at 0x00010000 in 3.5 seconds
  (effective 836.7 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
*******************************************************************/

/*******************************************************************
SERIAL MONITOR
==============

01:35:52.072 -> ESP-ROM:esp32s3-20210327
01:35:52.106 -> Build:Mar 27 2021
01:35:52.106 -> rst:0x1 (POWERON),boot:0x28 (SPI_FAST_FLASH_BOOT)
01:35:52.106 -> SPIWP:0xee
01:35:52.106 -> mode:DIO, clock div:1
01:35:52.106 -> load:0x3fce2820,len:0x118c
01:35:52.106 -> load:0x403c8700,len:0x4
01:35:52.106 -> load:0x403c8704,len:0xc20
01:35:52.106 -> load:0x403cb700,len:0x30e0
01:35:52.106 -> entry 0x403c88b8

01:35:52.232 -> ILI9341 GFX Test!
01:35:52.887 -> Display Power Mode: 0x94
01:35:52.887 ->        MADCTL Mode: 0x48
01:35:52.887 ->       Pixel Format: 0x5
01:35:52.887 ->       Image Format: 0x80
01:35:52.887 ->    Self Diagnostic: 0xC0

01:35:52.887 -> Benchmark                Time (microseconds)
01:35:52.929 -> Screen fill              10979903
01:36:04.380 -> Text                     418687
01:36:10.045 -> Lines                    4049264
01:36:35.429 -> Horiz/Vert Lines         886800
01:36:38.991 -> Rectangles (outline)     562889
01:36:42.237 -> Rectangles (filled)      22581229
01:37:08.090 -> Circles (filled)         2367388
01:37:12.676 -> Circles (outline)        1771972
01:37:14.934 -> Triangles (outline)      941727
01:37:18.617 -> Triangles (filled)       7270058
01:37:29.589 -> Rounded rects (outline)  1031853
01:37:33.293 -> Rounded rects (filled)   22628556
01:37:58.638 -> Done!

*******************************************************************/

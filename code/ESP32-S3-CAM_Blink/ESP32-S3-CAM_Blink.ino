/*******************************************************************
 * Filename          : ESP32-S3-CAM_Blink.ino
 * Description       : Make the Blue TX_LED Blink.
 * Development Board : GOOUUU ESP32-S3-CAM (ESP32-S3 Dev Module)

GOOUUU ESP32-S3-CAM
Pinout matches: ESP32-S3-WROOM(CAM), YD-ESP32-S3, ESP32-S3-DevKitC-1

Xtensa® 32-bit           GOOUUU ESP32-S3-CAM  ESP32-S3-WROOM-1 N16R8
dual-core LX7, 240MHz      _______________
                          |  ___   _   __¯|      IO##~  SD_Card
    DVP Camera IO##_      | | | |_| |_|   |      IO##*  PSRAM
                       .——| | |           |——.                  Blue
                3V3   1|•:|——.··. .————/:@|:¤|40 IO43 TX›[U0TXD  LED]  —————————
[RESET    ]      EN   2|•:|  WiFi ß ŒÆ '——|:•|39 IO44 RX‹[U0RXD     ]  LCD 2.8in
[CAM_SIOD ]SDA  IO4_  3|•:|  ˜¨¨˜ °       |:o|38 IO1  VR•[A0  (T_CS)]  —————————
[CAM_SIOC ]SCL  IO5_  4|•:|ESP32-S3-N16R8 |:o|37 IO2  U3•[A1 (T_DIN)]  TIRQ  -1
[CAM_VSYNC]     IO6_  5|•:|          ____ |:o|36 IO42 SDA[   (T_CLK)]  TCS  IO1
[CAM_HREF ]     IO7_  6|•:| ° N16R8 |QRCD||:o|35 IO41 SCL[    (T_DO)]  TDIN IO2
[CAM_XCLK ]    IO15_  7|•:'———————————————':•|34 IO40~ S3[SD_DATA  ø]  TCLK IO42
[CAM_Y9   ]D7  IO16_  8|• ._______________. •|33 IO39~ S2[SD_CLK   ø]  TDO  IO41
[CAM_Y8   ]D6  IO17_  9|• | ::::::::::::: | •|32 IO38~ S1[SD_CMD   ø]  SCK  IO3
[CAM_Y7   ]D5  IO18_ 10|• |  DVP Camera   | •|31 IO37* S4[PSRAM    ø]  MISO IO46
[CAM_Y4   ]D2   IO8_ 11|• ¯¯:::::::::::::¯¯ •|30 IO36*   [PSRAM    ø]  CS   IO14
[A2  (SCK)]     IO3  12|o      GOOUUU       •|29 IO35*   [PSRAM    ø]  MOSI IO45
[   (MISO)]    IO46  13|o   ESP32-S3-CAM    o|28 IO0     [BOOT      ]  DC   IO47
[CAM_Y3   ]D1   IO9_ 14|•   ¬ ¬   TX¤ ¤ [¤] o|27 IO45    [    (MOSI)]  RES  IO21
[CAM_Y5   ]D3  IO10_ 15|•   ¨ ¨......PWR 48 ¤|26 IO48 RGB[WS2812 LED]  BL   3V3
[CAM_Y2   ]D0  IO11_ 16|• RST |CH304G | BOOTo|25 IO47    [      (DC)]
[CAM_Y6   ]D4  IO12_ 17|• [Ø]  '''''''  [Ø] o|24 IO21    [     (RES)]
[CAM_PCLK ]    IO13_ 18|•  _____ O T _____  ø|23 IO20    [A9      D+]  —————————
[A13  (CS)]    IO14  19|o | USB |T T| USB | ø|22 IO19    [A8      D-]  I²C OLED
                5V0  20|• |  C  |G L|  C  | •|21 GND                   —————————
                       '——'ESP32'———'CH343'——'   IO48 RGB NeoPixel   1  *   GND
                                                                     2  *   5V0
ESP32-S3 Pins: 0…18 GPIO, 19…20 D+/D-, 21 GPIO, 22…25 Do Not Exist,  3 IO41 SCL
26…32 QSPI ƒlash, 33…34 Missing, 35…42 GPIO, 43…44 TX/RX, 45…48 GPIO 4 IO42 SDA
“TF SD_Card” on back.   pins_arduino.h ~ ESP32-S3-DevKitC-1
*******************************************************************/

/*******************************************************************
Type-C USB Data cable plugged into Left-side ESP32-S3 USB-OTG port.
                                   ¯¯¯¯¯¯¯¯¯          ¯¯¯¯¯¯¯
Arduino IDE > Tools                                  [CONFIGURATION]
                   Board: "ESP32S3 Dev Module"
         USB CDC On Boot: "Enabled"  **Cable plugged into Left USB**
           CPU Frequency: "240MHz (WiFi)"                 ¯¯¯¯
         USB DFU On Boot: "Disabled"
              Flash Mode: "QIO 80MHz"
              Flash Size: "16MB 128Mb"  -or-
              Flash Size: "8MB 64Mb"   check your board!
USB Firmware MSC On Boot: "Disabled"
        Partition Scheme: "16M Flash (2MB APP/12.5MB FATFS)"  -or-
        Partition Scheme: "8MB with spiffs (3MB APP/1.5MB SPIFFS)"
                   PSRAM: "OPI PSRAM"
             Upload Mode: "UART0/Hardware CDC"
            Upload Speed: "115200"
                USB Mode: "Hardware CDC and JTAG"
*******************************************************************/

// The ESP32-S3-CAM has 3 LEDs instead of 5 like the ESP32-S3-WROOM.
// There is no GPIO2 LED_BUILTIN, or RX_LED.
// The RGB NeoPixel (GPIO48) is both LED_BUILTIN & RGB_BUILTIN.
// So, for this ‘Blink’ sketch, we will Blink the Blue TX_LED.
// The Output and Serial Monitor windows are shown below.

#define TX_LED         43           // Blue LED     (Left)
// Power LED                        // Red  LED     (Middle)
//#define RGB_BUILTIN  48           // RGB NeoPixel (Right)

void setup(void) {
  Serial.begin(115200);             // Initialize Serial Monitor
  while(!Serial);                   // Wait for Serial Port to open

  // The TX_LED is wired “inverted”, so HIGH = Off
  pinMode(TX_LED,      OUTPUT);     // initialize the Blue TX_LED
  digitalWrite(TX_LED, HIGH);       // turn the TX_LED Off
//neopixelWrite(RGB_BUILTIN,0,0,0); // turn the RGB_BUILTIN Off
  delay(500);                       // wait 1/2 second

  Serial.println("\nESP32-S3-CAM  Blink the Blue TX_LED");
}

void loop() {
  Serial.println("Blink!");
  digitalWrite(TX_LED, LOW);        // turn the TX LED On(inverted)
  delay(500);                       // wait 1/2 second
  digitalWrite(TX_LED, HIGH);       // turn the LED Off(inverted)
  delay(500);                       // wait 1/2 second
}

/* —————————————————————————————————————————————————————————————————
NOTE:  Even though we are initializing GPIO43 TX_LED pinMode() as
—————  ‘OUTPUT’; and sending HIGH and LOW values to the LED attached
       to the TX GPIO; the Serial Monitor, which also uses this GPIO
       still functions! Chech out the Serial Monitor to see the
       message “Blink!” every 1/2 second cycle.

       Does this mean we can incorporate the this Blue LED into our
       sketches, without interfearing with the UART output to the
       Serial Monitor?
————————————————————————————————————————————————————————————————— */

/*******************************************************************
Sketch uses 327678 bytes (9%) of program storage space. 
  Maximum is 3342336 bytes.
Global variables use 20696 bytes (6%) of dynamic memory, 
  leaving 306984 bytes for local variables. Maximum is 327680 bytes.
esptool.py v4.8.1
Serial port COM6
Connecting....
Chip is ESP32-S3 (QFN56) (revision v0.2)
Features: WiFi, BLE, Embedded PSRAM 8MB (AP_3v3)
Crystal is 40MHz
MAC: 10:51:db:86:25:18
Uploading stub...
Running stub...
Stub running...
Configuring flash size...
Flash will be erased from 0x00000000 to 0x00004fff...
Flash will be erased from 0x00008000 to 0x00008fff...
Flash will be erased from 0x0000e000 to 0x0000ffff...
Flash will be erased from 0x00010000 to 0x00060fff...
Compressed 20208 bytes to 13058...
Writing at 0x00000000... (100 %)
Wrote 20208 bytes (13058 compressed) at 0x00000000 in 1.4 seconds 
  (effective 112.1 kbit/s)...
Hash of data verified.
Compressed 3072 bytes to 146...
Writing at 0x00008000... (100 %)
Wrote 3072 bytes (146 compressed) at 0x00008000 in 0.1 seconds 
  (effective 375.1 kbit/s)...
Hash of data verified.
Compressed 8192 bytes to 47...
Writing at 0x0000e000... (100 %)
Wrote 8192 bytes (47 compressed) at 0x0000e000 in 0.1 seconds 
  (effective 729.4 kbit/s)...
Hash of data verified.
Compressed 327824 bytes to 177355...
Writing at 0x00010000... (9 %)
Writing at 0x0001c144... (18 %)
Writing at 0x00028c7b... (27 %)
Writing at 0x0002e416... (36 %)
Writing at 0x00033e04... (45 %)
Writing at 0x000395b7... (54 %)
Writing at 0x0003ece9... (63 %)
Writing at 0x00044701... (72 %)
Writing at 0x0004a25a... (81 %)
Writing at 0x00054ee5... (90 %)
Writing at 0x0005ae76... (100 %)
Wrote 327824 bytes (177355 compressed) at 0x00010000 in 15.7 seconds 
  (effective 166.6 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting with RTC WDT...
*******************************************************************/

/*******************************************************************
Serial Monitor:
———————————————
16:16:21.876 -> ESP-ROM:esp32s3-20210327
16:17:12.741 -> 
16:17:12.741 -> ESP32-S3-CAM  Blink the Blue TX_LED
16:17:12.741 -> Blink!
16:17:13.749 -> Blink!
16:17:14.733 -> Blink!
16:17:15.752 -> Blink!
16:17:16.755 -> Blink!
*******************************************************************/

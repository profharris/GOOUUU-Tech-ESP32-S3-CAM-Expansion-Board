/*******************************************************************
 * Filename    : ESP32-S3-CAM_Blink.ino
 * Description : Make the Blue TX_LED Blink.
 *
 *       Board : ESP32S3 Dev Module
 ******************************************************************/
 
/*******************************************************************
ESP32-S3-CAM
(Same pinout as ESP32-S3-WROOM (CAM Module), & ESP32-S3-DevKitC-1)

Xtensa® 32-bit              ESP32-S3-CAM      ESP32-S3-WROOM-1 N16R8
dual-core LX7              _______________
240MHz                    |  ___   _   __¯|
                          | | | | | | |   |      IO##~   SD-Card
    DVP Camera IO##_      | | | |_| |_|   |      IO##*   PSRAM
                       .——| | |           |——.                      TFT
            ——> 3V3   1|•:|————————————/:@|:•|40 IO43 TX›[U0TXD LED]
[RESET    ]      EN   2|•:|  .··. .    '——|:•|39 IO44 RX‹[U0RXD LED]
[CAM_SIOD ]SDA  IO4_  3|•:|  WiFi ß       |:o|38 IO1  SDA[ADC1_CH0 ]
[CAM_SIOC ]SCL  IO5_  4|•:|  ˜¨¨˜ °       |:o|37 IO2  SCL[ADC1_CH1 ]
[CAM_VSYNC]     IO6_  5|•:|ESP32-S3-N16R8 |:o|36 IO42    [     SCLK]<——
[CAM_HREF ]     IO7_  6|•:|               |:o|35 IO41    [     MOSI]<——
[CAM_XCLK ]    IO15_  7|•:|  ŒÆ     F©    |:•|34 IO40~   [SD_DATA •]
[CAM_Y9   ]D7  IO16_  8|•:'———————————————':•|33 IO39~   [SD_CLK  •]
[CAM_Y8   ]D6  IO17_  9|• ._______________. •|32 IO38~   [SD_CMD  •]
[CAM_Y7   ]D5  IO18_ 10|• | ::::::::::::: | •|31 IO37*   [PSRAM   •]
[CAM_Y4   ]D2   IO8_ 11|• |    Camera     | •|30 IO36*   [PSRAM   •]
[  Switch ]     IO3  12|o ¯¯:::::::::::::¯¯ •|29 IO35*   [PSRAM   •]
[  Shutter]    IO46  13|o   ESP32-S3-CAM    o|28 IO0     [BOOT  RST]<——
[CAM_Y3   ]D1   IO9_ 14|•   ¬ ¬   TX¤ ¤ [¤] o|27 IO45    [       DC]<——
[CAM_Y5   ]D3  IO10_ 15|•   ¨ ¨......PWR 48 ¤|26 IO48 RGB[WS2812   ]
[CAM_Y2   ]D0  IO11_ 16|• RST |CH304G | BOOTo|25 IO47    [       CS]<——
[CAM_Y6   ]D4  IO12_ 17|• [Ø]  '''''''  [Ø] o|24 IO21    [      BLK]<——
[CAM_PCLK ]    IO13_ 18|• .......O T....... ø|23 IO20 D- [ADC2_C9  ]   —————————
[ADC2_CH3 ]    IO14  19|o | USB |T T| USB | ø|22 IO19 D+ [ADC2_C8  ]   I²C QWIIC
                5V0  20|• |  C  |G L|  C  | •|21 GND                <  —————————
                       '——'ESP32'———'CH343'——'   IO48 RGB NeoPixel    1  *  GND
                                                                      2  *  3V3
ESP32-S3 Pins: 0…18 GPIO, 19…20 D+/D-, 21 GPIO, 22…25 Do Not Exist,   3 IO1 SDA
26…32 QSPI ƒlash, 33…34 Missing, 35…42 GPIO, 43…44 TX/RX, 45…48 GPIO  4 IO2 SCL
SD-Card on back.        pins_arduino.h ~ ESP32-S3-DevKitC
*******************************************************************/

/*******************************************************************
Type-C USB cable plugged into the right-side TTL/UART port.

Arduino IDE > Tools                                  [CONFIGURATION]
                       Board: "ESP32S3 Dev Module"
             USB CDC On Boot: "Disabled"    *** Sketch locks up if ENABLED ***
               CPU Frequency: "240MHz (WiFi)"
             USB DFU On Boot: "Disabled"
                  Flash Mode: "QIO 80MHz"
                  Flash Size: "16MB 128Mb"
    USB Firmware MSC On Boot: "Disabled"
              Partion Scheme: "16M Flash (2MB APP/12.5MB FATFS)"
                       PSRAM: "OPI PSRAM"
*******************************************************************/

// The ESP32-S3-CAM has 3 LEDs, instead of 5 like the ESP32-S3-WROOM
// There is no GPIO2 LED_BUILTIN, or RX_LED.
// The RGB NeoPixel (GPIO48) is both LED_BUILTIN & RGB_BUILTIN
// So, for this ‘Blink’ sketch, we will Blink the Blue TX_LED

// Power LED                        // Red  LED     (middle)
#define TX_LED         43           // Blue LED     (left)
//#define RGB_BUILTIN  48           // RGB NeoPixel (right)

void setup(void) {
  Serial.begin(9600);               // Serial Monitor
  while(!Serial);                   // wait for Serial Port to open

  // The TX_LED is wired inverted, so HIGH = Off
  pinMode(TX_LED,      OUTPUT);     // initialize the Blue TX_LED
  digitalWrite(TX_LED, HIGH);       // turn the TX_LED Off
//neopixelWrite(RGB_BUILTIN,0,0,0); // turn the RGB_BUILTIN Off
  delay(500);                       // wait 1/2 second

  Serial.println(F("ESP32-S3-CAM  Blink the Blue TX_LED"));
}

void loop() {
  Serial.println(F("Blink!"));
  digitalWrite(TX_LED, LOW);        // turn the TX LED On(inverted)
  delay(500);                       // wait 1/2 second
  digitalWrite(TX_LED, HIGH);       // turn the LED Off(inverted)
  delay(500);                       // wait 1/2 second
}

/*******************************************************************
NOTE:  Even though we are initializing GPIO43 TX_LED pinMode() as 
       ‘OUTPUT’; and sending HIGH and LOW values to the LED attached
       to the TX GPIO; the Serial Monitor, which also uses this GPIO
       still functions! Chech out the Serial Monitor to see the 
       message “Blink!” every 1/2 second cycle.

       Does this mean we can incorporate the this Blue LED into our
       sketches, without interfearing with the UART output to the
       Serial Monitor?
*******************************************************************/


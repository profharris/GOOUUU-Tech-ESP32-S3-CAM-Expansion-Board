/********************************************************************
 * Filename    : ESP32-S3-WROOM_Blink.ino
 * Platform    : ESP32-S3-WROOM (CAM) | FREENOVE ESP32-S3-WROOM (CAM)
 * Description : Make the Blue LED_BUILTIN and other LEDs Blink.

 ESP32-S3-WROOM (CAM) Module     (FREENOVE ESP32-S3-WROOM clone)

                    11-pins wide×20-pins (40-pins)
 Xtensa® 32-bit
 dual-core LX7, 240MHz  • • • • • • • • • • • ESP32-S3-WROOM-1 N16R8   —————————
 16MB Flash, 8MB PSRAM     _______________                             I²C QWIIC
                          |  ___   _   __¯|      IO##~   SD-Card       —————————
    DVP Camera IO##_      | | | |_| |_|   |      IO##*   PSRAM         1  *  GND
                       .——| | |           |——.                         2  *  3V3
                3V3   1|•:|———————————————|:¤|40 IO43 TX›[U0TXD  LED]  3 IO1 SDA
[Reset    ]      EN   2|•:|ESP32S3-WROOM-1|:¤|39 IO44 RX‹[U0RXD  LED]  4 IO2 SCL
[CAM_SIOD ]SDA  IO4_  3|•:| Œ             |:o|38 IO1  SDA[A0        ]
[CAM_SIOC ]SCL  IO5_  4|•:| FCCID: 2AC7Z  |:¤|37 IO2  SCL[A1     LED]  —————————
[CAM_VSYNC]     IO6_  5|•:| WROOM1   ____ |:o|36 IO42    [    (MOSI)]« « SPI LCD
[CAM_HREF ]     IO7_  6|•:|         |QRCD||:o|35 IO41    [    (SCLK)]« Open Pins
[CAM_XCLK ]    IO15_  7|•:| ° N16R8 |____||:•|34 IO40~   [SD_DATA   ]  Right side
[CAM_Y9   ]D7  IO16_  8|•:'———————————————':•|33 IO39~   [SD_CLK    ]  —————————
[CAM_Y8   ]D6  IO17_  9|• ''''''''''''''''' •|32 IO38~   [SD_CMD    ]   -1  MISO
[CAM_Y7   ]D5  IO18_ 10|• ._______________. •|31 IO37*   [OPI PSRAM ]  IO42 SCLK
[CAM_Y4   ]D2   IO8_ 11|• | ::::::::::::: | •|30 IO36*   [OPI PSRAM ]  IO41 MOSI
[A2   JTAG]     IO3  12|o |  DVP Camera   | •|29 IO35*   [OPI PSRAM ]  IO0  RST
[      LOG]    IO46  13|o ¯¯:::::::::::::¯¯ ö|28 IO0     [BOOT (RST)]« IO45 DC
[CAM_Y3   ]D1   IO9_ 14|•  ESP32-S3  WROOM  o|27 IO45    [VSPI  (DC)]« IO47 CS
[CAM_Y5   ]D3  IO10_ 15|• R   ¤ ¤ ¤ ¤ [¤] B ¤|26 IO48 RGB[WS2812¤   ]  IO21 BL*
[CAM_Y2   ]D0  IO11_ 16|• [Ø] O T R 0 4 [Ø] o|25 IO47    [      (CS)]«
[CAM_Y6   ]D4  IO12_ 17|• RST N X X 2 8 IO0 o|24 IO21    [      (BL)]« Open Pins
[CAM_PCLK ]    IO13_ 18|• .......   ....... ø|23 IO20    [A9      D+]  —————————
[A13      ]    IO14  19|o | USB |   | USB | ø|22 IO19    [A8      D-]  IO3  SW
                5V0  20|• |  C  |   |  C  | •|21 GND                   IO46 SH
                       '——'ESP32'———'CH343'——'   IO48 RGB NeoPixel     IO14 A13

Pin configuration (ESP32-S3-DevkitC-1 v1.0 compatible)
ESP32-S3 Pins: 0…18 GPIO, 19/20 D+/D-, 21 GPIO, 22…25 Do Not Exist,
26…32 QSPI ƒlash, 33/34 Missing, 35…42 GPIO, 43/44 TX/RX, 45…48 GPIO
    pins_arduino.h ESP32-S3-DevKitC-1

github: https://github.com/espressif/esp32-camera
  docs: https://github.com/espressif/esp32-camera/tree/main/README.md
issues: https://github.com/espressif/esp32-camera/issues

GPIO Pins availiable when using the Camera and the TF SD_card slot:
    IO1, IO2 (LED) {I²C QWIIC}, IO3 (JTAG_EN), IO46 (LOG), IO14,
    IO42, IO41, IO45 (VDD_SPI voltage), IO47, and IO21 {SPI LCD}.

Aside from the fact that there is one less power-related pin on the
top and bottom, the pin arrangement appears to be essentially the
same as the ESP32-S3-DevKitC-1 v1.0.  It’s nice that it can be used
as a development board compatible with ‘ESP32-S3-DevKitC-1 v1.0’.

ARDUINO: Select Tools > Board > ESP32 Arduino > “ESP32S3 Dev Module”

********************************************************************/
// The ESP32-S3-WROOM (CAM), FREENOVE ESP32-S3-WROOM (CAM) and (Lite)
// all have '5' LEDs, including the RGB LED (RGB_BUILTIN)!
// This sketch will only Blink the LED_BUILTIN, and the TX & RX LEDs.

// Power On LED                     // Green (far left)
#define TX_LED       43             // TX› Amber LED
#define RX_LED       44             // RX‹ Amber LED
#define LED_BUILTIN   2             // Blue      LED
#define RGB_BUILTIN  48             // RGB NeoPixel

void setup() {
  Serial.begin(115200);             // Initialize Serial Monitor
  while(!Serial);                   // Wait for Serial port to open

  pinMode(TX_LED,      OUTPUT);     // Initialize Amber TX_LED
  pinMode(RX_LED,      OUTPUT);     // Initialize Amber RX_LED
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize Blue  LED_BUILTIN

  // The TX_LED & RX_LEDs are wired inverted, so HIGH = Off
  digitalWrite(TX_LED,      HIGH);  // turn the TX_LED Off
  digitalWrite(RX_LED,      HIGH);  // turn the RX_LED Off
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED_BUILTIN Off
  neopixelWrite(RGB_BUILTIN,0,0,0); // turn the RGB_BUILTIN Off
}

void loop() {
  Serial.println("Blink!");
  digitalWrite(TX_LED,      LOW);    // turn the TX LED On(Inverted)
  delay(250);                        // wait 1/4 second
  digitalWrite(RX_LED,      LOW);    // turn the RX LED On(Inverted)
  delay(250);                        // wait 1/4 second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the BUILTIN LED On
  delay(1000);                       // wait for a second

  digitalWrite(TX_LED,      HIGH);   // turn the LED Off(Inverted)
  delay(250);                        // wait 1/4 second
  digitalWrite(RX_LED,      HIGH);   // turn the LED Off(Inverted)
  delay(250);                        // wait 1/4 second
  digitalWrite(LED_BUILTIN, LOW);    // turn the BUILTIN LED Off
  delay(1000);                       // wait for a second
}

/*******************************************************************
NOTES: Even though we are initializing GPIO43 TX and GPIO44 RX with
       pinMode() as ‘OUTPUT’; and sending HIGH and LOW values to
       the LEDs attached to the TX and RX GPIOs; the Serial Monitor,
       which also uses these GPIOs, still functions! Chech out the
       Serial Monitor to see the message “Blink!” every cycle.

       Does this mean we can incorporate the two Amber LEDs into our
       sketches, without interfearing with the UART output to the
       Serial Monitor?
*******************************************************************/

/* I2C_explicit-port_scaner.ino
 * OLED 0.96in 128×64 SSD1306
 * GOOUUU Tech ESP32-S3-CAM Development Board
 * GOOUUU Tech ESP32-S3-CAM Expansion Board
 *             (...Not required, but it helps.)
 *
 * Prof. Michael P. Harris
 * Wiring:
 *
 * GOOUUU ESP32-S3-CAM          SSD1306 0.96in OLED
 * -------------------          -------------------
 * Pin 21 GND                   Pin 1 GND
 * Pin  1 3V3                   Pin 2 VCC
 * Pin 35 GPIO41 (SCL)          Pin 3 SCL
 * Pin 36 GPIO42 (SDA)          Pin 4 SDA
 *
 * GOOUUU ESP32-S3-CAM I²C:     Wire.setPins(I2C_SDA, I2C_SCL);
 *
 * -----------------------------------------------------------------
 * SETTINGS:
 *                    Board: "ESP32S3 Dev Module"
 *
 *          USB CDC On Boot: "Enabled"
 *            CPU Frequency: "240MHz (WiFi)"
 *          USB DFU On Boot: "Enabled (Requires USB-OTG Mode)"
 *               Flash Mode: "QIO 80MHz"
 *               Flash Size: "16MB 128Mb"
 * USB Firmware MSC On Boot: "Enabled (Requires USB-OTG Mode)"
 *                    PSRAM: "QSPI PSRAM"
 *              Upload Mode: "UART0 / Hardware CDC"
 *             Upload Speed: "921600"
 *                 USB Mode: "Hardware CDC and JTAG"
 */

#include<Wire.h>                    // Arduino I²C library

#define I2C_SCL          41         // I²C Clock
#define I2C_SDA          42         // I²C Data

byte busStatus;

void setup() {
  Serial.begin(115200);             // Initialize Serial Monitor
  while(!Serial);                   // Wait for Serial Port to open
  
  Wire.setPins(I2C_SDA, I2C_SCL);   // set non-standard I²C Pins
  
  Serial.println("\nI2C Port Scanner");
  Serial.println("================");

  Wire.begin();                     // SCL = GPIO41, SDA = GPIO42
  for(int i2cAddress = 0x00; i2cAddress < 0x80; i2cAddress++) {
    Wire.beginTransmission(i2cAddress);
    busStatus = Wire.endTransmission();
    if(busStatus == 0x00) {
      Serial.print("I2C Device found at address: 0x");
      Serial.println(i2cAddress, HEX);
    } else {
      Serial.print("I2C Device NOT found at address: 0x");
      Serial.println(i2cAddress, HEX);
    }
  }
}

void loop() {
}

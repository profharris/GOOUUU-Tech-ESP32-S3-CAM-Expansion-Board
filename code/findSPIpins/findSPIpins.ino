// findSPIpins.ino

// Find the default (Hardware) SPI pins for your board.
// Make sure you have the right board selected in:&nbsp; `Tools —» Boards`...

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

void setup() {
  Serial.begin(115200);         // Initialize Serial communication
  while(!Serial);               // Wait for the Serial port to open
  
  Serial.print("\n MOSI: ");
  Serial.println(MOSI);
  Serial.print(" MISO: ");
  Serial.println(MISO);
  Serial.print("  SCK: ");
  Serial.println(SCK);
  Serial.print("SS/CS: ");
  Serial.println(SS);
}

void loop() {
  delay(1000);
  Serial.print("\n MOSI: ");
  Serial.println(MOSI);
  Serial.print(" MISO: ");
  Serial.println(MISO);
  Serial.print("  SCK: ");
  Serial.println(SCK);
  Serial.print("SS/CS: ");
  Serial.println(SS);
}


/* -----------------------------------------------------------------
OUTPUT:
-------
Sketch uses 300598 bytes (14%) of program storage space. 
  Maximum is 2097152 bytes.
Global variables use 20004 bytes (6%) of dynamic memory, 
  leaving 307676 bytes for local variables. Maximum is 327680 bytes.
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
Configuring flash size...
Flash will be erased from 0x00000000 to 0x00004fff...
Flash will be erased from 0x00008000 to 0x00008fff...
Flash will be erased from 0x0000e000 to 0x0000ffff...
Flash will be erased from 0x00010000 to 0x00059fff...
Compressed 20208 bytes to 13058...
Writing at 0x00000000... (100 %)
Wrote 20208 bytes (13058 compressed) at 0x00000000 in 1.4 seconds 
  (effective 112.1 kbit/s)...
Hash of data verified.
Compressed 3072 bytes to 143...
Writing at 0x00008000... (100 %)
Wrote 3072 bytes (143 compressed) at 0x00008000 in 0.1 seconds 
  (effective 480.2 kbit/s)...
Hash of data verified.
Compressed 8192 bytes to 47...
Writing at 0x0000e000... (100 %)
Wrote 8192 bytes (47 compressed) at 0x0000e000 in 0.1 seconds 
  (effective 788.1 kbit/s)...
Hash of data verified.
Compressed 300736 bytes to 161441...
Writing at 0x00010000... (10 %)
Writing at 0x0001bc84... (20 %)
Writing at 0x00027e81... (30 %)
Writing at 0x0002d63a... (40 %)
Writing at 0x0003354a... (50 %)
Writing at 0x00038aa3... (60 %)
Writing at 0x0003e1d0... (70 %)
Writing at 0x00043b36... (80 %)
Writing at 0x0004a4f8... (90 %)
Writing at 0x000543fa... (100 %)
Wrote 300736 bytes (161441 compressed) at 0x00010000 in 14.4 seconds 
  (effective 167.3 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
--------------------------------------------------------------------

Serial Monitor:
---------------
15:38:01.331 -> ESP-ROM:esp32s3-20210327
15:38:01.331 -> Build:Mar 27 2021
15:38:01.331 -> rst:0x1 (POWERON),boot:0x8 (SPI_FAST_FLASH_BOOT)
15:38:01.334 -> SPIWP:0xee
15:38:01.334 -> mode:DIO, clock div:1
15:38:01.334 -> load:0x3fce2820,len:0x118c
15:38:01.334 -> load:0x403c8700,len:0x4
15:38:01.334 -> load:0x403c8704,len:0xc20
15:38:01.334 -> load:0x403cb700,len:0x30e0
15:38:01.334 -> entry 0x403c88b8
--------------------------------------------------------------------

16:10:33.645 ->  MOSI: 11
16:10:33.645 ->  MISO: 13
16:10:33.645 ->   SCK: 12
16:10:33.645 -> SS/CS: 10

16:10:34.666 ->  MOSI: 11
16:10:34.666 ->  MISO: 13
16:10:34.666 ->   SCK: 12
16:10:34.666 -> SS/CS: 10
...

----------------------------------------------------------------- */

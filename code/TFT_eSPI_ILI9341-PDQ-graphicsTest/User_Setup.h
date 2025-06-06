// User_Setup.h

//                            USER DEFINED SETTINGS
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

/* TFT_eSPI_Float_Test_320x240.ino
 *
 * Tests the updated floating point plot function.
 * The datum is set to the center of the 320x240 screen.
 * so numbers are printed the middle.
 *
 * The last test shows the datum point as a red dot.
 *
 * Normally strings are printed relative to the Top Left corner but
 * this can be changed with the setTextDatum() function.
 * The library has #defines for:
 *
 * TL_DATUM  0 // Top Left
 * TC_DATUM  1 // Top Centre
 * TR_DATUM  2 // Top Right
 * ML_DATUM  3 // Middle Left
 * MC_DATUM  4 // Middle Centre
 * MR_DATUM  5 // Middle Right
 * BL_DATUM  6 // Bottom Left
 * BC_DATUM  7 // Bottom Centre
 * BR_DATUM  8 // Bottom Right
 *
 *  This sketch needs Fonts 2 and 6.
 *
 * Make sure all the display driver and pin connections are correct
 * by editing the User_Setup.h file in the TFT_eSPI library folder.
 *
 * #################################################################
 * ## DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ##
 * #################################################################
 */

#include <TFT_eSPI.h>               // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();          // Invoke custom library

unsigned long drawTime = 0;

void setup(void) {
  Serial.begin(115200);             // Initialize Serial Monitor
  while(!Serial);                   // Wait for Serial Port to open

  tft.init();
  tft.setRotation(1);               // Landscape
}

void loop() {
  char tmp[12];

  tft.fillScreen(TFT_BLACK);        // Clear the screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  // Datum is middle centre
  tft.setTextDatum(MC_DATUM);

  // Test floating point drawing function:
  // drawFloat(value, precision, x, y, font);

  float test = 67.125;
  tft.drawFloat(test, 4, 160,120, 6);
  tft.drawString(dtostrf(test,4,4,tmp), 100,200, 6);
  delay(1000);
  tft.fillScreen(TFT_BLACK);        // Clear the screen

  test = -0.555555;
  tft.drawFloat(test, 3, 160,120, 6);
  tft.drawString(dtostrf(test,2,2,tmp), 100,200, 6);
  delay(1000);
  tft.fillScreen(TFT_BLACK);        // Clear the screen

  test = 0.123;
  tft.drawFloat(test, 4, 160,120, 6);
  tft.drawString(dtostrf(test,4,4,tmp), 100,200, 6);
  delay(1000);
  tft.fillScreen(TFT_BLACK);        // Clear the screen

  // This does not work at the moment....
  test = 9999999;
  tft.drawFloat(test, 0, 160,120, 6);
  tft.drawString(dtostrf(test,4,4,tmp), 100,200, 6);
  delay(1000);

  // Plot the datum for the last number
  tft.fillCircle(160,120, 5, TFT_RED);
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_BLACK);        // Clear the screen
  tft.drawString("X", 160,120, 2);
  delay(4000);
}

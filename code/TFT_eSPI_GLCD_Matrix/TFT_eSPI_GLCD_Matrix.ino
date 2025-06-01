// TFT_eSPI_GLCD_Matrix.ino
// LCD 240×320 ILI9341

// A TFT_eSPI fun MATRIX-like scrolling screen demo. The screen will
// flicker initially until fully drawn then will scroll smoothly.
// Needs GLCD font.

/* Make sure all the display driver and pin connections are correct
 * by editing the User_Setup.h file in the TFT_eSPI library folder.
 *
 * #################################################################
 * ## DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ##
 * #################################################################
 */

#include <TFT_eSPI.h>       // Hardware-specific TFT_eSPI library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

#define TEXT_HEIGHT    8    // Text Height to be printed & scrolled

#define BOT_FIXED_AREA 0    // Number of lines in Bottom Fixed Area
                            // (lines counted from bottom of screen)
#define TOP_FIXED_AREA 0    // Number of lines in Top Fixed Area
                            // (lines counted from top of screen)

byte     pos[42];
uint16_t yStart = TOP_FIXED_AREA;
uint16_t yArea  = 320 - TOP_FIXED_AREA - BOT_FIXED_AREA;
uint16_t yDraw  = 320 - BOT_FIXED_AREA - TEXT_HEIGHT;
uint16_t xPos   = 0;

void setup() {
  Serial.begin(115200);             // Initialize Serial Monitor
  while(!Serial);                   // Wait for Serial Port to open
  randomSeed(analogRead(A0));       // Seed random number generator

  tft.init();
  tft.setRotation(0);               // Portrait orientation
  tft.fillScreen(ILI9341_BLACK);    // Clear the screen
  setupScrollArea(TOP_FIXED_AREA, BOT_FIXED_AREA);
}

void loop(void) {
  // First fill the screen with random streaks of characters...
  for(int j=0; j < 600; j += TEXT_HEIGHT) {
    for(int i=0; i < 40; i++) {
      // Rapid fade initial brightness values  
      if(pos[i] > 20) pos[i] -= 3; 
      if(pos[i] >  0) pos[i] -= 1; // Slow fade later
      if((random(20) == 1) && (j<400)) pos[i] = 63; 
      // ~1 in 20 probability of a new character
      tft.setTextColor(pos[i] << 5, ILI9341_BLACK); 
      // Set the Green character brightness
      if(pos[i] == 63)  // Draw White character
        tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
      xPos += tft.drawChar(random(32, 128), xPos, yDraw, 1); 
      // Draw the character
    }
    // Scroll, 14ms per pixel line
    yDraw = scroll_slow(TEXT_HEIGHT, 14); 
    xPos=0;
  }

  //tft.setRotation(2);
  //tft.setTextColor(63 << 5, ILI9341_BLACK);
  //tft.drawCentreString("MATRIX",120,60,4);
  //tft.setRotation(0);

  // Now scroll smoothly forever
  while(1) {
    yield(); yDraw = scroll_slow(320, 5); 
    // Scroll 320 lines, 5ms per line
  }
}

int scroll_slow(int lines, int wait) {
  int yTemp = yStart;
  for(int i=0; i < lines; i++) {
    yStart++;
    if(yStart == 320 - BOT_FIXED_AREA) yStart = TOP_FIXED_AREA;
    scrollAddress(yStart);
    delay(wait);
  }
  return  yTemp;
}

void scrollAddress(uint16_t VSP) {
  // Vertical Scrolling Start Address
  tft.writecommand(ILI9341_VSCRSADD); 
  tft.writedata(VSP >> 8);
  tft.writedata(VSP);
}

void setupScrollArea(uint16_t TFA, uint16_t BFA) {
  // Vertical Scroll definition   
  tft.writecommand(ILI9341_VSCRDEF); 
  tft.writedata(TFA >> 8);
  tft.writedata(TFA);
  tft.writedata((320 - TFA - BFA) >> 8);
  tft.writedata(320 - TFA - BFA);
  tft.writedata(BFA >> 8);
  tft.writedata(BFA);
}

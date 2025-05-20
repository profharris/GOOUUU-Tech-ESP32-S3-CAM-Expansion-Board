/*******************************************************************
 * Filename    : ESP32-S3-WROOM_Blink.ino
 * Description : Make the Blue LED_BUILTIN and other LEDs Blink.
 ******************************************************************/

// ESP32-S3-WROOM CAM has 5 LEDs
// Power LED                        // Green (far left)
#define TX_LED       43             // TX› Amber LED
#define RX_LED       44             // RX‹ Amber LED
#define LED_BUILTIN   2             // Blue      LED
#define RGB_BUILTIN  48             // RGB NeoPixel

void setup() {
  Serial.begin(9600);               // Serial Monitor
  delay(1000);                      // Timing delay
  pinMode(TX_LED,      OUTPUT);     // initialize Amber TX_LED
  pinMode(RX_LED,      OUTPUT);     // initialize Amber RX_LED
  pinMode(LED_BUILTIN, OUTPUT);     // initialize Blue LED_BUILTIN

  // The TX_LED & RX_LEDs are wired inverted, so HIGH = Off
  digitalWrite(TX_LED,      HIGH);  // turn the TX_LED Off
  digitalWrite(RX_LED,      HIGH);  // turn the RX_LED Off
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED_BUILTIN Off
  neopixelWrite(RGB_BUILTIN,0,0,0); // turn the RGB_BUILTIN Off
}

void loop() {
  Serial.println("Blink!");
  digitalWrite(TX_LED,      LOW);    // turn the TX LED On(inverted)
  delay(250);                        // wait 1/4 second
  digitalWrite(RX_LED,      LOW);    // turn the RX LED On(inverted)
  delay(250);                        // wait 1/4 second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED On
  delay(1000);                       // wait for a second

  digitalWrite(TX_LED,      HIGH);   // turn the LED Off(inverted)
  delay(250);                        // wait 1/4 second
  digitalWrite(RX_LED,      HIGH);   // turn the LED Off(inverted)
  delay(250);                        // wait 1/4 second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED Off
  delay(1000);                       // wait for a second
}

/*******************************************************************
NOTE:  Even though we are initializing GPIO43 TX and GPIO44 RX with
       pinMode() as ‘OUTPUT’; and sending HIGH and LOW values to
       the LEDs attached to the TX and RX GPIOs; the Serial Monitor,
       which also uses these GPIOs, still functions! Chech out the
       Serial Monitor to see the message “Blink!” every cycle.

       Does this mean we can incorporate the two Amber LEDs into our
       sketches, without interfearing with the UART output to the
       Serial Monitor?
*******************************************************************/

# GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board

***WORK IN PROGRESS*** &nbsp; &nbsp; Prof. Michael P. Harris &nbsp; &nbsp; *05/11/2025*
<pre><code>
.____________________________________________________________________________________.
| Ø   .………. ¬R4       S1·2·3·4      ¬R6   .-----------.    U2 P1·2·3·4             Ø |
|     ¦W Ø¦        GND • • • •           —ô 5V0 sensor¦    Ø¨¨¦•¦ô¦o¦o¦¨¨Ø    I²C    |
| 5V0 ¦5  ¦ o      5V0 ô ô ô ô  o     G2 —oDATA DHT11 ¦    ¦   G V S S   ¦ Interface |
|     ¦0  ¦ o G5   SIG o o o o  o G4     —× n/c temp  ¦    ¦   N C C D   ¦ ————————— |
| GND ¦5  ¦ P7         G G G G  P8       —• GND humi  ¦    ¦   D C L A   ¦ GND — GND |
|     ¯¨¨¨¯            1              U3  '-----------'    ¦             ¦ VCC — 5V0 |
|   R3 POT               ._______________.                 ¦ 0.96″ OLED  ¦ SCL — G9  |
|                        ¦ .….…. .…. .……¯¦    G##~ SD_Card ¦   64×128    ¦ SDA — G8  |
|     DVP Camera ´_G##   ¦ ¦ ¦ ¦_¦ ¦_¦   ¦    G##÷ PSRAM   Ø……¨¨¨¨¨¨¨¨………Ø           |
|                     .——¦ ¦ ¦           ¦——.                                        |
|TXD o ö 3V3      3V3 |ö:¦——.··. .————/:•¦:o| G43  TX›        .____SPI LCD__ESP32-S3_|
|RXD o o EN       RST |o:¦  WiFi ß    '——¦:o| G44  RX‹        ¦_1. T_IRQ       ×     |
| G1 o © G4     ´_G4  |©:¦  ˜¨¨˜ °       ¦:o| G1       T_CS   ¦_2. T_DO        G41   |
| G2 o © G5     ´_G5  |©:¦ ESP32S3-N16R8 ¦:o| G2       T_DIN  ¦_3. T_DIN       G2    |
|G42 o © G6     ´_G6  |©:¦         .………….¦:o| G42      T_CLK  ¦_4. T_CS        G1    |
|G41 o © G7     ´_G7  |©:¦ ŒÆ F©   ¦QRCD¦¦:o| G41      T_DO   ¦_5. T_CLK       G42   |
|G40 õ © G15    ´_G15 |©:¦ ° N16R8 '…………'¦:õ| G40~ SD_DATA    ¦_6. SDO/MISO   G46/GND|
|G39 õ © G16    ´_G16 |©:'———————————————':õ| G39~ SD_CLK     ¦_7. LED/BL      3V3   |
|G38 õ © G17    ´_G17 |© .………………………………………. õ| G38~ SD_CMD     ¦_8. SCK        G3/G0  |
|G37 ð © G18    ´_G18 |© ¦ ::::::::::::: ¦ ð| G37÷ PSRAM      ¦_9. SDI/MOSI    G45   |
|G36 ð © G8     ´_G8  |© ¦    Camera     ¦ ð| G36÷ PSRAM      ¦10. DC/RS       G47   |
|G35 ð o G3  SCK  G3  |o ¯¯:::::::::::::¯¯ ð| G35÷ PSRAM      ¦11. RESET       G21   |
| G0 o o G46 MISO G46 |o      GOOUUU       o| G0   BOOT ?SCK  ¦12. CS          G14   |
|G45 o © G9     ´_G9  |©   ESP32-S3-CAM    o| G45       MOSI  ¦13. GND         GND   |
|G48 ¤ © G10    ´_G10 |©   ¬ ¬     ¤ ¤ ‹¤› ¤| G48  RGB        ¦14. VCC         5V0   |
|G47 o © G11    ´_G11 |©   ¨ ¨   PWR TX 48 o| G47         DC  '——————————————————————|
|G21 o © G12    ´_G12 |©      ......       o| G21        RST                         |
|G20 o © G13    ´_G13 |© RST ¦CH304G¦ BOOT ø| G20  D-           GOOUUU               |
|G19 o o G14 CS   G14 |o ‹•›  ''''''   ‹•› ø| G19  D+      (ESP32-S3-CAM) V1.2       |
|GND • ô 5V0      5V0 |ô .......O T....... •| GND        2.8″ SPI TFT LCD 240×320    |
|                     |  ¦ USB ¦T T¦ USB ¦  |                                        |
|G46: Input Only      |  ¦  C  ¦G L¦  C  ¦  |                   M     M T   T   T    |
|         ¬   ¬       '——'ESP32'———'CH343'——'         V G   R   O S L I C T D T I    |
|         R5 R7      R1¬ R2¬                          C N C S D S C E S L C I D R    |
|          ¤   ¤      ‹•›   ‹•›  ¦USB-C¦   ¤          C D S T C I K D O K S N O Q    |
| Ø       D2  D3      RST   KEY  '—————'  D1         ¦ô¦•¦o¦o¦o¦o¦o¦ö¦•¦o¦o¦o¦o¦×¦ Ø |
'————————————————————————————————————————————————————————————————————————————————————'
 Pinout:   G   G       E     G G          5 G G G G G G 3 G G G G G ×
           2   3       N     0 1          V N 1 2 4 4 3 V 4 4 1 2 4
      0 D 4 1 7 5   3 6 2     1
</code></pre>

## TWO sets of header-pin sockets (Yellow and Black)
<pre><code>
> QUICK NOTE: This GOOUUU Tech ESP32-S3-CAM Expansion Board has TWO
> ——————————— sets of header-pin sockets (Yellow and Black) to plug
> in your ESP32-S3-WROOM-1 Development boards.
</code></pre>

## 40-Pin “Yellow” header sockets (primary)
The `40-Pin “Yellow”` header sockets, are designed for the **GOOUUU “ESP32-S3-CAM”** board.<br/>
The **“ESP32-S3-WROOM” (CAM Module)**, a clone of the **“FREEVOVE ESP32-S3-WROOM”**;&nbsp; both<br/> 
also work perfectly in the “Yellow” headers as all three of these *DVP camera ready* Dev boards<br/> 
have the same pinouts and same SoC main chip the **“ESP32-S3-WROOM-1”**.

A fourth development board using the **“ESP32-S3-WROOM-1”** SoC,&nbsp; the **“YD-ESP32-S3”** also called<br/> 
the **“ESP32-S3-WROOM-1 Dev”**, --is a 44-pin board, but the top and bottom rows of pins are just an extra<br/> 
3V3 pin and three extra ground pins.&nbsp; -This board also works in the “Yellow” header pin sockets...<br/> 
just let the extra row of top and bottom pins hang over/extend past the headers alowing a 44-pin board to<br/> 
plug into a set of 40-pin sockets.&nbsp; This development board does NOT have a DVP camera interface like<br/> 
our first three boards.

All 4 of these “ESP32-S3-WROOM-1” Dev boards are pinout
backward compatible, -not counting the extra top/bottom
pins, with the original 44-pin “ESP-S3-DevKitC-1”.
    NOTE: DevKitC-1, NOT DevKitM-1 (NOT pin compatible)

Unfortunately, this original “ESP-S3-DevKitC-1” will not
plug into the “Yellow” headers as this original board is
narrower (by 1 pin spacing) than the other four boards.
Otherwise it could plug in just like the “YD-ESP32-S3”.

NOTE: To identify one of these five ESP32-S3-DevKitC-1
pin compatible boards... look at the board with the two
USB ports facing down. The Left-side pins will end with
GPIO13, GPIO14 then 5V0 (and possibly an extra GND). The
top Right-side pins will (possibly start with a GND pin)
then begin with TXD, RXD, GPIO1, then GPIO2.

The 44-pin “YD-ESP32-S3” and “ESP32-S3-DevKitC-1” have 1
extra pin at the top and bottom of each header, an extra
3V3 pin in the upper-Left, and an extra GND pin on the
other 3 corners.
————————————————————————————————————————————————————————

## 42-Pin “Black” header sockets

The 42-Pin “Black” header sockets are for an ALT version
of the “ESP-S3-DevKitC-1”. This ALT version has 42-pins
instead of the original 44-pins and is 1 pin space wider
like the four Dev boards mentioned above.

Even though this 42-pin “ESP-S3-DevKitC-1_ALT-version”
uses the same “ESP32-S3-WROOM-1” SoC, pinout is similar
but NOT the same as the other 40 & 44-pin Dev boards...
“ESP32-S3-GOOUUU-CAM”, “ESP32-S3-WROOM” (CAM Module),
“FREEVOVE ESP32-S3-WROOM”, “YD-ESP32-S3” or the original
44-pin “ESP-S3-DevKitC-1”.

A quick way to identify this Dev board, besides 42-pins
instead of 40 or 44-pins, is to look at the board with
the two USB ports facing down. The upper-Right pins will
start with (extra) GND, GPIO1, GPIO2, TX0, RX0... and
the lower-Left will end with GPIO11, GPIO12, 3V3. --AND
most importantly, the lower-Right pin is ‘5VIN’.


> [!WARNING]
> I want to pointout this _lower-Right_ ‘5VIN’ pin specifically because
> all the other ESP32-S3 Dev boards mentioned,<br>
> have a `GND` (power ground) pin in the lower-Right.&nbsp; Plugging
> in a `5V` pin into a `GND` header socket,<br>
> or vice-versa, is a quick way to short out and burn-up your Dev board!

# Very clever 2-way “Yellow” and “Black” header sockets

The design engineers for the “GOOUUU Tech ESP32-S3-CAM Expansion
Board” have done something very clever! They have cross-wired, where
needed, the pins in the `40-pin “Yellow”` header to the `42-pin “Black”`
header to match the pinout functions.

**For example:** the first four upper-Right pins of the `40-pin “Yellow”`
header are: `1. TXD`, `2. RXD`, `3. GPIO1`, `4. GPIO2`.  The first five 
pins of the `42-pin “Black”` header are `1. GND`, `2. GPIO1`, `3. GPIO2`, 
`4. TX0`, and `5. RX0`. Copper traces on the Expansion Board, connect 
“Yellow” pin-1 TXD to “Black” pin-4 TX0, and “Yellow” pin-2 RXD to “Black”
pin-5 RX0. Also GPIO1 is cross connected to GPIO1, GPIO2 is cross
connected to GPIO2 and so on. Since all the “ESP32-S3-WROOM-1” SoC
designs have the same pins... this allows for a single `40-pin` double
row breakout header along the left side of the expansion board. The
pinout of this breakout header, mirror-image matches the `40-pin`
`“Yellow” headers`, and all of the pins are well labled.

# 40-pin “Yellow” & 42-pin “Black” header sockets diagram

Following is my diagram, illustrating the 2-way “ESP32-S3-WROOM-1”
Development Board `40-pin “Yellow”` & `42-pin “Black”` header sockets.

 1. Pins marked © and ´_, are pins reserved for the _DVP _Camera_.
    (Includes all of the GPIO Pins on the Left-side header, except:
     GPIO3, GPIO46, & GPIO14).
 2. Pins marked õ and ~, are pins reserved for the TF SD_Card slot.
    (GPIO38, GPIO39, & GPIO40). The TF SD_Card slot is on the back.
 3. Pins marked ð and ÷, are pins reserved for PSRAM and QIO Flash.
    (GPIO36, GPIO37, & GPIO38). Best not to use these pins.

 4. Pins marked ô are 5V0   (5.0 volts)
 5. Pins marked ö are 3V3   (3.3 volts)
 6. Pins marked • are GND
 7. Pins marked ø are USB_D+ and USB_D—

 8. Pins marked » or « are pins with position mismatches between the
    Yellow P1 & P2 header-pin sockets and the Black P3 & P3 sockets.

<pre><code>
       ¦GOOUUU ESP32-S3-CAM¦ or: “ESP32-S3-WROOM” (CAM Module)
       ¦  `40-pin headers  ¦     “FREEVOVE ESP32-S3-WROOM”
       V   Yellow P1 & P2  V     “YD-ESP32-S3”/ESP32-S3-WROOM-1 Dev

        ¦ESP32-S3-DevKitC-1 ¦
        ¦`42-pin ALT VERSION¦
        V   Black P3 & P4   V

       .—P1 (Yellow)       .—P2 (Yellow 40-pin header)
       ¦.—P3 (Black)       ¦.—P4 (Black 42-pin header)
       ¦¦      ¦¦
       ×• GND  ×• GND  NOTE¹: The DVP Camera
  3V3  öö 3V3 same    »TXD oo  G1«        interface uses
   EN  oo  EN same    »RXD oo  G2«        all the Yellow
 ´_G4  ©©  G4 same    »G1  oo TX0«        GPIO Left-side
 ´_G5  ©©  G5 same    »G2  oo RX0«        _pins except:
 ´_G6  ©©  G6 --same-- G42 oo G42         GPIO3, GPIO46,
 ´_G7  ©©  G7 --same-- G41 oo G41         and GPIO14.
 ´_G15 ©© G15 --same-- G40 õõ G40~  SD_Card GPIO40
 ´_G16 ©© G16 --same-- G39 õõ G39~    "     GPIO39
 ´_G17 ©© G17 --same-- G38 õõ G38~    "     GPIO38
 ´_G18 ©© G18 --same-- G37 ðð G37÷  PSRAM   GPIO37
 ´_G8  ©©  G8 --same-- G36 ðð G36÷    "     GPIO36
  »G3  oø G19« D+ same G35 ðð G35÷    "     GPIO35
  »G46 oø G20« D— same G0  oo  G0
»´_G9  ©o  G3«    same G45 oo G45  NOTE²: Pin GPIO46 is
»´_G10 ©o G46«    same G48 ¤¤ G48         INPUT only.
»´_G11 ©©  G9«    same G47 oo G47         No pullups.
»´_G12 ©© G10«    same G21 oo G21
»´_G12 ©© G10«    same G21 oo G21
»´_G13 ©© G11«     D— »G20 øo G14«
  »G14 o© G12«     D+ »G19 ø© ´_G13«
  »5V0 ôö 3V3«        »GND •ô 5VIN« («—— Be careful!)
       ¦¦      ¦¦
       ¦'—Black¦'—Black
       '—Yellow'—Yellow
</code></pre>

# MISC Pin connections/configurations:

GOOUUU Tech ESP32-S3-CAM Expansion Board
    MISC Pin connections/configurations:

 +    DHT11 DATA: GPIO2
 +   R3 W505 Pot:
 +     Jumper P7: GPIO5
 +     Jumper P8: GPIO4
 +     Header S1: GPIO1
 +     Header S2:
 +     Header S3:
 +     Header S4:
 +       I²C SDA: GPIO8         {0.96″ OLED}  NOTE: The I²C pins
 +       I²C SCL: GPIO9         {  64×128  }  are used by the camera
 +        LED D1: GPIO1
 +        LED D2: GPIO2
 +        LED D3: GPIO3
 +  ‹RST] Button: EN/RESET
 +  ‹KEY] Button: GPIO0/BOOT

# 14-Pin SPI 2.8″ 240×320 TFT LCD header:
<pre><code>
GOOUUU Tech ESP32-S3-CAM Expansion Board
    ´14-Pin SPI 2.8″ 240×320 TFT LCD header:

    ILI9341 2.8″    GOOUUU Tech
    TFT Display     Expansion
    with Touch:     Board:         Description:

 1. T-IRQ           × N/C         Touch Interrupt,  Active LOW
 2. T-DO  (MISO)    GPIO41        Touch Data Out   (SPI MISO)
 3. T-DIN (MOSI)    GPIO2         Touch Data In    (SPI MOSI)
 4. T-CSGPIO1         Touch Chip Select, Active LOW
 5. T-CLK (SCK)     GPIO42        Touch Clock      (SPI SCK)
 6. SDO   (MISO)    GPIO46/GND    GND-Not Used     (SPI MISO)
 7. LED 3V3           BackLight Enable, Active HIGH
 8. SCK GPIO3/GPIO0   Display Clock    (SPI SCK)
 9. SDI   (MOSI)    GPIO45        Display Data In  (SPI MOSI)
10. DC  GPIO47        Display Data/Command, HIGH = Data
11. RESET           GPIO21        Display Reset Input, Active LOW
12. CS  GPIO14        Display Chip Select, Active LOW
13. GND GND           Power System Ground
14. VCC 5V0           Power 5.0V
</code></pre>

# TFT LCD 2.8″ 240×320 DISPLAY WITH TOUCHSCREEN

KEY FEATURES OF TFT LCD 2.8″ 240×320 DISPLAY WITH TOUCHSCREEN:

    + 2.8″ TFT LCD with 240×320 resolution
    + 65K colors with ILI9341 controller
    + Resistive Touch Screen with XPT2046 controller
    + SPI ´4-wire LCD interface (SCK, MOSI, DC, CS)
    + SPI ´4-wire SD_Card interface (SCK, MOSI, MISO, CS)
    + 3.V6 to 5.5V module operation
    + 3.3V logic compatible only

These full color displays are large enough for many applications
even when using Touch. The supplied stylus is helpful when using
smaller touch targets.

The modules have an SD_Card socket. This socket has separate
connections to the opposite end of the board. Not needed with the
“ESP32-S3-CAM”, as it already has a TF SD_Card on the backside.

Internally the display operates at 3.3V, so if using with a 5V0
microcontroller, be sure to include logic level shifters on the
data lines to prevent possible damage.


## 2.8″ TFT Display Technical Specifications:

Module Power:
—————————————

SEE IMAGE:  TFT LCD 2.8″ 240×320 RGB ILI9341 with Touchscreen
——» J1 Jumper Location

The module power comes in on the VCC pin. The module includes an
on-board 3.3V regulator, so the module should normally be operated
with 3.6V to 5.5V power on this pin to feed the regulator. Current
draw is typically 55mA-60mA.

If you would prefer to operate the module directly from a 3.3V power
source, there are two solder pads labeled ‘J1’. By solder shorting
these two pads together, the regulator is bypassed and the module
can be powered directly from 3.3V.

In general, it is best to operate the display off of 5V0 to ensure
enough power is available.  Be careful of trying to operate the
display from the built-in 3.3V available on Arduino and similar
microcontrollers since these power sources often have limited
current capability and may overheat.

SPI Interface:
——————————————

This display incorporates a SPI interface which provides for fast
display updates. It is a 4-wire interface so it includes the CS
(Chip Select) pin.

The Touch Screen also uses the SPI interface and CAN hook up to the
same pins as the display, but uses a separate CS to avoid conflict.

For best performance the hardware SPI interface should be used if
possible to get the fastest screen updates.
```
        Display Controller:	ILITEK ILI9341
          Touch Controller:	XPT	XPT2046

        Display	Technology:	TFT LCD
    Resolution:	240×320 pixels
         Color:	RGB 65K color (16-bit 5:6:5)
 Viewing Angle:	60°
    Interfaces:	SPI (Display and Touch)
         Operating Ratings:	DC Power Input	3.6V – 5.5V
         Operating Current:	55mA-60mA (typical)

    Dimensions:
         Module Size (PCB):	86×50mm     (3.39″×1.97″)
          Display diagonal:	71.12mm     (2.8″)
 Display (W×H):	57.6×43.2mm (2.27×1.7″)
```
## LCD 1x14 Header Specifications:
```
LCD 1x14 Header Specifications:
———————————————————————————————

 1. T_IRQ –Touch Interrupt.  Active LOW. If using, connect to an
           Interrupt capable Pin on your MCU.
 2. T_DO  –Touch Read Data.  Connect to SPI MISO on your MCU.
 3. T_DIN –Touch Write Data. Connect to SPI MOSI on your MCU.
 4. T_CS  –Touch Chip Select MUST be a separate CS from LCD CS.
 5. T_CLK –Touch SPI CLock.  Connect to SPI SCK  on your MCU.
 6. SDO/MISO –LCD Read Data. Connect to SPI MISO on your MCU.
 7. LED   –BackLight Control HIGH = BackLight On. Connect to
           3V3 if always ON, Or can be logic controlled.
 8. SCK   –LCD SPI Clock.    Connect to SPI SCK  on your MCU.
 9. SDI/MOSI –LCD Write Data Connect to SPI MOSI on your MCU.
10. DC    –Data or Command.  HIGH = Data, LOW = Command.
11. RESET –Reset Active LOW. Pull to 3V3 if not using.
12. CS    –LCD Chip Select.  This is SPI Chip Select for your LCD.
13. GND   –Connect to Ground This Ground needs to be in common
           with your MCU.
14. VCC   –Connect to 3.6V to 5.5V. Connect to your MCU 5V0, unless
you have made the 3V3 option by soldering the J1 pads.
```

## Display Orientation & Touch Screen Orientation:

### Display Orientation:

The display can be rotated in all ´4 directions.  Use setRotation(n)
to rotate the image to match the physical rotation where ‘n’ ranges
from ´0 to ´3.

You will also need to set the Rotation of the ‘Touch Screen’. The
numbers **DO NOT MATCH**, so use one of the following combinations.
```
ILI9341 Display	 XPT2046 Touchscreen
    0	2
    1	3
    2	0
    3	1
```

<hr>
# findSPIpins.ino
<pre><code>
// findSPIpins.ino
// Find the default (Hardware) SPI pins for your board.
// Make sure you have the right board selected in: Tools __> Boards...

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);         // Initialize Serial communication
  while(!Serial);   // Wait for the Serial port to open

  Serial.print(" MOSI: ");
  Serial.println(MOSI);
  Serial.print(" MISO: ");
  Serial.println(MISO);
  Serial.print("  SCK: ");
  Serial.println(SCK);
  Serial.print("SS/CS: ");
  Serial.println(SS);
}

void loop() {
  // put your main code here, to run repeatedly:
}
</code></pre>
<hr>

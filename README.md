# GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board

***A WORK IN PROGRESS*** &nbsp; &nbsp; Prof. Michael P. Harris &nbsp; &nbsp; *06/02/2025*<br/>
[GitHub Pages](https://pages.github.com/)

![GOOUUU-Tech ESP32-S3-CAM Expansion Board](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%20Expansion%20Board-1.jpg)

## Development Boards, NOT Compatible _(too narrow)_:
```
ESP32-S3-WROOM-1 “pin-compliant” Development boards:     Pins   CAM SD RGB LEDs
                                                                       LED
 0. Espressif ESP32-S3-DevKitC-1 (no camera, no SD card)  44            ✓  1+RGB
```
> [0. Espressif ESP32-S3-DevKitC-1](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/0.%20Espressif%20ESP32-S3-DevKitC-1.jpg)

## _Use_ the “Yellow” 40-pin (20+20) headers:<br/>_(also 44-pin (22+22) with top & bottom pin overhang!)_
```
ESP32-S3-WROOM-1 “pin-compliant” Development boards:     Pins   CAM SD RGB LEDs
                                                                       LED
 1. GOOUUU ESP32-S3-CAM     (DevKitC-1 clone + CAM + SD)  40     ✓  ✓  ✓  2+RGB
 2. ESP32-S3-WROOM CAM   (FREENOVE ESP32-S3-WROOM clone)  40     ✓  ✓  ✓  4+RGB
 3. FREENOVE ESP32-S3-WROOM (CAM)                         40     ✓  ✓  ✓  4+RGB
 4. FREENOVE ESP32-S3-WROOM-Lite (no camera interface)    40            ✓  4+RGB

 5. YD-ESP32-S3 (ESP32-S3-WROOM-1 Dev) (DevKitC-1 clone)  44            ✓  3+RGB
 6. AI-S3 (YD-ESP32-S3 clone)          (DevKitC-1 clone)  44            ✓  3+RGB
 7. WeAct Studio ESP32-S3-A/B Core     (DevKitC-1 clone)  44            ✓  1+RGB
 8. WaveShare ESP32-S3-DEV-KIT-N8R8    (DevKitC-1 clone)  44            ✓  1+RGB
```
> [1. GOOUUU ESP32-S3-CAM](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/1.%20GOOUUU%20ESP32-S3-CAM.jpg)<br/>
> [2. ESP32-S3-WROOM CAM](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/2.%20ESP32-S3-WROOM%20(CAM).jpg)<br/>
> [3. FREENOVE ESP32-S3-WROOM (CAM)](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/3.%20FREENOVE%20ESP32-S3-WROOM%20(CAM).jpg)<br/>
> [4. FREENOVE ESP32-S3-WROOM Lite](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/4.%20FREENOVE%20ESP32-S3-WROOM-Lite.jpg)<br/>
> <br/>
> [5. YD-ESP32-S3 (ESP32-S3-WROOM-1 Dev)](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/5.%20YD-ESP32-S3%20(ESP32-S3%20Dev).jpg)<br/>
> [6. AI-S3 (YD-ESP32-S3 clone)](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/6.%20AI-S3%20(YD-ESP32-S3%20clone).jpg)<br/>
> [7. WeAct Studio ESP32-S3-A/B Core](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/7.%20WeAct%20Studio%20ESP32-S3-AB.jpg)<br/>
> [8. WaveShare ESP32-S3-DEV-KIT-N8R8](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/8.%20WaveShare%20ESP32-S3-DEV-Kit-N8R8.jpg)


## _Use_ the “Black” 42-pin (21+21) headers:
```
ESP32-S3-WROOM-1 “pin-compliant” Development boards:     Pins   CAM SD RGB LEDs
                                                                       LED
 9. ESP32-S3-DevKitC-1-ALT       (no camera, no SD card)  42            ✓  1+RGB
```
> [9. ESP32-S3-DevKitC-1-ALT](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/9.%20ESP32-S3-DevKitC-1-ALT.jpg)
<br/>
close but not quite...<br/>

> [10. Lolin-S3 ESP32-S3](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/10.%20Lolin-S3%20ESP32-S3.jpg)<br/>
> [10. Lolin-S3 ESP32-S3](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/10.%20Lolin-S3%20ESP32-S3.jpg)

<hr>

## [How to identify the family of compatible ESP32-S3 Development Boards](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/info/How%20to%20identify%20the%20family%20of%20compatible%20ESP32-S3%20Development%20Boards.md)
<hr>

# GOOUUU Tech ESP32-S3-CAM Expansion Board Diagram
<pre><code>
.___________________________________________________________________________________.
| Ø  .………. ¬R4        S1·2·3·4      ¬R6   .-----------.  U2  P1·2·3·4             Ø |
|    ¦W Ø¦         GND • • • •           —ô 5V0 DHT11 ¦   Ø¨¨¦•¦ô¦o¦o¦¨¨Ø    I²C    |
|5V0 ¦5  ¦«—|•|VR  5V0 ô ô ô ô  |•|U3 —» —oDATA sensor¦   ¦   G V S S   ¦ Interface |
|    ¦0  ¦  |•|G1  SIG o o o o  |•|G2    —× n/c  temp ¦   ¦   N C C D   ¦ ————————— |
|GND ¦5  ¦  P7         G G G G  P8       —• GND  humi ¦   ¦   D C L A   ¦ GND — GND |
|    ¯¨¨¨¯             3 3 4 3        U3  '-----------'   ¦             ¦ VCC — 5V0 |
| R3 VR/POT            8 9 0 7                            ¦ 0.96″ OLED  ¦ SCL — G41 |
|                        ._______________.                ¦   64×128    ¦ SDA — G42 |
|                        ¦ .….…. .…. .……¯¦   G##~ SD_Card Ø……¨¨¨¨¨¨¨¨………Ø           |
|     DVP Camera ´_G##   ¦ ¦ ¦ ¦_¦ ¦_¦   ¦   G##÷ PSRAM                             |
|                     .——¦ ¦ ¦           ¦——.                                       |
|TXD ¤ ö 3V3       3V3|ö:¦——.··. .————/:•¦:¤|G43  TX› LED      .__SPI-LCD__ESP32-S3_|
|RXD o o EN        RST|o:¦  WiFi ß    '——¦:o|G44  RX‹          ¦_1. T_IRQ      × N/C|
| G1 o © G4      ´_G4 |©:¦  ˜¨¨˜ °       ¦:o|G1   VR• (T_CS)   ¦_2. T_CS       G1   |
| G2 o © G5      ´_G5 |©:¦ ESP32S3-N16R8 ¦:o|G2   U3• (T_DIN)  ¦_3. T_DIN      G2   |
|G42 o © G6      ´_G6 |©:¦         .………….¦:o|G42  SDA (T_CLK)  ¦_4. T_CLK      G42  |
|G41 o © G7      ´_G7 |©:¦ ŒÆ F©   ¦QRCD¦¦:o|G41  SCL (T_DO)   ¦_5. T_DO       G41  |
|G40 õ © G15     ´_G15|©:¦ ° N16R8 '…………'¦:õ|G40~ SD_DATA   •S3¦_6. SDO (MISO) G46  |
|G39 õ © G16     ´_G16|©:'———————————————':õ|G39~ SD_CLK    •S2¦_7. LED (BL)   3V3  |
|G38 õ © G17     ´_G17|© .………………………………………. õ|G38~ SD_CMD    •S1¦_8. SCK        G3   |
|G37 ð © G18     ´_G18|© ¦ ::::::::::::: ¦ ð|G37÷ PSRAM     •S4¦_9. SDI (MOSI) G45  |
|G36 ð © G8      ´_G8 |© ¦    Camera     ¦ ð|G36÷ PSRAM        ¦10. DC         G47  |
|G35 ð o G3  (SCK) G3 |o ¯¯:::::::::::::¯¯ ð|G35÷ PSRAM        ¦11. RST        G21  |
| G0 o o G46 (SDO) G46|o      GOOUUU       o|G0   ‹BOOT›       ¦12. CS         G14  |
|G45 o © G9      ´_G9 |©   ESP32-S3-CAM    o|G45      (SDI)    ¦13. GND        GND  |
|G48 ¤ © G10     ´_G10|©   ¬ ¬     ¤ ¤ ‹¤› ¤|G48  RGB LED      ¦14. VCC        5V0  |
|G47 o © G11     ´_G11|©   ¨ ¨   PWR TX 48 o|G47      (DC)     '————————————————————|
|G21 o © G12     ´_G12|©      ......       o|G21      (RST)                         |
|G20 o © G13     ´_G13|© RST ¦CH304G¦ BOOT ø|G20  D-            GOOUUU              |
|G19 o o G14 (CS)  G14|o ‹•›  ''''''   ‹•› ø|G19  D+     (ESP32-S3-CAM) V1.2        |
|GND • ô 5V0       5V0|ô ._____.O T._____. •|GND      2.8″ SPI TFT LCD 240×320      |
|                     |  | USB |T T| USB |  |                                       |
|G46: Input Only      |  |  C  |G L|  C  |  |                  M     M T   T   T    |
|         ¬   ¬       '——'ESP32'———'CH343'——'        V G   R   O S L I C T D T I    |
|         R5 R7      R1¬ R2¬                         C N C S D S C E S L C I D R    |
|          ¤   ¤      ‹•›   ‹•›  |USB-C|   ¤         C D S T C I K D O K S N O Q    |
| Ø       D2  D3      RST   KEY  '—————'  D1        ¦ô¦•¦o¦o¦o¦o¦o¦ö¦•¦o¦o¦o¦o¦×¦ Ø |
'———————————————————————————————————————————————————————————————————————————————————'
 Pinout:   G   P       E     G             T         5 G G G G G G 3 G G G G G ×
           4   W       N     0             X         V N 1 2 4 4 3 V 4 4 1 2 4
           8   R                                     0 D 4 1 7 5   3 6 2     1
</code></pre>

## TWO sets of header-pin sockets _(Yellow and Black)_
<pre><code> &nbsp; &nbsp; &nbsp; QUICK NOTE:&nbsp; This GOOUUU Tech ESP32-S3-CAM Expansion Board has TWO<br/>
 &nbsp; &nbsp; &nbsp; ———————————&nbsp; sets of header-pin sockets (Yellow and Black) to plug in<br/>
 &nbsp; &nbsp; &nbsp; your “ESP32-S3-WROOM-1” Development boards.
</code></pre>

# 40-Pin (20+20) “Yellow” header sockets _(primary)_
The `40-Pin` (20+20) `“Yellow”` header sockets, are designed for the &nbsp;
**GOOUUU “ESP32-S3-CAM”** board.&nbsp; A second, third, and fourth compatible
Dev Boards are the &nbsp;**“ESP32-S3-WROOM”** (CAM),&nbsp; a clone of the
**“FREEVOVE ESP32-S3-WROOM”** (CAM);&nbsp; and its’ sibling the&nbsp;
**“FREEVOVE ESP32-S3-WROOM-Lite”** _(no camera interface)_.&nbsp; All three of
these Dev Boards also work perfectly in the `40-Pin (20+20) “Yellow”` headers
&nbsp;--as all three of these &nbsp;*DVP camera ready*&nbsp; Dev boards have
the same pinouts,&nbsp; and same SoC main chip;&nbsp; the **“ESP32-S3-WROOM-1”**.

A fourth, fifth, and sixth development boards using the **“ESP32-S3-WROOM-1”** SoC,&nbsp;
are the **“YD-ESP32-S3”**,&nbsp; also called the **“ESP32-S3-WROOM-1 Dev”**,&nbsp; the
**“WaveShare ESP32-S3-DEV-KIT-N8R8”**,&nbsp; and the **“WeAct Studio ESP32-S3-A/B Core”**.&nbsp;
These are `44-pin` (22+22) boards,&nbsp; _(like the original ESP32-S3-DevKitC-1)_
&nbsp;--but the top and bottom rows of pins are just an extra `3V3` pin and three extra
`GND` pins.&nbsp; --These boards also works in the `40-Pin (20+20) “Yellow”` header pin
sockets...&nbsp; Just let the extra row of top & bottom pins hang over/extend past the
headers,&nbsp; allowing your `44-pin (22+22)` board to plug into a set of
`40-Pin (20+20) “Yellow”`header sockets.&nbsp; These development boards do NOT have a
&nbsp;*DVP camera interface* like our first three boards.

All eight of these **“ESP32-S3-WROOM-1”** Dev boards are pinout&nbsp;
***backward compatible***,&nbsp; -not counting the extra top & bottom
pins,&nbsp; with the original **Espressif**&nbsp; `44-pin (22+22)`
***“ESP-S3-DevKitC-1”***.

> **NOTE:**&nbsp; **DevKitC-1**,&nbsp; NOT DevKitM-1 *(M1 is NOT pin compatible)*.

*Unfortunately*,&nbsp; the original **“ESP-S3-DevKitC-1”** will not plug into
the `40-Pin (20+20) “Yellow”` headers,&nbsp; as this original Dev Board is
narrower *(by 1 pin spacing)* than the other seven Dev Boards.&nbsp; Otherwise
it could plug in just like the other `44-pin (22+22)` boards,&nbsp; like the
inexpensive workhorse **“YD-ESP32-S3”**.

![0. Espressif ESP32-S3-DevKitC-1](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/0.%20Espressif%20ESP32-S3-DevKitC-1.jpg)
<hr>

## Identifying **ESP32-S3-DevKitC-1** pin compatible boards
**NOTE:**&nbsp;
To identify one of these eight `40-pin (20+20)` **-or-** `44-pin (22+22)`
**ESP32-S3-DevKitC-1** pin compatible boards...&nbsp; Look at the board with
the two USB ports facing down.&nbsp; The Left-side pins will _end_ with `GPIO13`,
`GPIO14`, then `5V0` &nbsp;_(and possibly an extra `GND`)_.&nbsp;

![2. ESP32-S3-WROOM CAM](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/2.%20ESP32-S3-WROOM%20(CAM).jpg)

The top Right-side pins will _(possibly start with a `GND` pin)_&nbsp; then
_begin_ with `TXD`, `RXD`, `GPIO1`, then `GPIO2`.

The `44-pin (22+22)` boards,&nbsp; like the **“YD-ESP32-S3”** and
**“ESP32-S3-DevKitC-1”**,&nbsp; have 1 extra pin at the top and bottom of
each header,&nbsp; --an extra `3V3` pin in the upper-Left,&nbsp; and an
extra `GND` pin on the other 3 corners.

![6. AI-S3 (YD-ESP32-S3 clone)](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/6.%20AI-S3%20(YD-ESP32-S3%20clone).jpg)
<hr>

# 42-Pin (21+21) “Black” header sockets
The `42-Pin (21+21) “Black” header` sockets are for an **ALT version**
&nbsp;of the **“ESP-S3-DevKitC-1”**.&nbsp; This **ALT** version has
`42-pins (21+21)` instead of the original `44-pins (22+22)`,&nbsp;
and is 1 pin-space wider,&nbsp; like the Dev boards mentioned above.

Even though this `42-pin (21+21)` **“ESP-S3-DevKitC-1_ALT-version”**
uses the same **“ESP32-S3-WROOM-1”** SoC,&nbsp; --the pinout is
similar, but **NOT** the same as the other `40-pin (20+20)` and
`44-pin (22+22)` Dev boards...&nbsp; **“ESP32-S3-GOOUUU-CAM”**,&nbsp;
**“ESP32-S3-WROOM”** (CAM),&nbsp; **“FREEVOVE ESP32-S3-WROOM”**,&nbsp;
**“YD-ESP32-S3”**,&nbsp; or the original `44-pin (22+22)`
**“ESP-S3-DevKitC-1”**.

![9. ESP32-S3-DevKitC-1-ALT](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/9.%20ESP32-S3-DevKitC-1-ALT.jpg)

A quick way to identify this **ALT** Development board,&nbsp; besides the
`42-pins (21+21)`,&nbsp; instead of `40-pins (20+20)` or `44-pins (22+22)`,
&nbsp;is to look at the board with the two USB ports facing down.&nbsp;
The upper-Right pins will _start_ with _(an extra)_ `GND`,&nbsp; then `GPIO1`,
`GPIO2`, `TX0`, `RX0`.&nbsp; The lower-Left will _end_ with `GPIO11`,
`GPIO12`, `3V3`.&nbsp; --AND most importantly,&nbsp; the lower-Right
pin is `5VIN`.

> [!WARNING]
> I want to pointout this _lower-Right_ `5VIN` pin,&nbsp; specifically,
> &nbsp;because _All_ of the other ESP32-S3 Dev boards mentioned,&nbsp;
> have a `GND` (power ground) pin in the lower-Right.&nbsp; Plugging
> in a `5V` pin into a `GND` header socket, or vice-versa, is a quick
> way to short out and burn-up your Dev board!
<hr>

# Very clever 2-way “Yellow” and “Black” header sockets

The design engineers for the _“GOOUUU Tech ESP32-S3-CAM Expansion Board”_
have done something very clever!&nbsp; They have _cross-wired_,&nbsp; where
needed,&nbsp; the pins in the `40-pin (20+20) “Yellow”` header to the
`42-pin (21+21) “Black”` header to match the pinout functions.

**For example:**&nbsp; the first four upper-Right pins of the `40-pin (20+20) “Yellow”`
header are:&nbsp; `1. TXD`, `2. RXD`, `3. GPIO1`, `4. GPIO2`.  The first five
pins of the `42-pin (21+21) “Black”` header are:&nbsp; `1. GND`, `2. GPIO1`, `3. GPIO2`,
`4. TX0`, and `5. RX0`.&nbsp; Copper traces on the Expansion Board,&nbsp; connect the
“Yellow” pin-1 `TXD` to the “Black” pin-4 `TX0`,&nbsp; and “Yellow” pin-2 `RXD`
to “Black” pin-5 `RX0`.&nbsp; Also `GPIO1` is _cross_ _connected_ to `GPIO1`,&nbsp;
`GPIO2` is _cross_ _connected_ to `GPIO2` and so on.&nbsp;

Since all the “ESP32-S3-WROOM-1” SoC designs have the same set of GPIO pins... this
allows for a single `40-pin (20+20)` _double-row_ breakout header along the Left-side
of the Expansion Board.&nbsp; The pinout of this breakout header, _mirror-image_
matches the `40-pin (20+20)` `“Yellow” headers`,&nbsp; and all of the pins are
well labled.

## 40-pin (20+20) “Yellow” & 42-pin (21+21) “Black” header sockets diagram

![GOOUUU-Tech ESP32-S3-CAM Expansion Board _Yellow_ & _Black_ headers](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%20Expansion%20Board-2.jpg)

Following is my diagram,&nbsp; illustrating the 2-way “ESP32-S3-WROOM-1”
Development Board `40-pin (20+20) “Yellow”` & `42-pin (21+21) “Black”`
header sockets.

 1. Pins marked **©** and **´_** &nbsp;-are pins reserved for the **DVP Camera**.
    (Includes ALL of the GPIO pins on the _Left-side_ header,&nbsp; except:
     `GPIO3`, `GPIO46`, & `GPIO14`).
 2. Pins marked **õ** and **~** &nbsp;-are pins reserved for the **TF SD_Card** slot.
    (`GPIO38`, `GPIO39`, & `GPIO40`).&nbsp; The TF SD_Card slot is on the back.
 3. Pins marked **ð** and **÷** &nbsp;-are pins reserved for **PSRAM** and **QIO Flash**.
    (`GPIO35`, `GPIO36`, & `GPIO37`).&nbsp; Best not to use these pins.
 4. Pins marked **ô** &nbsp;-are `5V0` &nbsp;(5.0 volts)
 5. Pins marked **ö** &nbsp;-are `3V3` &nbsp;(3.3 volts)
 6. Pins marked **•** &nbsp;-are `GND`
 7. Pins marked **ø** &nbsp;-are `USB_D+` & `USB_D-`
 8. Pins marked **»** or **«** &nbsp;-are pins with _position_ _mismatches_ between
    the “Yellow” **P1** & **P2** header-pin sockets and the Black **P3** & **P3** sockets.

<pre><code>
        ¦ GOOUUU ESP32-S3-CAM ¦ or: “ESP32-S3-WROOM” (CAM)
        ¦   `40-pin headers`  ¦     “FREEVOVE ESP32-S3-WROOM”
        V  “Yellow” P1 & P2   V     “YD-ESP32-S3”/ESP32-S3-WROOM-1 Dev
                                    “WaveShare ESP32-S3-DEV-KIT-N8R8”
                                    “WeAct Studio ESP32-S3-A/B Core”
         ¦ ESP32-S3-DevKitC-1  ¦
         ¦ `42-pin ALT VERSION`¦
         V   “Black” P3 & P4   V

        .—P1 (“Yellow”)       .—P2 (“Yellow” 40-pin (20+20) headers)
        ¦.—P3 (“Black”)       ¦.—P4 (“Black” 42-pin (21+21) headers)
        ¦¦                    ¦¦
        ×•  GND               ×•  GND               NOTE¹: The DVP Camera
  3V3   öö  3V3 same    »TXD  oo  G1«                      interface uses
   EN   oo   EN same    »RXD  oo  G2«                      all the Yellow
 ´_G4   ©©   G4 same    »G1   oo  TX0«                     GPIO Left-side
 ´_G5   ©©   G5 same    »G2   oo  RX0«                     _pins_ except:
 ´_G6   ©©   G6 --same-- G42  oo  G42                      `GPIO3`, `GPIO46`,
 ´_G7   ©©   G7 --same-- G41  oo  G41                      and `GPIO14`.
 ´_G15  ©©  G15 --same-- G40  õõ  G40~  SD_Card `GPIO40`
 ´_G16  ©©  G16 --same-- G39  õõ  G39~    "     `GPIO39`
 ´_G17  ©©  G17 --same-- G38  õõ  G38~    "     `GPIO38`
 ´_G18  ©©  G18 --same-- G37  ðð  G37÷  PSRAM   `GPIO37`
 ´_G8   ©©   G8 --same-- G36  ðð  G36÷    "     `GPIO36`
  »G3   oø  G19« D+ same G35  ðð  G35÷    "     `GPIO35`
  »G46  oø  G20« D- same G0   oo  G0
»´_G9   ©o   G3«    same G45  oo  G45               NOTE²: Pin `GPIO46` is
»´_G10  ©o  G46«    same G48  ¤¤  G48                      INPUT only.
»´_G11  ©©   G9«    same G47  oo  G47                      No pullups.
»´_G12  ©©  G10«    same G21  oo  G21
»´_G12  ©©  G10«    same G21  oo  G21
»´_G13  ©©  G11«     D- »G20  øo  G14«
  »G14  o©  G12«     D+ »G19  ø©  ´_G13«
  »5V0  ôö  3V3«        »GND  •ô  5VIN« («— _Be careful!_)
        ¦¦                    ¦¦
        ¦'—“Black”            ¦'—“Black”
        '—“Yellow”            '—“Yellow”
</code></pre>
<hr>

## MISC Pin connections/configurations:

GOOUUU Tech ESP32-S3-CAM Expansion Board<br/>
&nbsp; &nbsp; MISC Pin connections/configurations:

   + VR R3  W505 Pot: `GPIO1`
   + U2 DHT11 sensor: `GPIO2`

   * Jumper P7: `GPIO1`  (VR Enable)
   * Jumper P8: `GPIO2`  (U2 Enable)

   - Header S1: `GPIO38` (3-Wire PWM)
   - Header S2: `GPIO39` (3-Wire PWM)
   - Header S3: `GPIO40` (3-Wire PWM)
   - Header S4: `GPIO37` (3-Wire PWM)

   + I²C SCL: `GPIO41` &nbsp; &nbsp; &nbsp;{0.96″ OLED}
   + I²C SDA: `GPIO42` &nbsp; &nbsp; &nbsp;{  64×128  }

   * LED D1: `GPIO48` RGB LED
   * LED D2: `PWR ON`
   * LED D3: `GPIO43` TXD LED

   - ‹RST› Button: `EN/RESET`
   - ‹KEY› Button: `GPIO0/BOOT`
<hr>
<br/>

# LCD 2.8in 240×320 SPI TFT Display (ILI9341)

![2.8″ 240×320 SPI TFT LCD Display](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/ILI9341%202.8in%20240x320%20TFT%20Display.jpg)
<br/>

## 14-Pin SPI 2.8in 240×320 TFT LCD header:

### GOOUUU Tech ESP32-S3-CAM Expansion Board<br/>14-Pin SPI 2.8in 240×320 ILI9341 TFT header:

| **ILI9341 2.8in<br/>LCD Display<br/>with Touch:** | **GOOUUU Tech<br/>Expansion<br/>Board:** | <br/><br/>**Description:** |
|------------------|     :---:       |--------------------------------|
| 1. T-IRQ         |    × _N/C_      | Touch Interrupt,   _Active LOW_|
| 2. T-DO  (MISO)  |    GPIO41       | Touch Data Out    (SPI MISO)   |
| 3. T-DIN (MOSI)  |    GPIO2        | Touch Data In     (SPI MOSI)   |
| 4. T-CS          |    GPIO1        | Touch Chip Select, _Active LOW_|
| 5. T-CLK (SCLK)  |    GPIO42       | Touch SPI Clock   (SPI SCLK)   |
| 6. SDO   (MISO)  |    GPIO46       | GND _Not Used_    (SPI MISO)   |
| 7. LED           |    3V3          | BackLight Enable, _Active HIGH_|
| 8. SCK   (SCLK)  |    GPIO3        | LCD SPI Clock     (SPI SCLK)   |
| 9. SDI   (MOSI)  |    GPIO45       | LCD Data In       (SPI MOSI)   |
|10. DC            |    GPIO47       | LCD Data/Command, _HIGH = Data_|
|11. RESET         |    GPIO21       | LCD Reset input,   _Active LOW_|
|12. CS            |    GPIO14       | LCD Chip Select,   _Active LOW_|
|13. GND           |    GND          | Power System       Ground      |
|14. VCC           |    5V0          | Power System       5V0         |
<br/>

### SPECIAL NOTE:&nbsp; Touch Screen SPI pins versus the LCD SPI pins:

As noted above and on the on the Expansion Board Diagram #1,&nbsp; the
SPI XPT2046 Touch Screen controller on the 2.8in TFT LCD Display
is wired/configured to the following pins:

> | **XPT2046 Pin** | **Description**   | **ESP32-S3 Pin** |
> |     :---:       |-------------------|       :---:      |
> | T-IRQ           | Touch Interrupt   | N/C              |
> | T-CLK (SCLK)    | Touch SPI SCLK    | GPIO42           |
> | T-DO  (MISO)    | Touch SPI MISO    | GPIO41           |
> | T-DIN (MOSI)    | Touch SPI MOSI    | GPIO2            |
> | T-CS            | Touch Chip Select | GPIO1            |

The SPI control pins for the ILI9341 2.8in 240×320 TFT LCD Display itself are:

> | **ILI9341 Pin** | **Description**   | **ESP32-S3 Pin** |
> |      :---:      |-------------------|       :---:      |
> | SCK   (SCLK)    | LCD SPI SCLK      | GPIO3            |
> | SDO   (MISO)    | LCD SPI MISO      | GPIO46           |
> | SDI   (MOSI)    | LCD SPI MOSI      | GPIO45           |
> | CS              | LCD Chip Select   | GPIO14           |

The *XPT2046 Touch Screen controller* is supported for SPI based displays.&nbsp;
The SPI bus for the Touch controller is _“shared”_ with the SPI TFT LCD,&nbsp;
and ‘only’ an additional CS _(Chip Select)_ pin is needed.

This means that the three SPI Touch pins:&nbsp; `T-CLK` (SCLK), `T-DO` (MISO),
and `T-DIN` (MOSI),&nbsp; could have been wired/configured to the _“same”_
corresponding SPI TFT LCD pins:&nbsp; `SCK` (SCLK) - `GPIO3`, `SDO` (MISO) - `GPIO46`,
and `SDI` (MOSI) - `GPIO45`.&nbsp; Only the individual *CS* _(Chip Select)_
line needed to be assigned to seperate GPIO pin.&nbsp;
*This could have freed up ‘three’ ESP32-S3-WROOM pins*.

This is very important,&nbsp; because as configured,&nbsp; if you are using
one of the *ESP32-S3-WROOM* boards with a _“DVP Camera”_ interface &nbsp;and
_“NOT sharing”_ those three primary SPI pins,&nbsp; you now have ‘zero’ pins
availiable.&nbsp; --And that is ‘0’ pins free _after_ giving up the `I²C`
interface on `SCL` - `GPIO41` and `SDA` - `GPIO42`&nbsp; to the Touch Screen
interface.

As wired/configured,&nbsp; if you want an `I²C interface`, you need to give up
`Touch Screen` capability,&nbsp; and vice-versa.&nbsp; If the 3 primary SPI pins
were _“shared”_, &nbsp;we could have both,&nbsp; with ‘1’ pin left over.&nbsp;
We could even add a `buzzer` audio interface or possibily a Analog 1-pin `keypad`,
etc.
<hr>

![14-Pin SPI 2.8″ 240×320 TFT LCD header](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/ILI9341%202.8in%20240x320%20TFT%20Display-5.jpg)

## TFT LCD 2.8″ 240×320 DISPLAY WITH TOUCH SCREEN

Key Features of the TFT LCD 2.8″ 240×320 Display with Touch Screen:

+ 2.8″ TFT LCD with 240×320 resolution
+ 65K 16-BIT colors using a ILI9341 controller
+ Resistive Touch Screen using an XPT2046 controller
+ SPI 4-wire `ILI9341` LCD interface (`SCK`,    `SDI_MOSI`, `SDO_MIS0`, `CS`)
+ SPI 4-wire `XPT2046` Touch Screen  (`T-CLK`,  `T-DIN`,    `T-DO`,     `T-CS`)
+ SPI 4-wire `SD_Card` interface     (`SD_SCK`, `SD_MOSI`,  `SD_MISO`,  `SD_CS`) _(Not Used)_
+ 3.6V to 5.5V module operation
+ 3.3V logic compatible only

**NOTE:**&nbsp; The SPI `SD_Card` interface is _(**Not Used**)_ on this Expansion Board.
&nbsp;Instead,&nbsp; the 4-pin header the SPI `SD_Card` pins plug into, are wired as an
`I²C interface` using `SCL` - `GPIO41` and `SDA` - `GPIO42`.&nbsp; This allows the
use of a standard I²C 128×64 SSD1306 OLED Display.&nbsp; Notice that
`GPIO41` and `GPIO42` are also used by the _Touch Screen interface_... although if
you are using an I²C OLED Display,&nbsp; you would not be using the TFT Touch Screen.

![I²C 128×64 SSD1306 OLED Display](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%20Expansion%20Board-5.jpg)

Internally,&nbsp; the LCD display logic operates at `3.3V`,&nbsp;
-so if you use the LCD TFT module with a `5V0` Microcontroller,&nbsp;
be sure to include _logic level shifters_ on the data lines to prevent
possible damage.

These full color displays are large enough for many applications
even when using _Touch_.&nbsp; The supplied ‘stylus’ is helpful when
using smaller Touch targets.&nbsp; The LCD TFT module has an `SD_Card`
socket.&nbsp; This socket has separate connections on the opposite
end of the LCD TFT board.&nbsp; This is not needed with the
**“ESP32-S3-CAM”**,&nbsp; as it already has a `TF SD_Card` slot on
its’ backside.

> **DO NOT CONFUSE:**&nbsp; the ***SPI*** _SD_Card interface_&nbsp; on the
> LCD TFT module pins&nbsp; _(SD_SCK, SD_MOSI, SD_MISO, SD_CS)_,&nbsp;
> _which we are not using_,&nbsp; with the ***SDIO*** _SD_Card interface_&nbsp;
> to the `TF SD_Card slot` on the backside of the “DVP Camera capable”
> Dev boards.&nbsp;
>
> This _high speed_ advanced &nbsp;***SDIO*** _SD_Card interface_&nbsp;
> is configured on reserved pins&nbsp; _(GPIO38 &nbsp;**SD_CMD**,&nbsp;
> `GPIO39` &nbsp;**SD_CLK**,&nbsp; and `GPIO40` &nbsp;**SD_DATA**)_.

## 2.8″ TFT LCD Display Technical Specifications:

### LCD Module Power:

SEE IMAGE:  TFT LCD 2.8″ 240×320 RGB ILI9341 with Touchscreen
—» `J1` Jumper Location

![J1 Jumper Location](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/ILI9341%202.8in%20240x320%20TFT%20Display-6.jpg)

The LCD module power comes in on the `VCC` pin.&nbsp; The LCD includes an
on-board 3.3V regulator,&nbsp; so the LCD should normally be operated
with `3.6V` to `5.5V` power on this pin to feed the regulator.&nbsp;
Current draw is typically 55mA-60mA.

If you would prefer to operate the LCD module directly from a `3.3V`
power source,&nbsp; there are two solder pads labeled ‘**J1**’.&nbsp;
By solder shorting these two pads together,&nbsp; the 3V3 regulator
is bypassed and the LCD module can be powered directly from `3.3V`.

In general,&nbsp; it is best to operate the display off of `5V0` to
ensure enough power is available.&nbsp;  Be careful of trying to
operate the the display from the built-in 3.3V available on Arduino
and similar microcontrollers since these power sources often have
limited current capability and may overheat.

### LCD SPI Interface:

This LCD display incorporates a SPI interface which provides for fast
display updates.&nbsp; It is a 4-wire SPI interface,&nbsp; so it includes
a `CS` _(Chip Select)_ pin.

The _Touch Screen_ also uses the SPI interface and _CAN_ hook up to the
_“same SPI pins”_ as the LCD display,&nbsp; but use a separate `CS`
_(Chip Select)_ to avoid conflicts.

For best performance the _hardware_ _SPI_ interface should be used if
possible to get the fastest screen updates.
```
        Display Controller: ILITEK ILI9341
          Touch Controller: XPT XPT2046

        Display Technology: TFT LCD
                Resolution: 240×320 pixels
                     Color: RGB 65K color (16-bit 5:6:5)
             Viewing Angle: 60°
                Interfaces: SPI (LCD Display, Touch, and SD_Card)
         Operating Ratings: DC Power Input 3.6V – 5.5V
         Operating Current: 55mA-60mA (typical)

    Dimensions:
         Module Size (PCB): 86×50mm     (3.39″×1.97″)
          Display diagonal: 71.12mm     (2.8″)
             Display (W×H): 57.6×43.2mm (2.27×1.7″)
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
    you have made the 3V3 option by soldering the ‘J1’ pads.
```

## Display Orientation & Touch Screen Orientation:

### Display Orientation:

The LCD display output can be _rotated_ in all 4-directions.&nbsp;
Use &nbsp;`setRotation(n)`&nbsp; to rotate the image to match your
desired physical rotation where _‘n’_ ranges from 0 to 3.

You will also need to set the _rotation_ of the ‘*Touch Screen*’.&nbsp;
The configuration numbers **DO NOT MATCH**,&nbsp; so use one of the
following combinations.

> | *Rotation* | *ILI9341 Display* | *XPT2046 Touchscreen* |
> |    :---:   |       :---:       |        :---:          |
> |       0°   |         0         |          2            |
> |      90°   |         1         |          3            |
> |     180°   |         2         |          0            |
> |     270°   |         3         |          1            |
<hr>
<br/>

## DVP Camera interface:

### ESP32-S3-WROOM-1 &nbsp;Camera Interface&nbsp; (OV2640)
<pre><code>———————————————————————————————————————————————————————————————————————
 Uses ALL but 3 IO pins on the   ESP32-S3-WROOM-1    Camera Interface
 Left-side of ESP32-S3-WROOM-1   (Left Side Pins)    (FPC 0.5mm 24P)
                                  1.     3V3         1. NC      ×
44-pin (22+22) & 40-pin (20+20)   2.  1. 3V3         2. AGND    GND
                                  3.  2. EN   ‹RST›  3. SDA     CAM_SIOD
    CAM_SIOD    SDA IO4  .··..·›  4.  3. IO4         4. AVDD    VDD_2V8
    CAM_SIOC    SCL IO5  .··..·›  5.  4. IO5         5. SCL     CAM_SIOC
    CAM_VSYNC       IO6  ······›  6.  5. IO6         6. RESET   10K~VDD_2V8
    CAM_HREF        IO7  ······›  7.  6. IO7         7. VSYNC   CAM_VSYNC
    CAM_XCLK        IO15 ······›  8.  7. IO15        8. PWDN    10K~GND
    CAM_Y9      D7  IO16 ······›  9.  8. IO16        9. HREF    CAM_HREF
    CAM_Y8      D6  IO17 ······› 10.  9. IO17       10. DVDD    VDD_1V5
    CAM_Y7      D5  IO18 ······› 11. 10. IO18       11. DOVDD   VDD_2V8
    CAM_Y4      D2  IO8  ······› 12. 11. IO8        12. Y9      CAM_Y9
                               » 13. 12. IO3        13. XCLK    CAM_XCLK
                               » 14. 13. IO46       14. Y8      CAM_Y8
    CAM_Y3      D1  IO9  ······› 15. 14. IO9        15. DGND    GND
    CAM_Y5      D3  IO10 ······› 16. 15. IO10       16. Y7      CAM_Y7
    CAM_Y2      D0  IO11 ······› 17. 16. IO11       17. PCLK    CAM_PCLK
    CAM_Y6      D4  IO12 ······› 18. 17. IO12       18. Y6      CAM_Y6
    CAM_PCLK        IO13 ······› 19. 18. IO13       19. Y2      CAM_Y2
                               » 20. 19. IO14       20. Y5      CAM_Y5
                                 21. 20. 5V0  VBUS  21. Y3      CAM_Y3
    VDD_3V3     AMS1117-3.3      22.     GND        22. Y4      CAM_Y4
    VDD_2V8     ME621C28                            23. NC      ×
    VDD_1V5     ME621C15                            24. NC      ×

————————————————————————————————————————————————————————————————————
</code></pre>

![ESP32-S3 DVP Camera Interface (OV2640)](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%20Expansion%20Board-4.jpg)
<hr>

### SDIO SD_Card interface:&nbsp; _(GPIO38, GPIO39, & GPIO40)_

The **SPI** _SD_Card interface_&nbsp; on the TFT LCD is not needed because
the **“ESP32-S3-CAM”**,&nbsp; already has a `TF SD_Card` slot on its’ backside.

> **DO NOT CONFUSE:**&nbsp; the ***SPI*** _SD_Card interface_&nbsp; on the
> LCD TFT module pins&nbsp; _(SD_SCK, SD_MOSI, SD_MISO, SD_CS)_,&nbsp;
> which we are not using,&nbsp; with the ***SDIO*** _SD_Card interface_&nbsp;
> to the TF SD_Card slot on the backside of the “DVP Camera capable”
> Dev boards.&nbsp;

This _high speed_ advanced &nbsp;***SDIO*** _SD_Card interface_&nbsp;
is configured on reserved pins&nbsp; _(GPIO38 &nbsp;**SD_CMD**,&nbsp;
GPIO39 &nbsp;**SD_CLK**,&nbsp; and GPIO40 &nbsp;**SD_DATA**)_.

![ESP32-S3 SDIO TF SD_Card Interface](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/1.%20GOOUUU%20ESP32-S3-CAM.jpg)


See example usage in `\code`.&nbsp; _...to be continued..._
<hr>

### SPI ƒlash and PSRAM _(GPIO26..GPIO32)_:

GPIO26 to GPIO32 are connected to the integrated SPI ƒlash and PSRAM
and are not recommended for other uses.&nbsp; They are not exposed on
these particular Dev boards, but if they are exposed on your board,
avoid using them:

+ GPIO26 (ƒlash/PSRAM SPICS1)
+ GPIO27 (ƒlash/PSRAM SPIHD)
+ GPIO28 (ƒlash/PSRAM SPIWP)
+ GPIO29 (ƒlash/PSRAM SPICS0)
+ GPIO30 (ƒlash/PSRAM SPICLK)
+ GPIO31 (ƒlash/PSRAM SPIQ)
+ GPIO32 (ƒlash/PSRAM SPID)

### Missing _N/C_ Pins:&nbsp; _GPIO33_ & _GPIO34_

## OPI PSRAM additional Pins:&nbsp; _(GPIO35..GPIO37)_:

**IN ADDITION:**&nbsp; For boards with _Octal SPI ƒlash/PSRAM_ memory
embedded,&nbsp; for example all boards with an **ESP32-S3-WROOM-1**
module and boards with **ESP32-S3-WROOM-2** modules,&nbsp; --pins
`GPIO35`,&nbsp; `GPIO36` &nbsp;and `GPIO37` are reserved for internal
communication between the _ESP32-S3_ and the _Octal SPI ƒlash/PSRAM_
memory,&nbsp; and thus are NOT available for external use.
———————————————————————————————————————————————————
<hr>
<br/>

# Code Snippets:
<hr>
<br/>

## findSPIpins.ino
```C++
// findSPIpins.ino

// Find the default (Hardware) SPI pins for your board.
// Make sure you have the right board selected in:&nbsp; `Tools —» Boards`...

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);         // Initialize Serial communication
  while(!Serial);               // Wait for the Serial port to open

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
```
<hr>

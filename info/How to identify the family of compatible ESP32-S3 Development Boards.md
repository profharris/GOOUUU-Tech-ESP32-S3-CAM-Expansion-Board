## How to identify the family of compatible ESP32-S3 Development Boards
<hr>

## GOOUUU Tech ESP32-S3-CAM Expansion Board

***A WORK IN PROGRESS*** &nbsp; &nbsp; Prof. Michael P. Harris &nbsp; &nbsp; *06/01/2025*<br/>
[GitHub Pages](https://pages.github.com/)

![GOOUUU-Tech ESP32-S3-CAM Expansion Board _Yellow_ & _Black_ headers](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%20Expansion%20Board-2.jpg)

As I’ve been working with the **GOOUUU Tech ESP32-S3-CAM Expansion Board**,&nbsp;
I have identified 10 compatible Development Boards,&nbsp; so far...

Let’s break down how you can identify a compatible Development Board.&nbsp;
Obviously,&nbsp; as _GOOUUU Tech_ is the designer and developer of this _Expansion Board_&nbsp;
it was designed for their very own&nbsp;
[GOOUUU ESP32-S3-CAM](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/1.%20GOOUUU%20ESP32-S3-CAM.jpg)
&nbsp;board.&nbsp; But due to partial standardization and clones of the original&nbsp;
[Espressif ESP32-S3-DevKitC-1](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/0.%20Espressif%20ESP32-S3-DevKitC-1.jpg),
&nbsp;there are many other _ESP32-S3-WROOM-1_ based boards completely compatible with the<br/>
[GOOUUU-Tech ESP32-S3-CAM Expansion Board](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%20Expansion%20Board-1.jpg).

## The “Yellow” 40-pin (20+20) headers

The big majority of the compatible Development Boards I've discovered,&nbsp;
are either _40-pin_ (20+20),&nbsp; and plug directly into the _“Yellow” 40-pin (20+20) headers_,&nbsp;
**-or-** are _44-pin_ (22+22) Development Boards,&nbsp; which plug the _“Yellow” 40-pin headers_&nbsp;
by skipping/overlaping the top and bottom rows of pins.

The `44-pin` (22+22) boards,&nbsp; share the same pinout as the original&nbsp;
[Espressif ESP32-S3-DevKitC-1](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/0.%20Espressif%20ESP32-S3-DevKitC-1.jpg).
&nbsp;--The top and bottom rows of pins are just an extra `3V3` pin in the upper Left,&nbsp;
and three extra `GND` pins in the other three corners.&nbsp; --These boards also works in the
`40-Pin (20+20) “Yellow”` header pin sockets...&nbsp; Just let the extra row of top & bottom
pins hang over/extend past the `40-pin` “Yellow” headers,&nbsp; allowing your `44-pin (22+22)` 
board to plug into a set of `40-pin (20+20) “Yellow”`header sockets.&nbsp; These development 
boards generally do NOT have a &nbsp;*DVP camera interface*.

This practice of skipping the extra pins at the top and bottom is so wide spread,&nbsp;
that the majority of ESP32-S3-WROOM-1 development boards today are `40-Pin (20+20)`.

> 1. &nbsp;44-pin (22+22) pinout [Espressif ESP32-S3-DevKitC-1 44-pin pinout](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/ESP32-S3-DevKitC-1%2044-pins%20pinout.jpg)<br/>
> 2. &nbsp;40-pin (20+20) pinout [GOOUUU ESP32-S3-CAM 40-pin pinout](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%2040-pins%20pinout.png).
<hr>

【1.】 Let’s start with the most widely availiable,&nbsp; and least expensive,&nbsp; of the ESP32-S3-WROOM-1 
compatible Development Boards.<br/>The
[YD-ESP32-S3 (ESP32-S3-WROOM-1 Dev)](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/5.%20YD-ESP32-S3%20(ESP32-S3%20Dev).jpg).

![YD-ESP32-S3 (ESP32-S3-WROOM-1 Dev)](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/5.%20YD-ESP32-S3%20(ESP32-S3%20Dev).jpg).

This is a `44-pin (22+22)` development board,&nbsp; sharing the same pinout as the original&nbsp; 
[Espressif ESP32-S3-DevKitC-1](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/0.%20Espressif%20ESP32-S3-DevKitC-1.jpg).
&nbsp; -It is even mis-labled on many sites, selling as an _Espressif ESP32-S3-DevKitC-1_,&nbsp;
--but there are _two_ big differences. 

1. The [VCC-GND.com](https://vcc-gnd.com/) **YD-ESP32-S3** and its’ clones,&nbsp; are _1 pin-space_
wider than the original&nbsp; 
[Espressif ESP32-S3-DevKitC-1](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/0.%20Espressif%20ESP32-S3-DevKitC-1.jpg).
&nbsp; Regrettably, an orininal _Espressif ESP32-S3-DevKitC-1_,&nbsp; will not plug into the
`40-Pin (20+20) “Yellow”` header pin sockets because it is _1 pin-space_ too narrow.&nbsp; 
Being _1 pin-space_ wider is a good thing, as most of the Dev Boards availiable use this
wider form factor.

2. The main recognizable difference, making the **YD-ESP32-S3** and its’ clones unique,&nbsp;
-are the three solder-jumbers on the board.&nbsp; 
> 1. The first solder-jumber,&nbsp;  “**RGB**” (RGB CTRL),&nbsp; is just to the right of the large white 
> RGB LED.&nbsp; It is even labled “**RGB**”,&nbsp; and is soldered closed on most boards.&nbsp; 
> Note: on one of my **YD-ESP32-S3** clones,&nbsp; there is a capacitor soldered across this 
> solder-jumber.
>
> 2. The second solder-jumber,&nbsp; “**IN-OUT**”,&nbsp; is on the far Left side, just
> below the RGB LED.&nbsp; It is usually labled “**IN OUT**” or “**5VIN OUT**”.
>
> 3. The third solder-jumber,&nbsp; “**USB-OTG**”,&nbsp; is on the back of the board.

#### NOTES¹: ‘RGB’, ‘IN-OUT’, and ‘USB-OTG’ solder jumper pads

The ‘**IN-OUT**’ jumper, when closed, bypasses 1 diode, making USB VBus
power coming to 5Vin. If 5Vin is also connected to external source,
it can get back-fed by USB, which is usually undesirable. But this
USB bus is protected by another diode, it cannot get back-fed by
external source.

When ‘**IN-OUT**’ is open, 5Vin and USB VBus are separated by a diode, 
USB power does not come to 5Vin.

The ‘**USB-OTG**’ jumper, when closed, connects together USB VBus lines
from both USB-C connectors.

***REF:***&nbsp; Third-party ESP32-S3 development boards ‘IN-OUT’ and 
‘USB-OTG’ pads - What do they do?
https://www.reddit.com/r/esp32/comments/10rdngp/thirdparty_esp32s3_development_boards_inout_and/?rdt=39953

These solder-jumpers&nbsp; make the [VCC-GND.com](https://vcc-gnd.com/) **YD-ESP32-S3** and its’ 
clones easily recognizable,&nbsp; even when they are labled as &nbsp;_Espressif ESP32-S3-DevKitC-1_&nbsp;
or &nbsp;_ESP32-S3-WROOM-1 Dev_,&nbsp; or something else on sales sites. 

The **YD-ESP32-S3** and its’ clones are also quickly recognizable by the
four LEDs in a row across the Dev Board.&nbsp; On the Left is the larger
RGB LED (NeoPixel), followed by the Power (Red), TX (Green), then RX (Blue) LEDs.

Ususlly Only **YD-ESP32-S3**s' from [VCC-GND.com](https://vcc-gnd.com/)&nbsp; will have 
the **YD-ESP32-S3** markings on the back. Even though these are the least expensive of
these compatible Dev Boards, I have several, from several different vendors, and
they have always been of good quality and performed as expected.

[YD-ESP32-S3 ESP32-S3-WROOM-1 Dev](https://github.com/profharris/YD-ESP32-S3%20ESP32-S3-WROOM-1%20Dev/blob/main/Readme.md)

【2.】 

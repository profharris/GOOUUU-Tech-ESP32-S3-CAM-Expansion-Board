## How to identify the family of compatible ESP32-S3 Development Boards
<hr>

## GOOUUU Tech ESP32-S3-CAM Expansion Board

***A WORK IN PROGRESS*** &nbsp; &nbsp; Prof. Michael P. Harris &nbsp; &nbsp; *06/01/2025*<br/>
[GitHub Pages](https://pages.github.com/)

![GOOUUU-Tech ESP32-S3-CAM Expansion Board _Yellow_ & _Black_ headers](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%20Expansion%20Board-2.jpg)

As I've been working with the **GOOUUU Tech ESP32-S3-CAM Expansion Board**,&nbsp;
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

1. [Espressif ESP32-S3-DevKitC-1 44-pin pinout](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/ESP32-S3-DevKitC-1%2044-pins%20pinout.jpg)<br/>
2. [GOOUUU ESP32-S3-CAM 40-pin pinout](https://github.com/profharris/GOOUUU-Tech-ESP32-S3-CAM-Expansion-Board/blob/main/images/GOOUUU%20ESP32-S3-CAM%2040-pins%20pinout.png)


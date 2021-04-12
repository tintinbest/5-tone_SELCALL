# 5-tone_SELCALL
Library to generate SelCall tones (CCIR, ZVEI ...) with an arduino board

The library can generate 5 tone SelCAll tones for CCIR, ZVEI1, ZVEI2, ZVEI3 and EEA standards.

Simply create a "Fivetone" object {Fivetone NAMEOFTHEOBJECT (int PROTOCOL, int OUTPUTPIN);}

(1 : CCIR / 2 : ZVEI1 / 3 : ZVEI2 / 4 : ZVEI3 / 5:EEA)

To generate the tones, use the send5tone() function.

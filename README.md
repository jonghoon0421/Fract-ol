# Fract-ol
**To install:**
* `git clone https://github.com/jonghoon0421/Fract-ol.git`
* `make`

**To execute:**
* `Usage: ./fractol [parameter]`

  * `----------------------------PARAMETER---------------------------`
    * `[M] : Mandelbrot`
    * `[J] : Julia`
    * `[B] : Burning Ship`
    * `[T] : Tricorn`
    * `[N3] : Newton Method -- p(z) = z^3 - 1; a = 1`
    * `[N4] : Newton Method -- p(z) = z^4 - 1; a = 1`
    * `[WOC] : Newton Method -- p(z) = z^3 - 2*z - 2; a = 1`
    * `[WC] : Newton Method -- p(z) = z^8 + 15 * z^4 - 16; a = 1`
    * `[S] : Newton Method -- p(z) = sin(z); a = 1`
    
* `Event options`
  * `----------------------------KEYBOARD----------------------------`
    * `R : Reset current fractal`
    * `I, O : Increase / decrease max_iteration`
    * `D, F : Switch fractals (previous / next)`
    * `C : Switch color settings (continuous / discrete)`
    * `*Z, *X : Hold to start psychedelic effect (outward / inward)`
    * `ARROW KEYS : Move in 4 directions`
    * `+, - : Zoom in / out`
    * `**SPACE : Switch Julia behavior modes (static / dynamic)`
    * `ESC : Exit`
  * `------------------------------MOUSE-----------------------------`
    * `LEFT CLICK : Bring the position to the center of window`
    * `**MOTION : Change constant term to cursor position`
    * `WHEEL UP, DOWN : Zoom in / out, follows cursor position`
  * `----------------------------NUMBER PAD--------------------------`
    * `7, 8, 9 : Increase color frequency (R, G, B), respectively`
    * `4, 5, 6 : Decrease color frequency (R, G, B), respectively`
    * `*1 : Switch color arrangement or to black-n-gray scale`
    
* ` * : Only available in 'CONTINUOUS' color setting`
* `** : Only available in 'JULIA' fractal`

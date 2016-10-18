#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#include <stdint.h>
#include "board.h"

typedef struct { // Data stored PER GLYPH
  uint16_t bitmapOffset;     // Pointer into GFXfont->bitmap
  uint8_t  width, height;    // Bitmap dimensions in pixels
  uint8_t  xAdvance;         // Distance to advance cursor (x axis)
  int8_t   xOffset, yOffset; // Dist from cursor pos to UL corner
} GFXglyph;

typedef struct { // Data stored for FONT AS A WHOLE:
  uint8_t  *bitmap;      // Glyph bitmaps, concatenated
  GFXglyph *glyph;       // Glyph array
  uint8_t   first, last; // ASCII extents
  uint8_t   yAdvance;    // Newline distance (y axis)
} GFXfont;



// Display global variables encapsulated in struct
struct Adafruit_GFX_T{
  int16_t
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int16_t
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  uint16_t
    textcolor, textbgcolor;
  uint8_t
    textsize,
    rotation;
  bool
    wrap,   // If set, 'wrap' text at right edge of display
    _cp437; // If set, use correct CP437 charset (default is off)
  GFXfont
    *gfxFont;
};

// Pointer to an Adafruit_GFX ADT object
typedef struct Adafruit_GFX_T *Adafruit_GFXPtr_t;


// returns a pointer to ADT struct
Adafruit_GFXPtr_t Adafruit_GFX_Init(int16_t w, int16_t h); // Constructor

 void drawPixel(int16_t x, int16_t y, uint16_t color);

  //Text funtions
  void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
      uint16_t bg, uint8_t size);
  void setCursor(int16_t x, int16_t y);
  void setTextColor(uint16_t c);
  void setTextColorB(uint16_t c, uint16_t bg);
  void setTextSize(uint8_t s);
  void setTextWrap(bool w);
  void setRotation(uint8_t r);
  // void cp437(bool x=true);
  void cp437(bool x);
  // void setFont(const GFXfont *f = NULL);
  void setFont(const GFXfont *f );
  void getTextBounds(char *string, int16_t x, int16_t y,
	      int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);

  void write(uint8_t);


  int16_t height() ;
  int16_t width() ;

  uint8_t getRotation() ;

  // get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
  int16_t getCursorX() ;
  int16_t getCursorY() ;


 //  void fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
 // uint16_t color); 

 // void drawFastVLine(int16_t x, int16_t y,
 // int16_t h, uint16_t color);

 // void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
 // uint16_t color); 





#endif // _ADAFRUIT_GFX_H
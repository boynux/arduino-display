#ifndef _FONT_H
#define _FONT_H

#include <Arduino.h>

union FontData {
  uint64_t data;
  uint8_t line[7];
  uint8_t kerning;
};

class Font {
 public:
  Font() {}

  static void getFont(char c, FontData* font);
  static const FontData _font[];
};

#endif

#include "TextGrid.h"
#include "string.h"

TextGrid::TextGrid(const char *text):
  TextGrid(strlen(text) * 8, 8) {
  setText(text);
}

void TextGrid::setText(const char *text) {
  if(_text) {
    free(_text);
  }

  _text = (char *)malloc(strlen(text) * sizeof(char));
  strcpy(_text, text);
}

uint8_t* TextGrid::nextFrame() {
  int length = 0;
  
  for(unsigned int segment = 0; segment < strlen(_text); segment++) {
    uint64_t c = _TEXT_GRID_FONTS[_text[segment] - 0x20];

    // assuming each segment is 8 x 8
    for(int row = 0; row < 8; row++) {
      _buffer[segment * 8 + row] = (uint8_t)(c >> ((7 - row) * 8));
    }

    length += 8;

    if(length >= _width) {
      break;
    }
  }

  return _buffer;
}

void TextGrid::reset() {

}

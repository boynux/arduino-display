#include "TextGrid.h"
#include "string.h"

TextGrid::TextGrid(const char *text):
  TextGrid(strlen(text) * 8, 8) {
  setText(text);
}

TextGrid* TextGrid::instanceWithString(const char* text) {
  int length = 0;
  int str_len = strlen(text);
  Font font;

  for(int index = 0; index < str_len; ++index) {
    length += font.getFont(text[index]).kerning;
  }

  length += length % 8 > 0 ? length % 8 : 0;

  TextGrid* grid = new TextGrid(str_len * 8, 8);
  grid->setText(text);

  return grid;
}

void TextGrid::setText(const char *text) {
  if(_text) {
    free(_text);
  }

  _text = (char *)malloc(strlen(text) + 1);
  initialize();

  strcpy(_text, text);
}

uint8_t* TextGrid::nextFrame() {
  int  remaining = 8;
  uint8_t index = 0;
  uint8_t place = 0;
  uint8_t shift = 0;
  uint8_t row = 0;

  while(_text[place] != '\0') {
    const FontData &font = _font->getFont(_text[place]);

    if(shift == 0) {
      for(row = 0; row < 7; row++) {
	_buffer[index * 8 + row] |= (font.line[7 - row] << (8 - remaining));
      }
      remaining -= (font.kerning > 0 ? font.kerning : 8);
    } else {
      for(row = 0; row < 7; row++) {
	_buffer[index * 8 + row] |= font.line[7 - row] >> shift;
      }
      shift = 0;
    }

    if(remaining > 0) {
      place++;
      continue;
    }

    shift = remaining < 0 ? font.kerning + remaining : shift;

    if(remaining == 0)
      place++;

    remaining += 8;
    index++;

    if(index * 8 > width()) {
      break;
    }
  }
  return _buffer;
}

void TextGrid::reset() {

}

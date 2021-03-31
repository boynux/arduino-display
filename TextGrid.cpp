#include "TextGrid.h"
#include "string.h"

void TextGrid::setText(const char *text) {
  if(_text) {
    free(_text);
  }

  _text = malloc(strlen(text) * sizeof(char));
  strcpy(_text, text);
}

uint8_t* TextGrid::nextRow() {
  
}

void TextGrid::reset() {

}

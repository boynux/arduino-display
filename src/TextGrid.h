#ifndef _TEXT_GRID_H
#define _TEXT_GRID_H

#include "BaseGrid.h"
#include "Font.h"

#include "stdlib.h"
#include "string.h"

class TextGrid: public BaseGrid {
public:
  TextGrid(int width, int height)
    :BaseGrid(width, height) {

    initialize();
    _text = strdup("");
    _font = new Font();
  }

  TextGrid(const char *text);
  ~TextGrid() {
    delete[] _buffer;
    delete _text;
    delete _font;
  }

  void initialize()  __attribute__((always_inline)) {
    uint8_t size = width() * height() / 8 + 8;
    if(!_buffer) {
      // Allocate 8bit chunk of w * h + 1 byte for null-termoinator
      _buffer = new uint8_t[size];
    }

    memset(_buffer, 0, size);
  }

  void setText(const char *text);
  static TextGrid *instanceWithString(const char *text);

  uint8_t* nextFrame() override;
  void reset() override;
  
private:
  static const int MaxRows = 8;
  static const int NumModules = 4;
  static const int ColsPerModule = 8;
  static const int MaxCols = TextGrid::ColsPerModule * TextGrid::NumModules;

  uint8_t* _buffer = 0;
  char* _text;
  const Font* _font;
};

#endif

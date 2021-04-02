#include "ScrollDecorator.h"

ScrollDecorator::ScrollDecorator(int width, int height, BaseGrid *grid):
  BaseDecorator(width, height, grid) {

  _buffer = new uint8_t[width * height / 8](0);
  _index = 0;
}


union Data {
  uint64_t data;
  uint8_t parts[sizeof(uint64_t)];
};


void ScrollDecorator::scrollText(int width, int height, int offset, const uint8_t *buffer, uint8_t *out) {
  for(unsigned int i = 0; i < height; i++) {
    union Data data;
    for(unsigned int j = 0; j < width / 8 + 1; j++) {
      data.parts[j] = buffer[i + j * 8];
    }

    data.data >>= offset;
    for(unsigned int j = 0; j < width / 8; j++) {
      out[i + j * 8] = data.parts[j];
    }
  }
}

uint8_t *ScrollDecorator::nextFrame() {
  if(_index + width() < _grid->width()) {
    uint8_t* buffer = _grid->nextFrame();

    scrollText(width(), height(), _index % 8, _grid->nextFrame() + _index / 8 * 8, _buffer);
    _index ++;
  }

  return _buffer;
}

void ScrollDecorator::reset(){
  _index = 0;
}
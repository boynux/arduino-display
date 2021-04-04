#include "ScrollDecorator.h"

ScrollDecorator::ScrollDecorator(int width, int height, BaseGrid *grid):
  BaseDecorator(width, height, grid) {

  _buffer = new uint8_t[width * height / 8];
  _index = 0;
}

void ScrollDecorator::scrollText(int width, int height, int offset, const uint8_t *nextFrame, uint8_t *out) {
  for(int i = 0; i < height; i++) {
    union Data data;
    for(int j = 0; j < width / 8; j++) {
      data.parts[j] = out[i + j * 8];
    }

    data.parts[width / 8] = nextFrame[i] >> offset % 8;
    data.data >>= 1;
    for(int j = 0; j < width / 8; j++) {
      out[i + j * 8] = data.parts[j];
    }
  }
}

uint8_t *ScrollDecorator::nextFrame() {
    uint8_t* buffer = _grid->nextFrame();
    scrollText(width(), height(), _index, buffer + _index / 8 * 8, _buffer);
    _index = (_index + 1) % _grid->width();
    return _buffer;
}

void ScrollDecorator::reset(){
  _index = 0;
}

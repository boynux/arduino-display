#ifndef _BASE_GRID_H
#define _BASE_GRID_H

#include <stdint.h>

class BaseGrid {
public:
  BaseGrid(int width, int hieght);
  BaseGrid(): BaseGrid(8, 8) {}
  
  virtual void reset() = 0;
  // Returns a 2d array of row x cols x 8 bit
  virtual uint8_t *nextFrame() = 0;

  int width() __attribute__((always_inline)) {
    return _width;
  }
  int height() __attribute__((always_inline)) {
    return _height;
  }
  
protected:
  int _width, _height;
};

#endif

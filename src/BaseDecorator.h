#ifndef _BASE_DECORATOR_H
#define _BASE_DECORATOR_H

#include "BaseGrid.h"

class BaseDecorator:
public BaseGrid {
 public:
 BaseDecorator(int width, int height, BaseGrid *grid):
  BaseGrid(width, height), _grid(grid) {}

 protected:
  BaseGrid *_grid;
};

#endif

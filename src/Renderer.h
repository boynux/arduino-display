#ifndef _RENDERER_H
#define _RENDERER_H

#include "BaseGrid.h"
#include <LedControl.h>

class Renderer {
public:
  Renderer(LedControl *control, BaseGrid *grid):
    _grid(grid), _control(control) {}

  void render();

private:
  BaseGrid *_grid;
  LedControl *_control;
};

#endif

#include "Renderer.h"

void Renderer::render() {
  uint8_t *buffer = _grid->nextFrame();

  if (buffer == 0) {
    _grid->reset();
    buffer = _grid->nextFrame();
  }
  
  for(int i = 0; i < _grid->height(); i++) {
    for(int j = 0; j < _grid->width() / 8; j++) {
      _control->setRow(j, i, buffer[i + j * 8]);
    }
  }
}

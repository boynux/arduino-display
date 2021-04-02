#ifndef _SCROLL_DECORATOR_H
#define _SCROLL_DECORATOR_H

#include "BaseDecorator.h"

class ScrollDecorator: public BaseDecorator {
 public:
  ScrollDecorator(int width, int height, BaseGrid *grid);

  uint8_t* nextFrame() override;
  void reset() override;

 private:
  void scrollText(int, int, int, const uint8_t*, uint8_t*);
  uint8_t* _buffer;
  unsigned int _index;
};

class EndOfBufferException {};

#endif

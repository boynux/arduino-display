#include <LedControl.h>

#include "src/Display.h"

#define NUM_MODULES 4

LedControl lc = LedControl(11, 13, 4, 4);
Renderer *renderer;
BaseGrid *grid;

void setup() {
  for(int add = 0; add < NUM_MODULES; add++) {
    // the zero refers to the MAX7219 number, it is zero for 1 chip
    lc.shutdown(add, false);// turn off power saving, enables display
    lc.setIntensity(add, 1);// sets brightness (0~15 possible values)
    lc.clearDisplay(add);// clear screen
  }

	const char text[] = "Hello world!  ";
	
	grid = new ScrollDecorator(32, 8, new TextGrid(text));
	renderer = new Renderer(&lc, grid);
}

void loop() {
	renderer->render();

  delay(100);
}


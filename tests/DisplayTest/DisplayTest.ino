#include <AUnit.h>
#include <stdlib.h>
#include <Display.h>

#define TEST_GRID(NAME, FUNC, ARG, ...) test(NAME) { \
  const uint8_t e[] = __VA_ARGS__;       \
	uint8_t b[8];                          \
  FUNC(#ARG, b);		         						 \
	for(unsigned int i = 0; i < 8; i++) {  \
		assertEqual(b[i], e[i]);         \
  }                                      \
}
	
using namespace aunit;

void setup() {
  Serial.begin(115200);
  while (! Serial); // Wait until Serial is ready - Leonardo/Micro
}

void loop() {
  TestRunner::run();
}

void textFrame(const char *text, uint8_t *b) {
  TextGrid grid = TextGrid(8, 8);
  grid.setText(text);

  memcpy(b, grid.nextFrame(), 8);
}

TEST_GRID(TextGridA, textFrame, A, {
		0B00000000,
		0B00111100,
		0B01100110,
		0B01100110,
		0B01111110,
		0B01100110,
		0B01100110,
		0B01100110
})

TEST_GRID(TextGridX, textFrame, X, {
		0B00000000,
		0B11000110,
		0B11000110,
		0B01101100,
		0B00111000,
		0B01101100,
		0B11000110,
		0B11000110
})


TEST_GRID(TextGridE, textFrame, E, {
		0B00000000,
		0B01111110,
		0B00000110,
		0B00000110,
		0B00111110,
		0B00000110,
		0B00000110,
		0B01111110
})

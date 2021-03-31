#include <LedControl.h>

#include "Renderer.h"
#include "TextGrid.h"

/*

 */
const uint64_t IMAGES[] = {
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0001017F7F110100, // 0
  0x0031794945672300, // 1
  0x00367F4949632200, // 2
  0x00047F7F24140C00, // 3
  0x004E5F5151737200, // 4
  0x00266F49497F3E00, // 5
  0x0060785F47606000, // 6
  0x00367F49497F3600, // 7
  0x003E7F49497B3200, // 8
  0x003E7F51497F3E00, // 9
  0x0000003636000000, // :
  0x0000003637010000, // ;
  0x004163361C080000, // <
  0x0000141414140000, // =
  0x0000081C36634100, // >
  0x0030784D4D602000, // ?
  0x0004325A5A423C00, // @
  0x003F7F48487F3F00, // A
  0x00367F49497F7F00, // B
  0x00226341417F3E00, // C
  0x003E7F41417F7F00, // D
  0x00414949497F7F00, // E
  0x00404848487F7F00, // F
  0x00266745417F3E00, // G
  0x007F7F08087F7F00, // H
  0x0000417F7F410000, // I
  0x00407E7F41070600, // J
  0x004163361C7F7F00, // K
  0x00010101017F7F00, // L
  0x7F7F3018307F7F00, // M
  0x7F7F0C18307F7F00, // N
  0x003E7F41417F3E00, // O
  0x00387C44447F7F00, // P
  0x003D7F46427E3C00, // Q
  0x00317B4E4C7F7F00, // R
  0x00266F49497B3200, // S
  0x0060407F7F406000, // T
  0x007F7F01017F7E00, // U
  0x007C7E03037E7C00, // V
  0x7F7F060C067F7F00, // W
  0x63771C081C776300, // X
  0x0070780F0F787000, // Y
  0x006171594D474300, // Z
  0x0041417F7F000000, // [
  0x0002060C18302000, // \
  0x0000007F7F414100, // ]
  0x0810204020100800, // ^
  0x0002020202020200, // _
  0x0010706000000000, // `
  0x000F1F1515170200, // a
  0x00060F09097F7F00, // b
  0x000A1B11111F0E00, // c
  0x007F7F09090F0600, // d
  0x000C1D15151F0E00, // e
  0x002064447F3F0400, // f
  0x003E3F25253D1800, // g
  0x00070F08087F7F00, // h
  0x0000012F2F010000, // i
  0x00005E5F01070600, // j
  0x00111B0E047F7F00, // k
  0x0000007F7F000000, // l
  0x1F1F0C070C1F1F00, // m
  0x000F1F18181F1F00, // n
  0x000E1F11111F0E00, // o
  0x00183C24243F3F00, // p
  0x03013F3F243C1800, // q
  0x000C1C10101F1F00, // r
  0x0012151515150900, // s
  0x0008083F3F080800, // t
  0x001F1F01011F1E00, // u
  0x000C0E03030E0C00, // v
  0x1E1F010F011F1E00, // w
  0x00111B0E0E1B1100, // x
  0x001E1F05051D1800, // y
  0x0000191D17130000, // z
  0x004141773E080000, // {
  0x0000007E7E000000, // |
  0x0000083E77414100, // }
  0x0010081810180800, // ~
};
const int IMAGES_LEN = sizeof(IMAGES)/8;

const int MAX_ROWS = 8;
const int NUM_MODULES = 4;
const int COLS_PER_MODULE = 8;
const int MAX_COLS = COLS_PER_MODULE * NUM_MODULES;

uint64_t buffer[MAX_ROWS] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
};

LedControl lc = LedControl(11, 13, 4, 4);

void setup() {
  for(int add = 0; add < NUM_MODULES; add++) {
    // the zero refers to the MAX7219 number, it is zero for 1 chip
    lc.shutdown(add, false);// turn off power saving, enables display
    lc.setIntensity(add, 1);// sets brightness (0~15 possible values)
    lc.clearDisplay(add);// clear screen
  }
}

void drawChar(int module, uint64_t c) {
  for (int row = 0; row < MAX_ROWS; row++) {
    byte _bit = (c >> row * 8) & 0xFF;
    for (int col = 0; col < COLS_PER_MODULE; col++) {
      lc.setLed(module, row, col, bitRead(_bit, col)); // turns on LED at col, row
    }
  }
}

void displayBuffer() {
  for(int row = 0; row < 8; row++) {
    uint64_t slice = buffer[row];

    for(int mod = 0; mod < 4; mod++) {
      lc.setRow(mod, row, slice);
      slice >>= 8;
    }
  }
}

/*
void appendBuffer(int col) {
 byte mask = 0x01;
 for(int i = 0; i < 8; i++) {
 unsigned long b = buffer[i];
 
 b <<= 1;
 buffer[i] = b | (col & mask);
 col >>= 1;
 } 
 }
 */

void appendBuffer(int col) {
  byte mask = 0x01;
  for(int i = 0; i < 8; i++) {
    uint64_t b = buffer[i];

    b >>= 1;
    uint64_t n = (uint64_t)(col & mask) << 63;
    buffer[i] = b | n;
    col >>= 1;
  } 
}

void scrollText(char *string) {
  for(int i = 0; i < strlen(string); i++) {
    uint64_t c = IMAGES[string[i] - 0x20];

    for(int col = 0; col < 8; col++) {
      appendBuffer(c & 0xFF);
      displayBuffer();
      c >>= 8;
      delay(100);

    }
  }
}

void loop() {
  /*
  for (int col = 0; col < MAX_COLS; col++) {
   for (int row = 0; row < MAX_ROWS; row++) {
   lc.setLed(NUM_MODULES - col / COLS_PER_MODULE - 1, row, col % COLS_PER_MODULE, true); // turns on LED at col, row
   delay(25);
   }
   }
   for (int col = MAX_COLS; col >= 0; col--) {
   for (int row = 0; row < MAX_ROWS; row++) {
   lc.setLed(NUM_MODULES - col / COLS_PER_MODULE - 1, row, col % COLS_PER_MODULE, false); // turns off LED at col, row
   delay(25);
   }
   }
   */
  /*
  for(int i = 0; i < MAX_COLS; i++) {
   appendBuffer(0x1F);
   displayBuffer();
   delay(100);
   }
   */
  scrollText("ABCDEFGH");
  delay(100);
  // drawChar(3, IMAGES[0]);
  // drawChar(2, IMAGES[1]);
  // drawChar(1, IMAGES[2]);
  // drawChar(0, IMAGES[3]);

  delay(100);
}


#include "Control.h"
#include <string.h>
#include <Arduino.h>

Control::Control(uint8_t rx, uint8_t tx)
  :serial(rx, tx) {
}

void Control::init(long buadRate) {
  serial.begin(Control::BaudRate);
}

void Control::readBuffer(int size, char* buffer) {
  for(short i = 0; i < size; i++) {
    buffer[i] = serial.read();
  }

  buffer[size] = '\0';
}

void Control::next(void (callback) (const char *)) {
  long r = serial.available();

  if(r == 0) {
    callback(0);
    return;
  }
  
  char *buffer = new char[r + 1];
  readBuffer(r, buffer);

  const char* key = "TEXT:";
  if (strncasecmp(buffer, key, strlen(key)) == 0) {
    callback(buffer + strlen(key));
  }
  delete[] buffer;
}

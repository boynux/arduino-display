#ifndef _CONTROL_H
#define _CONTROL_H

#include <stdlib.h>
#include <SoftwareSerial.h>

class Control {
 public:
  Control(uint8_t rx, uint8_t tx);

  void init(long baudRate = Control::BaudRate);
  void next(void (callback) (const char *));
  
 private:
  void readBuffer(int size, char* buffer);
  
  static const long BaudRate = 9600;
  SoftwareSerial serial;
  bool NL = true;
};

#endif

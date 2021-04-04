#include <LedControl.h>
#include <DS3231.h>
#include <Wire.h>
#include <BMP180I2C.h>
#include <Adafruit_BMP085.h>

#include "src/Display.h"

#define NUM_MODULES 4
#define CLK 11
#define DIN 13
#define CS 12
#define I2C_ADDRESS 0x77

Adafruit_BMP085 bmp;
BMP180I2C bmp180(I2C_ADDRESS);
DS3231 clock;

LedControl lc = LedControl(DIN, CLK, CS, NUM_MODULES);
Renderer *renderer;
TextGrid *textGrid;

bool century = false;
bool h12Flag;
bool pmFlag;

char text[32] = {0};

void getTemprature(char *temp) {
	char str_temp[6];
	float t = bmp.readTemperature();
	dtostrf(t, 4, 2, str_temp);

	sprintf(temp, "%sC", str_temp);
}

void getStringDate(char *date) {
	bool h12, pm;
	sprintf(date, "%02d:%02d", clock.getHour(h12, pm), clock.getMinute());
}

void getString(char *string) {
	char time[16], temp[16];

	getTemprature(temp);
	getStringDate(time);

	sprintf(string, "%s | %s ", time, temp);
}

void setup() {
	// Start the serial port
	Serial.begin(57600);

	// Start the I2C interface
	Wire.begin();

	if (!bmp.begin()) {
		Serial.println("Could not find a valid BMP085 sensor, check wiring!");
		while (1) {}
  }

	clock.setClockMode(false);	// set to 24h

  for(int add = 0; add < NUM_MODULES; add++) {
    // the zero refers to the MAX7219 number, it is zero for 1 chip
    lc.shutdown(add, false);// turn off power saving, enables display
    lc.setIntensity(add, 1);// sets brightness (0~15 possible values)
    lc.clearDisplay(add);// clear screen
  }

	// const char text[] = "Hello world!";
	// textGrid = new TextGrid(text);
	getString(text);
	textGrid = TextGrid::instanceWithString(text);
	
	BaseGrid *grid = new ScrollDecorator(32, 8, textGrid);
	renderer = new Renderer(&lc, grid);
}

void loop() {
	renderer->render();
	getString(text);
	textGrid->setText(text);

  delay(30);
}

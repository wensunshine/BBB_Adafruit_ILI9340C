#ifndef ADAFRUIT_BB_GPIO_H_
#define ADAFRUIT_BB_GPIO_H_

#include "SimpleGPIO.h"
#include <stdint.h>

#define OUTPUT 1
#define INPUT 0
#define LOW 0
#define HIGH 1

uint8_t digitalWrite(uint8_t port, PIN_VALUE value);  
uint8_t pinMode(uint8_t port, PIN_DIRECTION out_flag);  

uint8_t delay(uint16_t mS);

#endif /* Adafruit_BB_GPIO */

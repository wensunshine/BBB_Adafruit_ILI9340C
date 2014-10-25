#ifndef ADAFRUIT_BB_GPIO_H_
#define ADAFRUIT_BB_GPIO_H_

#include "SimpleGPIO.h"
#include <stdint.h>


uint8_t digitalWrite(uint8_t port, PIN_VALUE value);  
uint8_t pinMode(uint8_t port, PIN_DIRECTION out_flag);  

uint8_t delay(uint16_t mS);

#endif /* Adafruit_BB_GPIO */

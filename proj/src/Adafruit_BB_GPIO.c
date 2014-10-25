#include <stdint.h> 
#include "Adafruit_BB_GPIO.h"
#include <unistd.h>

uint8_t digitalWrite(uint8_t gpio, PIN_VALUE value)  
{
return  (uint8_t) gpio_set_value(gpio, value);
}

uint8_t pinMode(uint8_t gpio, PIN_DIRECTION out_flag)
{
return (uint8_t) gpio_set_dir(gpio, out_flag);
}
  
uint8_t delay(uint16_t mS)
{
return (uint8_t) usleep(mS*1000);
}

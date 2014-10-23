#include<stdint.h>
int initSpi();

void spiTransferByte(int fd,uint8_t data);

int closeSpi(int fd); 

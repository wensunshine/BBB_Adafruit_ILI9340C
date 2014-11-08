#include<stdint.h>

int initSpi();
void spiwrite(uint16_t data);
void spiTransferBurst(int fd,uint8_t *data,int length);

void spiTransferByte(int fd,uint8_t data);

void transfer(int fd);

int closeSpi(int fd); 

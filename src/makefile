CC=gcc
CFLAGS=-I.
DEPS = spi.h
OBJ = spi.o  

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

spi: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


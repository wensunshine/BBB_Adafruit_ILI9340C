IDIR =../include
CC=gcc
CXX=g++
CFLAGS=-I$(IDIR)
CXXFLAGS=-Wall
ODIR=obj
LDIR =../lib


LIBS=-lm



_DEPS = spi.h Adafruit_ILI9340.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = spi.o #Adafruit_ILI9340.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)
	 $(CXX) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

spi: $(OBJ)
#	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS) $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

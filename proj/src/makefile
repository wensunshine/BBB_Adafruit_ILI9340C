IDIR =../include
CC=gcc
CXX=g++
CFLAGS=-I$(IDIR)
CXXFLAGS=-Wall
ODIR=obj
LDIR =../lib


LIBS=-lm



_DEPS = spi.h Adafruit_ILI9340.h Adafruit_GFX.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = graphicstest.o  spi.o Adafruit_ILI9340.o Adafruit_GFX.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)
	 $(CXX) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

test: $(OBJ)
#	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS) $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

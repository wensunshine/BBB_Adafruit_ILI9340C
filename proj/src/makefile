IDIR =../include
CC=gcc
CXX=g++
CFLAGS=-I$(IDIR)
CXXFLAGS=-Wall
ODIR=obj
LDIR =../lib


LIBS=-lm

#g++ -o graphicstest graphicstest.cpp Adafruit_ILI9340.cpp Adafruit_GFX.cpp spi.c glcdfont.c -I../include

_DEPS = spi.h Adafruit_ILI9340.h Adafruit_GFX.h SimpleGPIO.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = graphicstest.o  spi.o Adafruit_ILI9340.o Adafruit_GFX.o glcdfont.o SimpleGPIO.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)
	 $(CXX) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

test.out: $(OBJ)
#	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS) $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
		 

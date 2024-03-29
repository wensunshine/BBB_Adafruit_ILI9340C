/***************************************************
  This is an example sketch for the Adafruit 2.2" SPI display.
  This library works with the Adafruit 2.2" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/1480
 
  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/
 
#include "spi.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"
#include "Adafruit_BB_GPIO.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

// These are the pins used for the UNO
// for Due/Mega/Leonardo use the hardware SPI pins (which are different)
#define _sclk 30 
#define _miso 31
#define _mosi 48
#define _cs 51
#define _dc 60
#define _rst 50

// Using software SPI is really not suggested, its incredibly slow
//Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _mosi, _sclk, _rst, _miso);
// Use hardware SPI
Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _rst);

int min(int a, int b)
{
if (a < b) return a;
else return b;
}


unsigned long testFillScreen() {
//  unsigned long start = micros();

  tft.fillScreen(ILI9340_BLACK);
  delay(500);
  tft.fillScreen(ILI9340_RED);
  delay(500);
  tft.fillScreen(ILI9340_GREEN);
  delay(500);
  tft.fillScreen(ILI9340_BLUE);
  delay(500);
  tft.fillScreen(ILI9340_BLACK);
  return 0;//micros() - start;
}
unsigned long testText() {
  tft.fillScreen(ILI9340_BLACK);
  //unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9340_WHITE);  tft.setTextSize(1);
  //tft.println("Hello World!");
  tft.setTextColor(ILI9340_YELLOW); tft.setTextSize(2);
//  tft.println(1234.56);
  tft.setTextColor(ILI9340_RED);    tft.setTextSize(3);
//  tft.println(0xDEADBEEF, HEX);
//  tft.println();
  tft.setTextColor(ILI9340_GREEN);
  tft.setTextSize(5);
//  tft.println("Groop");
  tft.setTextSize(2);
//  tft.println("I implore thee,");
  tft.setTextSize(1);
/*  tft.println("my foonting turlingdromes.");
  tft.println("And hooptiously drangle me");
  tft.println("with crinkly bindlewurdles,");
  tft.println("Or I will rend thee");
  tft.println("in the gobberwarts");
  tft.println("with my blurglecruncheon,");
  tft.println("see if I don't!");*/
  return 0;//micros() - start;
}
void loop(void) {
  for(uint8_t rotation=0; rotation<4; rotation++) {
    tft.setRotation(rotation);
    testText();
    delay(2000);
  }
}
unsigned long testLines(uint16_t color) {
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = tft.width(),
                h = tft.height();

  tft.clearBuffer();
  tft.fillScreen(ILI9340_BLACK);

  x1 = y1 = 0;
  y2    = h - 1;
  //start = micros();
  for(x2=0; x2<w; x2+=6) {tft.drawLine(x1, y1, x2, y2, color);
  tft.fillBufferScreen();}

  x2    = w - 1;
 for(y2=0; y2<h; y2+=6) {tft.drawLine(x1, y1, x2, y2, color);
  tft.fillBufferScreen();}
  delay(200);
  //t     = micros() - start; // fillScreen doesn't count against timing

  tft.fillScreen(ILI9340_BLACK);


  tft.clearBuffer();
  x1    = w - 1;
  y1    = 0;
  y2    = h - 1;
  //start = micros();
  for(x2=0; x2<w; x2+=6) {tft.drawLine(x1, y1, x2, y2, color);

  tft.fillBufferScreen();}

  x2    = 0;
  for(y2=0; y2<h; y2+=6) {tft.drawLine(x1, y1, x2, y2, color);
  //t    += micros() - start;

  tft.fillBufferScreen();}

  delay(200);


  tft.fillScreen(ILI9340_BLACK);

  tft.clearBuffer();
  x1    = 0;
  y1    = h - 1;
  y2    = 0;
  //start = micros();
  for(x2=0; x2<w; x2+=6) {tft.drawLine(x1, y1, x2, y2, color);
  tft.fillBufferScreen();}
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) {tft.drawLine(x1, y1, x2, y2, color);
  
  tft.fillBufferScreen();}
  //t    += micros() - start;
  delay(200);
  tft.fillScreen(ILI9340_BLACK);

  tft.clearBuffer();
  x1    = w - 1;
  y1    = h - 1;
  y2    = 0;
  //start = micros();
  for(x2=0; x2<w; x2+=6) {tft.drawLine(x1, y1, x2, y2, color);
  tft.fillBufferScreen();}
  delay(200);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) {tft.drawLine(x1, y1, x2, y2, color);
  tft.fillBufferScreen();}
  
  return 0;//micros() - start;
}

unsigned long testFastLines(uint16_t color1, uint16_t color2) {
  unsigned long start;
  int           x, y, w = tft.width(), h = tft.height();

  tft.fillScreen(ILI9340_BLACK);
  tft.clearBuffer();
  //start = micros();
  for(y=0; y<h; y+=5) {tft.drawFastHLine(0, y, w, color1);
  tft.fillBufferScreen();}
  for(x=0; x<w; x+=5) {tft.drawFastVLine(x, 0, h, color2);
  tft.fillBufferScreen();}
  return 0;//micros() - start;
}

unsigned long testRects(uint16_t color) {
  unsigned long start;
  int           n, i, i2,
                cx = tft.width()  / 2,
                cy = tft.height() / 2;

  tft.fillScreen(ILI9340_BLACK);
  n     = min(tft.width(), tft.height());
  //start = micros();
  printf("%d - \n",n);
  tft.clearBuffer();

for(i=2; i<n; i+=6) {
    i2 = i / 2;
    tft.drawRect(cx-i2, cy-i2, i, i, color);
   tft.fillBufferScreen(); 
  }

  return 0;//micros() - start;
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;
//  tft.fillScreen(ILI9340_BLACK);
  n = min(tft.width(), tft.height());
  tft.clearBuffer();
  for(i=n; i>0; i-=6) {
    i2    = i / 2;
    //start = micros();
    tft.fillRect(cx-i2, cy-i2, i, i, color1);

    //t    += micros() - start;
    // Outlines are not included in timing results
    tft.drawRect(cx-i2, cy-i2, i, i, color2);
    tft.fillBufferScreen();
  }

  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = tft.width(), h = tft.height(), r2 = radius * 2;

  tft.fillScreen(ILI9340_BLACK);
  //start = micros();
  tft.clearBuffer();
  for(x=radius; x<w; x+=r2) {
    for(y=radius; y<h; y+=r2) {
      tft.fillCircle(x, y, radius, color);
    }

     tft.fillBufferScreen();
  }

  return 0;//micros() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x, y, r2 = radius * 2,
                w = tft.width()  + radius,
                h = tft.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
//  start = micros();
  for(x=0; x<w; x+=r2) {
    for(y=0; y<h; y+=r2) {
      tft.drawCircle(x, y, radius, color);
    }
	tft.fillBufferScreen();
  }

  return 0;//micros() - start;
}

unsigned long testTriangles() {
  unsigned long start;
  int           n, i, cx = tft.width()  / 2 - 1,
                      cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9340_BLACK);
  n     = min(cx, cy);
//  start = micros();
tft.clearBuffer();
  for(i=0; i<n; i+=5) {
    tft.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      tft.Color565(0, 0, i));
     tft.fillBufferScreen();
  }

  return 0;//micros() - start;
}

unsigned long testFilledTriangles() {
  unsigned long start, t = 0;
  int           i, cx = tft.width()  / 2 - 1,
                   cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9340_BLACK);
//  start = micros();
  tft.clearBuffer();
  for(i=min(cx,cy); i>10; i-=5) {
    //start = micros();
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.Color565(0, i, i));
  //  t += micros() - start;
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.Color565(i, i, 0));
	tft.fillBufferScreen();
  }

  return t;
}

unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9340_BLACK);

  tft.clearBuffer();
  w     = min(tft.width(), tft.height());
//  start = micros();
  for(i=0; i<w; i+=6) {
    i2 = i / 2;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.Color565(i, 0, 0));
   tft.fillBufferScreen();
  }

  return 0;//micros() - start;
}

unsigned long testFilledRoundRects() {
  unsigned long start;
  int           i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

 tft.fillScreen(ILI9340_BLACK);
//  start = micros();
  tft.clearBuffer();
  for(i=min(tft.width(), tft.height()); i>20; i-=6) {
    i2 = i / 2;
    tft.fillRoundRect(cx-i2, cy-i2, i, i, i/8, tft.Color565(0, i, 0));
 tft.fillBufferScreen();  
  }

  return 0;//micros() - start;
} 

int main() {
  
  printf("Adafruit 2.2\" SPI TFT Test!"); 
  tft.begin();

//  tft.invertDisplay(1); 
  printf("Benchmark                Time (microseconds)");
  printf("Screen fill              ");
  (testFillScreen());
 // delay(500);
  printf("Text                     ");
 // (testText());
//  delay(3000);
//  getchar();
  printf("Lines                    ");
  (testLines(ILI9340_GREEN));
  delay(500);

//  getchar();
  printf("Horiz/Vert Lines         ");
  (testFastLines(ILI9340_RED, ILI9340_BLUE));
  delay(500);
//  getchar();

  printf("Rectangles (outline)     ");
  (testRects(ILI9340_GREEN));
  delay(500);

  printf("Rectangles (filled)      ");
 (testFilledRects(ILI9340_YELLOW, ILI9340_MAGENTA));
  delay(500);
  printf("Circles (filled)         ");
  (testFilledCircles(10, ILI9340_MAGENTA));
  printf("Circles (outline)        ");
  (testCircles(10, ILI9340_WHITE));

  printf("Triangles (outline)      ");
  (testTriangles());

  printf("Triangles (filled)       ");
  (testFilledTriangles());
  
printf("Rounded rects (outline)  ");
  (testRoundRects());
  
printf("Rounded rects (filled)   ");
  (testFilledRoundRects());

  printf("Done!");
getchar();
return 0;
}

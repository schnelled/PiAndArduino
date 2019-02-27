#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Define the pins to be used
#define TFT_CS    10
#define TFT_RST   9
#define TFT_DC    8

// Define colors
#define BLACK     0x0000
#define RED       0xF800
#define ORANGE    0xFD20
#define YELLOW    0xFFE0
#define GREEN     0x0400
#define BLUE      0x001F
#define INDIGO    0x4810
#define VIOLET    0xEC1D

// Initialize 1.44" TFT with ST7735 object
// Adafruit_ST7735(int8_t cs, int8_t dc, int8_t rst)
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


void setup(void) {
  // Setup serial baud rate
  Serial.begin(9600);
  
  // Initialize ST7735 chip
  // INITR_144GREENTAB = 0x01
  tft.initR(INITR_144GREENTAB);
  
  // Black the backscreen
  tft.fillScreen(BLACK);
}

void loop(void) {
  // Initialize the step values
  uint16_t blue = 0x0001;   // 0000 0000 0000 0001
  uint16_t green = 0x0020;  // 0000 0000 0010 0000
  uint16_t red = 0x0800;    // 0000 1000 0000 0000
  
  // Initialize the color value
  uint16_t color = 0x0000;
  
  // Loop through the blue colors
  for(color = blue; color < green; color = color + blue) {
   tft.fillScreen(color);
   tft.setCursor(55, 64);
   tft.setTextColor(BLACK);
   tft.print("Blue");
  }
  // Black the screen & delay for 1/4 second
  tft.fillScreen(BLACK);
  delay(250);
  
  //Loop through the green colors
  for(color = green; color < red; color = color + green) {
    tft.fillScreen(color);
    tft.setCursor(50, 64);
    tft.setTextColor(BLACK);
    tft.print("Green");
  }
  // Black the screen & delay for 1/4 second
  tft.fillScreen(BLACK);
  delay(250);
  
  // Loop through the red colors
  for(color = red; color > blue; color = color + red) {
   tft.fillScreen(color);
   tft.setCursor(55, 64);
   tft.setTextColor(BLACK);
   tft.print("Red");
  }
  // Black the screen & delay for 1/4 second
  tft.fillScreen(BLACK);
  delay(250);
  
  // Loop through the rainbow colors
  tft.fillScreen(RED);
  delay(500);
  tft.fillScreen(ORANGE);
  delay(500);
  tft.fillScreen(YELLOW);
  delay(500);
  tft.fillScreen(GREEN);
  delay(500);
  tft.fillScreen(BLUE);
  delay(500);
  tft.fillScreen(INDIGO);
  delay(500);
  tft.fillScreen(VIOLET);
  delay(500);
}



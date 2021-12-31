
# Gameduino

This is a project that we have done to help other peoples who want to make a similar project.


## Roadmap

- Component design

- Code

- Tinkering all the components

## Libraries

- Graphic library : https://github.com/adafruit/Adafruit-GFX-Library

- Serial Peripheral Interface : https://github.com/arduino/ArduinoCore-avr/blob/master/libraries/SPI/src/SPI.h

- Inter-Integrated Circuit : https://github.com/rambo/I2C

- Display Library : https://www.arduino.cc/reference/en/libraries/adafruit-ssd1306/

## Helpful Resources

- Oled Display Tutorial : https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/


## Screenshots

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)


## Usage/Examples

- SPI Display setup

``` wiring
// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   4 //D1
#define OLED_CLK   3  //D0
#define OLED_DC    6  
#define OLED_CS    7
#define OLED_RESET 5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
```

- I2C Display setup
``` wiring
// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128	
#define SCREEN_HEIGHT 64	
#define OLED_RESET 4		 - if your screen has no reset pin, you have to change that value to -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  
          }
```

- Screening Hello World on I2C display
``` wiring
// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128	
#define SCREEN_HEIGHT 64	
#define OLED_RESET 4		 - if your screen has no reset pin, you have to change that value to -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.println("Hello World");
  display.display();
 
          }
```



 

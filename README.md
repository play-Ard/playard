
# **PLAYARD**

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
- Deploying Flask Application to Heroku : https://stackabuse.com/deploying-a-flask-application-to-heroku/


## Screenshots

![Screenshot](images/i2c-hello-world.png)

## Usage/Examples

- ### SPI Display setup

``` cpp
// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   4 //D1
#define OLED_CLK   3  //D0
#define OLED_DC    6  
#define OLED_CS    7
#define OLED_RESET 5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
```

- ### I2C Display setup
``` cpp
// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128	
#define SCREEN_HEIGHT 64	
#define OLED_RESET 4 // if your screen has no reset pin, that value must be -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  
}
```

- ### Displaying 'Hello World' on I2C display
``` cpp
// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128	
#define SCREEN_HEIGHT 64	
#define OLED_RESET 4 // if your screen has no reset pin, that value must be -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.println("Hello World");
  display.display();
 
}
```

- ### SD Card Write - Read and Random Selection code Example
``` cpp
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  
#define OLED_RESET -1 //- if your screen has no reset pin, you have to change that value to -1

const long serialPort = 9600;
int xPin = A0; 
int yPin = A1; 
int buttonPin = 2; 

int xPosition;
int yPosition;
int buttonFlag;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

// Two dimensional list to hold questions
// Maybe can be converted into HashMaps to categorize topics
const int nRows = 4;
const int nColumns = 2;
const char *Questions[ rows ][ columns ] = { 
  {'Where is the capital of Turkey?', 'How many legs do chickens have?'},
  {'Father of Python?', 'Which is the moon of jupyter?'},
  {'Which one is the default seperator for CSV files?', 'R or Python? :D'},
  {'Full name of HP?', 'How old was Alan Turing when he died?'},
};

// Index of random category
long randNRow;

const long shortDelay = 100;
const long longDelay = 10000;

void setup() {
  
  Serial.begin(serialPort);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Hello World");
  display.display();
 
}

 void loop(){
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonFlag = digitalRead(buttonPin);
  
  xPosition = map(xPosition, 0, 1023, 0, SCREEN_WIDTH);
  yPosition = map(yPosition, 0, 1023, 0, SCREEN_HEIGHT);
  Serial.print("X Position: ");
  Serial.print(xPosition);
  Serial.print(" | Y Position: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonFlag);
  delay(shortDelay);

  // Choosing random question for each category
  for (int i = 0; i < nRows; i++)
  {
    randNRow = random(0, nColumns);
    display.println(Questions[i][rand]);
    display.clearDisplay();
    delay(longDelay);
    display.display();
  }
}
```

- ### IOT - Read and Display External Data with Flask and Heroku Example

**Python**:
```python
from flask import Flask, jsonify
from flask_restful import Resource, Api
from flask_cors import CORS

app = Flask(__name__)
api = Api(app)
CORS(app)

questions = {"questions":"Turkiyenin en buyuk dagi?","answers":'Agri Dagi'}

class status (Resource):
    def get(self):
        try:
            return {'data': 'Api is Running'}
        except:
            return {'data': 'An Error Occurred during fetching Api'}

class Questions(Resource):
    def get(self):
        return jsonify(questions)


api.add_resource(status, '/')

api.add_resource(Questions, '/questions/')

if __name__ == '__main__':
    app.run()
```

**Arduino**:
```cpp
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  
#define OLED_RESET -1     //- if your screen has no reset pin, you have to change that value to -1

// Wifi and HTTP libraries
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <ArduinoJson.h>  // to parse the resulting data.

const char* ssid = "WiFi_ssid";
const char* password = "WiFi_password";

const long serialPort = 115200;

const long longDelay = 1000;
const long shortDelay = 100;

HTTPClient http;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define SCREEN_ADDRESS 0x3C

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

  Serial.begin(serialPort);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.print("Connecting..");}

}
void loop() {

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

      WiFiClient client;
      HTTPClient http;

    http.begin(client, "http://play-ard.herokuapp.com/questions/");  //Specify request destination
    int httpCode = http.GET();                                  //Send the request

    if (httpCode > 0) { //Check the returning code

        DynamicJsonDocument doc(400); //For ESP32/ESP8266 you'll mainly use dynamic.

        DeserializationError error = deserializeJson(doc, client);
        String json = http.getString();
        if (!error) {
          String question = doc["questions"]; 
          String answer = doc["answers"]; 

          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(WHITE);
          display.setCursor(0, 10);
          display.println("--------");
          display.println(question);
          display.println("--------");
          display.println(answer);
          display.display();

          Serial.print("------");
          Serial.print(question);
          Serial.print(answer);
          Serial.print("------");
          
          
  } else {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
         //Get the request response payload
    }
    http.end();   //Close connection
  }
  delay(longDelay);    //Send a request every 30 seconds
}
```

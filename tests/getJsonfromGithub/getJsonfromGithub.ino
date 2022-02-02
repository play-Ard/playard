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

HTTPClient http;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define SCREEN_ADDRESS 0x3C

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

  Serial.begin(serialPort);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(longDelay);
    Serial.print("Connecting..");}

}
void loop() {

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

      WiFiClient client;
      HTTPClient http;

    http.begin(client, "http://play-ard.herokuapp.com/questions/4");  //Specify request destination
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

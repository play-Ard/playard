#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  
#define OLED_RESET -1     //- if your screen has no reset pin, you have to change that value to -1

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
const char* ssid = "RobustCoffeeShop";
const char* password = "robust9496";

HTTPClient http;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define SCREEN_ADDRESS 0x3C

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.print("Connecting..");}

}
void loop() {

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

      WiFiClient client;
      HTTPClient http;

    http.begin(client, "http://my-json-server.typicode.com/erhan-namli/gameduino/db");  //Specify request destination
    int httpCode = http.GET();                                  //Send the request

    if (httpCode > 0) { //Check the returning code

        DynamicJsonDocument doc(400); //For ESP32/ESP8266 you'll mainly use dynamic.

        DeserializationError error = deserializeJson(doc, client);

        if (!error) {
          String deneme = doc["questions"][0]["question"]; 
         
          Serial.print("------");
          Serial.print(deneme);
          Serial.print("------");
          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(WHITE);
          display.setCursor(0, 10);
          display.println(deneme);
          display.display();

          
  } else {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
      String json = http.getString();   //Get the request response payload
    }
    http.end();   //Close connection
  }
  delay(1000);    //Send a request every 30 seconds
}

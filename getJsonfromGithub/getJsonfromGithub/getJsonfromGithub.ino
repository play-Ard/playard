#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
const char* ssid = "SSID";
const char* password = "PASSWORD";

HTTPClient http;

void setup() {

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
          String deneme = doc["questions"][1]["question"]; 
         
          Serial.print("------");
          Serial.print(deneme);
          Serial.print("------");

          
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

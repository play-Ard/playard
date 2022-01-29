#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define SCK  21
#define MISO  22
#define MOSI  19
#define CS  0

long randNumber;

void readFile(fs::FS &fs, const char * path){
  Serial.printf("Reading file: %s\n", path);

  File file = fs.open(path);
  if(!file){
    Serial.println("Failed to open file for reading");
    return;
  }

  while(file.available()){
    Serial.write(file.read());
  }
  file.close();
}

void writeFile(fs::FS &fs, const char * path, const char * message){
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if(!file){
    Serial.println("Failed to open file for writing");
    return;
  }
  if(file.print(message)){
   
  } else {
    Serial.println("Write failed");
  }
  file.close();
}

void setup(){
  Serial.begin(115200);
  SPIClass spi = SPIClass(VSPI);
  spi.begin(SCK, MISO, MOSI, CS);

  SD.begin(CS,spi,80000000);

  const char *Listem[] = {"/soru1.txt", "/soru2.txt", "/soru3.txt", "/soru4.txt"};
  randNumber = random(0, 4);
    Serial.println(Listem[randNumber]);
  writeFile(SD, "/soru1.txt", "Ağrı 1");
  writeFile(SD, "/soru2.txt", "Ağrı 2");
  writeFile(SD, "/soru3.txt", "Ağrı 3");
  writeFile(SD, "/soru4.txt", "Ağrı 4");
  readFile(SD, Listem[randNumber]);
  readFile(SD, Listem[randNumber]);
  Serial.println("-------------");
  Serial.println(Listem[randNumber]);
  Serial.println("-------------");
}
void loop(){
}

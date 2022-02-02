#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define SCK  21
#define MISO  22
#define MOSI  19
#define CS  0
const long serialPort = 115200;

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
  Serial.begin(serialPort);
  SPIClass spi = SPIClass(VSPI);
  spi.begin(SCK, MISO, MOSI, CS);

  SD.begin(CS,spi,80000000);

  const char *filesList[] = {"/question1.txt", "/question2.txt", "/question3.txt", "/question4.txt"};
  randNumber = random(0, 4);
    Serial.println(Listem[randNumber]);
  writeFile(SD, "/question1.txt", "Ağrı 1");
  writeFile(SD, "/question2.txt", "Ağrı 2");
  writeFile(SD, "/question3.txt", "Ağrı 3");
  writeFile(SD, "/question4.txt", "Ağrı 4");
  readFile(SD, filesList[randNumber]);
  readFile(SD, filesList[randNumber]);
  Serial.println("-------------");
  Serial.println(filesList[randNumber]);
  Serial.println("-------------");
}
void loop(){
}

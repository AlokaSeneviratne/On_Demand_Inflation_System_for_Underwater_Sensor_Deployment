#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define data1 34
#define data2 35
#define data3 32

RTC_DS3231 rtc;

char t[32];
char d[32];

int s = 0;
int a1 = 0;
int a2 = 0;
int a3 = 0;
int myFile = 1;

void setup() {
  Serial.begin(9600);

  Serial.println("System Booted.");

  if (!SD.begin(5)) {
    Serial.println("Card Mount Failed");
    return;
  }
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  Wire.begin();
  rtc.begin();
  //rtc.adjust(DateTime(2023, 02, 14, 12, 45, 00));
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

}

void loop() {
  //writetosdcard();
  a1 = digitalRead(data1);
  a2 = digitalRead(data2);
  a3 = digitalRead(data3);

  }
}



//=================================================================================================================

void writetosdcard() {
  Serial.println("Function running...");
  if (myFile) {
    Serial.println("Writing to test.txt...");
    DateTime now = rtc.now();
    sprintf(t, "%02d:%02d:%02d ", now.hour(), now.minute(), now.second());
    sprintf(d, "%02d.%02d.%02d  ", now.year(), now.month(), now.day());
    Serial.println(F("Date/Time: "));
    Serial.print(d); Serial.println(t);
    appendFile(SD, "/test.txt", d);
    appendFile(SD, "/test.txt", ",");
    appendFile(SD, "/test.txt", t);
    appendFile(SD, "/test.txt", ",");
    if (a1 == 1) {
      appendFile(SD, "/test.txt", "1");
    }
    else {
      appendFile(SD, "/test.txt", "0");
    }
    appendFile(SD, "/test.txt", ",");
    if (a2 == 1) {
      appendFile(SD, "/test.txt", "1");
    }
    else {
      appendFile(SD, "/test.txt", "0");
    }
    appendFile(SD, "/test.txt", ",");
    if (a3 == 1) {
      appendFile(SD, "/test.txt", "1");
    }
    else {
      appendFile(SD, "/test.txt", "0");
    }
    appendFile(SD, "/test.txt", "\n");
    Serial.println("done.");
    //readFile(SD, "/test.txt");
    Serial.println(" ");
  }
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  //myFile.close();
  delay(1000);
  //Serial.println("Writing to test.txt...");
}


//===============================================================================================






void readFile(fs::FS &fs, const char * path) {
  Serial.printf("Reading file: %s\n", path);

  File file = fs.open(path);
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }

  Serial.print("Read from file:\n ");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void appendFile(fs::FS &fs, const char * path, const char * message) {
  //Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if (file.print(message)) {
    //Serial.println("Message appended");
    Serial.print("");
  } else {
    Serial.println("Append failed");
  }
  file.close();
}

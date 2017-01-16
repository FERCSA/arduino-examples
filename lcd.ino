#include <SPI.h>
#include <PCD8544.h>

#define LED PC13
#define SERIESRESISTOR 10000
int elapsed_time = 1;

static PCD8544 my_display;


void setup() {
  pinMode(LED, OUTPUT);
  my_display.begin();
  Serial.begin(115200);
}

void loop() {
  // text display tests
  my_display.clear();
  my_display.setCursor(40,2);//x=pixel(0-83), y=line(0-5)
  my_display.print(elapsed_time);
  delay(500);
  my_display.clear();


  for (uint8_t g=0; g< 6; g++) {
    for (uint8_t f=0; f< 79; f++) {
      my_display.setCursor(f,g);
      my_display.print("O");
      delay(10);
    }
  }

  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second

  
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second

  elapsed_time++;
}


/*
 * Default pins: 
 * SCL - PB6
 * SDA - PB7
 * Don't forget to pull up internally or with a resistor!
 * Example size: 24C64 -> 64Kbit -> 8192byte
 * FERCSA(fercsa@freemail.hu)
 */
#include <Wire.h>    
 
#define i2c_bus_000 0x50    //Address of 24LC256 eeprom chip
 
void setup(void)
{
  Serial.begin(115200);
  Wire.begin();
  pinMode(PB6, INPUT_PULLUP);
  pinMode(PB7, INPUT_PULLUP);
}
 
void loop(){
  if (Wire.available())
    Serial.println("Wire lib okay!");

  //write test
//  write_EEPROM(i2c_bus_000, 8191, 0x66);//8192 will start over at 0000!
//  Serial.println( read_EEPROM(i2c_bus_000, 8191), HEX );

  unsigned int address = 0;
  byte value;
  
  for(int i=0;i <8192; i++){
    value = read_EEPROM(i2c_bus_000, i);
    if(i < 10){
      Serial.print("000");
    }    
    if(i >= 10 && i < 100){
      Serial.print("00");
    }     
    if(i >= 100 && i < 1000){
      Serial.print("0");
    }     
    Serial.print(i);
    Serial.print(":<");
    if(value < 16){
      Serial.print("0");
    }
    Serial.print(value, HEX);
    Serial.print("> ");
    if(i%8 == 7){
      Serial.println();
    }
  }
  Serial.println();
  Serial.println("----------------------");
  delay(2000);
}
 
void write_EEPROM(int bus, unsigned int address, byte data ) 
{
  Wire.beginTransmission(bus);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.write(data);
  Wire.endTransmission();
 
  delay(5);
}
 
byte read_EEPROM(int bus, unsigned int address ) 
{
  byte rdata = 0xFF;
 
  Wire.beginTransmission(bus);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
 
  Wire.requestFrom(bus,1);
 
  if (Wire.available()) rdata = Wire.read();
 
  return rdata;
}

/* One cell(3.7V) voltmeter with voltage divider for a 3.3V device
 * R1=464k, R2=116k (470k/120k)
 * FERCSA(fercsa@freemail.hu)
 */

float divider = 4.2 / 3.3;//max cell voltage / max analog pin voltage

void setup(){
  Serial.begin(115200);
}

void loop(){

  int analog_value = analogRead(PA0);
  float voltage = 3.3 / 4095 * analog_value * divider;//analog pin voltage / resolution * ADC value * divider

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print("V (");
  Serial.print(analog_value);
  Serial.println(")");
 
  delay(1000);
}

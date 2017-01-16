#define SERIESRESISTOR 10000    

void setup(void) {
  Serial.begin(115200);
}
 
void loop(void) {

  Serial.print("Temperature: "); 
  Serial.println( get_temp(PB0) );

  delay(1000);
}

double get_temp(int pin){
  int RawADC = analogRead(pin);

  long Resistance;
  double Temp;

  Resistance = (SERIESRESISTOR * (4095.0f / float(RawADC) - 1));
 
  /******************************************************************/
  /* Utilizes the Steinhart-Hart Thermistor Equation:               */
  /*    Temperature in Kelvin = 1 / {A + B[ln(R)] + C[ln(R)]^3}     */
  /*    where A = 0.001129148, B = 0.000234125 and C = 8.76741E-08  */
  /******************************************************************/
  Temp = log(Resistance);
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;  // Convert Kelvin to Celsius
  return Temp;
}


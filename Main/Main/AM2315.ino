void get_outdoorTemperature() {

  if (! am2315.readTemperatureAndHumidity(&temperature, &humidity)) {
   
  }
  Serial.print("Temp *C: ");
  Serial.println(temperature);
  dtostrf(temperature, 6, 2, strTemperature);
  Serial.println(strTemperature);
  
  Serial.print("Hum %: "); 
  Serial.println(humidity);
  dtostrf(humidity, 6, 2, strHumidity);

}

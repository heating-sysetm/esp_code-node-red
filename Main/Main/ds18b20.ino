void Temperature() {

  // Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  

  Serial.print("Sensor 1(*C): ");
  Serial.println(sensors.getTempC(sensor1));
  Fsensor1 = sensors.getTempC(sensor1);
  dtostrf(Fsensor1, 5, 2, Strsensor1);
 
  

  Serial.print("Sensor 2(*C): ");
  Serial.println(sensors.getTempC(sensor2));
  Fsensor2 = sensors.getTempC(sensor2);
  dtostrf(Fsensor2, 5, 2, Strsensor2);

  
  Serial.print("Sensor 3(*C): ");
  Serial.println(sensors.getTempC(sensor3));
  Fsensor3 = sensors.getTempC(sensor3);
  dtostrf(Fsensor3, 5, 2, Strsensor3);


  Serial.print("Sensor 4(*C): ");
  Serial.println(sensors.getTempC(sensor4));
  Fsensor4 = sensors.getTempC(sensor4);
  dtostrf(Fsensor4, 5, 2, Strsensor4);


  Serial.print("Sensor 5(*C): ");
  Serial.println(sensors.getTempC(sensor5));
  Fsensor5 = sensors.getTempC(sensor5);
  dtostrf(Fsensor5, 5, 2, Strsensor5);


  Serial.print("Sensor 6(*C): ");
  Serial.println(sensors.getTempC(sensor6));
  Fsensor6 = sensors.getTempC(sensor6);
  dtostrf(Fsensor6, 5, 2, Strsensor6);


  Serial.print("Sensor 7(*C): ");
  Serial.println(sensors.getTempC(sensor7));
  Fsensor7 = sensors.getTempC(sensor7);
  dtostrf(Fsensor7, 5, 2, Strsensor7);



  delay(1000);

}

void GasSensor()
{
  readMQ9_2 = analogRead(39);
//  readMQ9_1 = analogRead(36);

  GasSensor2 = map(readMQ9_2, 0, 4095, 10, 100);
  dtostrf(GasSensor2, 4, 0, strGasSensorTwo);
  
//  GasSensor1 = map(readMQ9_1, 0, 4095, 10, 100);
//  dtostrf(GasSensor1, 4, 0, strGasSensorOne);

//  Serial.println(GasSensor1);
  Serial.println(GasSensor2);

  //delay(1000);
}

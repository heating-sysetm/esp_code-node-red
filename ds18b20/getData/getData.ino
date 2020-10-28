#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to GPIO15
#define ONE_WIRE_BUS 15
// Setup a oneWire instance to communicate with a OneWire device
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);
//28 4 2 79 A2 1 3 E5
//28 22 5 56 B5 1 3C 95
//28 AD 63 56 B5 1 3C D6
DeviceAddress sensor5 = { 0x28, 0xD8, 0x42, 0x56, 0xB5, 0xFF, 0x3C, 0xD5 };//SENSOR 5
DeviceAddress sensor4 = { 0x28, 0x4, 0x2, 0x79, 0xA2,0x1,0x3,0xE5 };//NESNOR 4
DeviceAddress sensor1 = { 0x28, 0x24, 0x77, 0x79, 0xA2, 0x1, 0x3, 0xEC };//SENSOR 1
DeviceAddress sensor6 = { 0x28, 0x86, 0x7C, 0x56, 0xB5, 0x1, 0x3C, 0x8B };//SENSOR 6
DeviceAddress sensor3 = { 0x28, 0xF5, 0x90, 0x56, 0xB5, 0x1, 0x3C, 0xB1 };//SENSOR 3
DeviceAddress sensor2 = { 0x28, 0xAD, 0x63, 0x56, 0xB5, 0x1, 0x3C, 0xD6 };//SENSOR 2
DeviceAddress sensor7 = { 0x28, 0xEB, 0x6D, 0x79, 0xA2, 0x1, 0x3, 0x96 };//SENSOR 7

void setup(void) {
  Serial.begin(115200);
  sensors.begin();
}

void loop(void) {
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  Serial.print("Sensor 1(*C): ");
  Serial.println(sensors.getTempC(sensor1));
 

  Serial.print("Sensor 2(*C): ");
  Serial.println(sensors.getTempC(sensor2));
  

  Serial.print("Sensor 3(*C): ");
  Serial.println(sensors.getTempC(sensor3));
 

   Serial.print("Sensor 4(*C): ");
  Serial.println(sensors.getTempC(sensor4));


   Serial.print("Sensor 5(*C): ");
  Serial.println(sensors.getTempC(sensor5));
 

   Serial.print("Sensor 6(*C): ");
  Serial.println(sensors.getTempC(sensor6));
 

   Serial.print("Sensor 7(*C): ");
  Serial.println(sensors.getTempC(sensor7));
 

  

  delay(2000);
}

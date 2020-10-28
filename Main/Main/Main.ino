#include <WiFi.h>
#include <OneWire.h>
#include <PubSubClient.h>
#include <Adafruit_AM2315.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>



#define ONE_WIRE_BUS 15
#define led 5



const char* ssid = "Narmafzar";
const char* password = "";
const char* mqtt_server = "192.168.202.199";

WiFiClient espClient12;
PubSubClient client(espClient12);

Adafruit_AM2315 am2315;
float temperature, humidity;
char strTemperature[7];
char strHumidity[7];

//MQ9
int GasSensor1 = 0;
int GasSensor2= 0;
int   readMQ9_1  = 0;
int   readMQ9_2  = 0;
char  strGasSensorOne[4];
char  strGasSensorTwo[4];

// Setup a oneWire instance to communicate with a OneWire device
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

DeviceAddress sensor1 = { 0x28, 0x24, 0x77, 0x79, 0xA2, 0x1, 0x3, 0xEC };//SENSOR 1
DeviceAddress sensor2 = { 0x28, 0xAD, 0x63, 0x56, 0xB5, 0x1, 0x3C, 0xD6 };//SENSOR 2
DeviceAddress sensor3 = { 0x28, 0xF5, 0x90, 0x56, 0xB5, 0x1, 0x3C, 0xB1 };//SENSOR 3
DeviceAddress sensor4 = { 0x28, 0x4, 0x2, 0x79, 0xA2, 0x1, 0x3, 0xE5 }; //NESNOR 4
DeviceAddress sensor5 = { 0x28, 0xD8, 0x42, 0x56, 0xB5, 0xFF, 0x3C, 0xD5 };//SENSOR 5
DeviceAddress sensor6 = { 0x28, 0x86, 0x7C, 0x56, 0xB5, 0x1, 0x3C, 0x8B };//SENSOR 6
DeviceAddress sensor7 = { 0x28, 0xEB, 0x6D, 0x79, 0xA2, 0x1, 0x3, 0x96 };//SENSOR 7

float Fsensor1 = 0.0;
float Fsensor2 = 0.0;
float Fsensor3 = 0.0;
float Fsensor4 = 0.0;
float Fsensor5 = 0.0;
float Fsensor6 = 0.0;
float Fsensor7 = 0.0;

char Strsensor1[7];
char Strsensor2[7];
char Strsensor3[7];
char Strsensor4[7];
char Strsensor5[7];
char Strsensor6[7];
char Strsensor7[7];

LiquidCrystal_I2C lcd(0x27, 20, 4);


void setup() {
  // put your setup code here, to run once:


  Serial.begin(115200);

  //*** wifi **//
  setup_wifi();
  //*** wifi **//

  //***broker***//
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  //***broker***//

  //*** AM2315 *** //
  am2315.begin();
  Serial.println("AM2315 Test!");
  //*** AM2315 ***//

  //*** ds18b20 ***//
  sensors.begin();
  //*** ds18b20 ***//

  //*** lcd***//
  lcd.begin();
  lcd.backlight();
  
  //*** lcd***//

  //*** led***//

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);




}

void loop() {
  // put your main code here, to run repeatedly:

  if (!client.connected())
  {
    reconnect();
  }
  if (!client.loop()) {
    client.connect("system_monitoring_1"); // ESP_SYSTEM MONITORING
  }

  get_outdoorTemperature();
  GasSensor();
  Temperature();
  show_lcd();
 


}

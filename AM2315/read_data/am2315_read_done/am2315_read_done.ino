#include <Wire.h>
#include <Adafruit_AM2315.h>

/***************************************************
  This is an example for the AM2315 Humidity + Temp sensor

  Designed specifically to work with the Adafruit AM2315 Sensor
  ----> https://www.adafruit.com/products/1293

  These displays use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// Connect RED of the AM2315 sensor to 5.0V
// Connect BLACK to Ground
// Connect WHITE to i2c clock
// Connect YELLOW to i2c data

Adafruit_AM2315 am2315;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
    
  }
  am2315.begin();
    Serial.println("AM2315 Test!");
}



  void loop() {
    float temperature, humidity;

    if (! am2315.readTemperatureAndHumidity(&temperature, &humidity)) {

      return;
    }

    Serial.print("Temp *C: "); Serial.println(temperature);
    Serial.print("Hum %: "); Serial.println(humidity);

    delay(4000);
  }

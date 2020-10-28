void callback(String topic, byte* message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  Serial.print(".Message: ");
  String messagein;

  for (int i = 0; i < length; i++)
  {
    messagein += (char)message[i];
  }
  Serial.println(messagein);


  if (topic == "send/info") {
    digitalWrite(led, HIGH);

    client.publish("outTemp", strTemperature);
    client.publish("outHum", strHumidity);

    client.publish("Temp1", Strsensor1);
    client.publish("Temp2", Strsensor2);
    client.publish("Temp3", Strsensor3);
    client.publish("Temp4", Strsensor4);
    client.publish("Temp5", Strsensor5);
    client.publish("Temp6", Strsensor6);
    client.publish("Temp7", Strsensor7);

   // client.publish("GasSensor1", strGasSensorOne);
    client.publish("GasSensor2", strGasSensorTwo);



    digitalWrite(led, LOW);

  }

}


//************************************************************************
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    if ((client.connect("system_monitoring_1"))) {
      Serial.println("connected");
      client.subscribe("send/info");


    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");

      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

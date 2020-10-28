void show_lcd()
{
lcd.setCursor(0,0);  
lcd.print(" Monitoring  System");

lcd.setCursor(0,1);  
lcd.print("Temp OUT:");
lcd.setCursor(9,1);  
lcd.print(temperature);

lcd.setCursor(0,2);  
lcd.print("HUM  OUT:");
lcd.setCursor(9,2);  
lcd.print(humidity);

lcd.setCursor(0,3);  
lcd.print("GAS1:");
lcd.setCursor(5,3);  
lcd.print(GasSensor1);

lcd.setCursor(11,3);  
lcd.print("GAS2:");
lcd.setCursor(16,3);  
lcd.print(GasSensor2);

lcd.setCursor(8,3);  
lcd.print("%");
lcd.setCursor(19,3);  
lcd.print("%");
}

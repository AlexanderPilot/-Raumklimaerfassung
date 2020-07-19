#include <Arduino.h>
#include "TempSens.h"
#include <WiFi.h>


//Initialisierung Sensor
TempSens tempSens(0); //BMP280, I2C
//TempSens tempSens(1); //BMP180, I2C
//TempSens tempSens(2); //AM2320
//TempSens tempSens(3); //LM35
//TempSens tempSens(4); //DHT11
//TempSens tempSens(5); //TMP35GZ

//ISR für Timerinterrupt
hw_timer_t * timer = NULL;
bool eventtrigger;
// ISR to set trigger
void IRAM_ATTR onTimer()
{
    eventtrigger = true;
}

void setup()
{
  //Seriele Verbindung öffnen
  Serial.begin(SERIAL_SPEED);
  Serial.println("Raumklimaerfassung");
  Serial.println(PRINT_SEPARATOR_LONG);
  delay(1000);

  //Timer-Interrupt initialisieren 
  
  timer = timerBegin(0, 80, true); // Time 1: 1/(80MHZ/80) = 1us and count up
  timerAttachInterrupt(timer, &onTimer, true); // Attach onTimer function
  timerAlarmWrite(timer, 1000000, true);   // Set alarm to 1000 ms and repeat it (true)


  //WiFi einrichten und starten

  //Sensoren einrichten und starten
  tempSens.begin();

  //Übertragungsprotokolle einrichten

}

void loop()
{
  //Deklaration Variablen  
  float tempSensorValue;
  float rhSensorValue;

  //Abfrage Lufttemperatur
  tempSensorValue = tempSens.getTemperature();
  if (tempSensorValue != NAN)
  {
    Serial.print("Temperatur: ");
    Serial.print(tempSensorValue);
    Serial.println("°C");
  }
  else
  {
    Serial.println("Sensorwert ungültig");

  }
  
  //Abfrage Luftfeuchtigkeit
  rhSensorValue = tempSens.getHumidity();
  if (rhSensorValue != NAN)
  {
    Serial.print("Luftfeuchtigkeit: ");
    Serial.print(rhSensorValue);
    Serial.println("%");
  }
  else
  {
    Serial.println("Sensorwert ungültig");

  }
  
  //Abfrage Luftdruck

  //Abfrage Luftqualität (CO, CO2, NOx)

  //Abfrage Regensensor

  //Abfrage Windgeschwindigkeit

}
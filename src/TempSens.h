#pragma once

#include "Arduino.h"
#include "Wire.h"
#include "Configuration.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_BMP085.h>

class TempSens
{
    public:
        //Konstruktor
        TempSens(uint8_t type);

        //Initialisierung
        void begin();

        //Auslesefunktion
        float getTemperature();
        float getHumidity();
        

    private:
        uint8_t _type;

        Adafruit_BMP085 *_bmp180;
        Adafruit_BME280 *_bme280;
};
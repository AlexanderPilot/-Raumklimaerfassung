
#include "TempSens.h"


TempSens::TempSens(uint8_t type)
{
    _type = type;
    switch(_type)
    {
        case 0: //BMP280
            _bme280 = new Adafruit_BME280();
            break;
        case 1: //BMP180
            _bmp180 = new Adafruit_BMP085();
            break;
        case 2: //AM2320
            //_am2320Sensor = new Adafruit_AM2320();
            break;
        case 3: //LM35
            break;
        case 4: //DHT11
            //_dhtSensor = new DHT(T_SENS_PIN,DHT11);
            break;
        case 5: //TMP35GZ
            break;
        default:
            break;
    }
}


void TempSens::begin()
{
    switch(_type)
    {
        case 0: //BMP280
            if (!_bme280->begin(0x76))
            {
                Serial.println("Could not find a valid BME280 sensor, check wiring!");
                while (1);
            }
            break;
        case 1: //BMP180
            if (!_bmp180->begin())
            {
	            Serial.println("Could not find a valid BMP180 sensor, check wiring!");
            	while (1) {}
              }
            break;
        case 2: //AM2320
            //_am2320Sensor->begin();
            break;
        case 3: //LM35
            break;
        case 4: //DHT11
            //_dhtSensor->begin();
            break;
        case 5: //TMP35GZ
            break;
        default:
            break;
    }
}

float TempSens::getTemperature()
{
    float temp = 0;

    switch(_type)
    {
        case 0: //BMP280
            temp = _bme280->readTemperature();
            break;
        case 1: //BMP180
            temp = _bmp180->readTemperature();
            break;
        case 2: //AM2320
            //temp = _am2320Sensor->readTemperature();
            break;
        case 3: //LM35
            temp = 25;
            break;
        case 4: //DHT11
            //temp = _dhtSensor->readTemperature(false);
            break;
        case 5: //TMP35GZ
            temp = 25;
            break;
        default:
            break;
    }
    return temp;
}

float TempSens::getHumidity()
{
    float rh = 0;

    switch(_type)
    {
        case 0: //BMP280
            rh = _bme280->readHumidity();
            break;
        case 1: //BMP180
            //sensor doesn't provide humidity
            break;
        case 2: //AM2320
            //rh = _am2320Sensor->readTemperature();
            break;
        case 3: //LM35
            rh = 25;
            break;
        case 4: //DHT11
            //rh = _dhtSensor->readTemperature(false);
            break;
        case 5: //TMP35GZ
            rh = 25;
            break;
        default:
            break;
    }
    return rh;
}
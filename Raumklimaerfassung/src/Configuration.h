/***************************************************************************
 * Header für die Konfiguarationen der Wetterstation
 *
 *
 **************************************************************************/


/* Vermeidung Doppeldefinitionen */
#pragma once

/***************************************************************************
 * Versionierung der Wetterstation1
 * 
 * Version 1.0 wird vergeben,sobald die Wetterstation initial funktioniert
 * 
 * Versionshistorie:
 * v1.0 Erstinbetriebnahme der Wetterstation
 **************************************************************************/
#define VERSION "0.2"


/***************************************************************************
 * Einbinden von benötigten Bibliotheken
 **************************************************************************/
#include "WiFi.h"

/***************************************************************************
 * Serielle Verbindung
 **************************************************************************/
#define SERIAL_SPEED 115200

/***************************************************************************
 * Debug Botschaften aktivieren/deaktivieren
 **************************************************************************/
#define DEBUG_PRINT

#ifdef DEBUG_PRINT
  #define _DEBUG_BEGIN(x)       Serial.begin(x);
  #define _DEBUG_PRINT(x)       Serial.print(x);
  #define _DEBUG_PRINTLN(x)     Serial.println(x);
  #define _DEBUG_WRITE(x)       Serial.write(x);
#else
  #define _DEBUG_BEGIN(x)
  #define _DEBUG_PRINT(x)
  #define _DEBUG_PRINTLN(x)
  #define _DEBUG_WRITE(x)
#endif

#define PRINT_SEPARATOR         "-------------------------"
#define PRINT_SEPARATOR_LONG    "--------------------------------------------------"


/***************************************************************************
 * WiFi Einstellungen
 **************************************************************************/
#define WIFI_MAX_TIME_CONNECTING    20  //max. Dauer, die gewartet wird bis Verbindungsaufbau abgebrochen wird

/***************************************************************************
 * I2C Einstellungen
 **************************************************************************/
/* Adresse fuer Sensor XY */
#define XY_ADDRESS      0x68
#define SDA_PIN         21
#define SCL_PIN         22

/***************************************************************************
 * Verwendete Sensoren
 **************************************************************************/
/* Temperatursensor vorhanden */

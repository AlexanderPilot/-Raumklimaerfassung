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
#define PRINT_SEPARATOR         "-------------------------"
#define PRINT_SEPARATOR_LONG    "--------------------------------------------------"


/***************************************************************************
 * WiFi Einstellungen
 **************************************************************************/
#define WIFI_MAX_TIME_CONNECTING    20  //max. Dauer, die gewartet wird bis Verbindungsaufbau abgebrochen wird

/***************************************************************************
 * I2C Einstellungen
 **************************************************************************/
/* Adresse fuer Temperatursensor */
#define AM2320_ADDRESS  0x05
#define SDA_PIN         21
#define SCL_PIN         22
#define T_SENS_PIN      4

/***************************************************************************
 * Verwendete Sensoren
 **************************************************************************/
/* Temperatursensor vorhanden */

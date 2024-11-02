
/*
 * WICHTIG: 4,7k Ohm Widerstand benutzen
 * Zwischen 5V und Data Pin
 */

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS A0   // Pin für DS18B20

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(void){
  Serial.begin(9600);
  Serial.println("Temperaturauslesen von dem DS18B20");
  Serial.println();
  sensors.begin();
}

void loop(void){
  sensors.requestTemperatures();
  Serial.print("Temperatur: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println("°C");
  Serial.println();
  delay(1000);
}

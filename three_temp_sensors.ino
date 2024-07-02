#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to Arduino digital pin 2
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Start the DS18B20 sensor
  sensors.begin();
  
  // Print the header for PLX-DAQ
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Sensor 1,Sensor 2,Sensor 3");
}

void loop() {
  // Request temperature readings from all sensors
  sensors.requestTemperatures();
  
  // Print temperature readings to the Serial Monitor
  Serial.print("DATA,TIME,");
  for (int i = 0; i < sensors.getDeviceCount(); i++) {
    Serial.print(sensors.getTempCByIndex(i));
    Serial.print(",");
  }
  Serial.println();
  
  // Wait for 1 second before taking another reading
  delay(1000);
}

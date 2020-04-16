#include "sensor_bme280.h"

#include <math.h>

sensor_bme280::sensor_bme280() {
    // default settings
    // (you can also pass in a Wire library object like &Wire2)
//     Wire.begin(sdaPin, sclPin);
//     g_b_iicBME280_connected = bme.begin(0x76, &Wire);  // 0x76: default i2c address of bme280
//     if (!g_b_iicBME280_connected) Serial.println("Could not find a valid BME280 sensor, check wiring!");
}

sensor_bme280::~sensor_bme280() {

}

bool sensor_bme280::connectBME280iic() {
  bool status;

  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  Wire.begin(sdaPin, sclPin);
  status = bme.begin(0x76, &Wire);  // 0x76: default i2c address of bme280
  if (!status) Serial.println("Could not find a valid BME280 sensor, check wiring!");
  
  g_b_iicBME280_connected = status;
  
  return status;
}

double sensor_bme280::get_temperature() {
    double temperature;
    
    if (g_b_iicBME280_connected) {
        temperature = bme.readTemperature();
        
        return temperature;
    }
    else return 0;
}

double sensor_bme280::get_humidity() {
    double humidity;
    
    if (g_b_iicBME280_connected) {
        humidity = bme.readHumidity();
        humidity = roundf(humidity * 10.0F) / 10.0F; // round to .1 precision
        
        return humidity;
    }
    else return 0;
}

double sensor_bme280::get_pressure() {
    double pressure;
    
    if (g_b_iicBME280_connected) {
        pressure = bme.readPressure() / 100.0F; // 100.0F ... type cast to float to force floating point division
        
        return pressure;
    }
    else return 0;
}

int sensor_bme280::get_altitude() {
    double altitude;
    
    if (g_b_iicBME280_connected) {
        altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
        
        return int(altitude);
    }
    else return 0;
}

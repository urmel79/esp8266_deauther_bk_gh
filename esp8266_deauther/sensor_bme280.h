#ifndef sensor_bme280_h
#define sensor_bme280_h

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// mittlerer Luftdruck der Atmosphäre (atmosphärischer Druck) auf Meereshöhe
// #define SEALEVELPRESSURE_HPA (1013.25)
// #define SEALEVELPRESSURE_HPA (1018) // DD-Gittersee, 2019-08-26 21:00
// #define SEALEVELPRESSURE_HPA (1015) // Nürnberg, 2019-08-28 20:00
// #define SEALEVELPRESSURE_HPA (1019) // Nürnberg, 2019-08-29 12:00
// #define SEALEVELPRESSURE_HPA (1022) // DD-Albertstadt, 2019-08-30 10:00
#define SEALEVELPRESSURE_HPA (1025) // DD-Albertstadt, 2020-04-10 14:00
// #define SEALEVELPRESSURE_HPA (1025) // Leipzig, 2020-04-10 14:00

class sensor_bme280 {
    public:

        sensor_bme280();
        ~sensor_bme280();
        
        bool connectBME280iic();
        
        double get_temperature();
        double get_humidity();
        double get_pressure();
        int get_altitude();

    private:
        
        bool g_b_iicBME280_connected = false;
        
        const int sdaPin = D1;
        const int sclPin = D2;

        Adafruit_BME280 bme; // I2C
    
};

#endif // ifndef sensor_bme280_h

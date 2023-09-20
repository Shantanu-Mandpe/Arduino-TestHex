#include "Arduino_BHY2.h"
#include "TestHex.h"

// Sensor XYZ has XYZ data as int16_t -> convert to hexadecimal

SensorXYZ accelerometer(SENSOR_ID_ACC);
SensorXYZ gyro(SENSOR_ID_GYRO);

TestHex testhex(13);

void setup(){
  Serial.begin(115200);
  BHY2.begin();

  accelerometer.begin();
  gyro.begin();
}

void loop(){
  static auto lastCheck = millis();

  // Update function should be continuously polled
  BHY2.update();

  // Check sensor values every second  
  if (millis() - lastCheck >= 1000) {
    lastCheck = millis();   
    
    testhex.convert("GyroX",gyro.x());
    testhex.convert("GyroY",gyro.y());
    testhex.convert("GyroZ",gyro.z());
  }
}
 
 
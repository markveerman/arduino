#ifndef __BURGLER_ALARM_H__
#define __BURGLER_ALARM_H__

#include "pir_sensor.h"
#include "smtp_service.h"

const int ALERT_MAX = 10;

class BurglerAlarm {
  PassiveInfraredSensor _pir_sensor;
  SmtpService _smtp_service;
  bool sending;
  int alert_count;
  
  void send_alarm() {
    if (!sending && alert_count <= ALERT_MAX) {   
      sending = true;
 
      Email email(
        "mark@veerman.com",
        // mark@veerman.com,
        "nuf01@icloud.com",
        "Intruder Alert!!",
        "Someone is in your bedroom!"
      );
      _smtp_service.send_email(email);
      
      sending = false;
    }
  }
  
  public:
  BurglerAlarm(
    const PassiveInfraredSensor& pir_sensor,
    const SmtpService& smtp_service) :
      _pir_sensor(pir_sensor),
      _smtp_service(smtp_service) {
        
        sending = false;
        alert_count = 0;
  }
  
  void check() {
    Serial.println("Checking");
    if (_pir_sensor.motion_detected()) {
      Serial.println("Intruder detected!");
      send_alarm();
    }
  }
};

#endif

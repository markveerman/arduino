#ifndef __PASSIVE__IR__SENSOR_
#define __PASSIVE__IR__SENSOR_

class PassiveInfraredSensor {
  int _input_pin;

  public:
  PassiveInfraredSensor(const int input_pin) {
    _input_pin = input_pin;
    pinMode(_input_pin, INPUT);
  }

  const bool motion_detected() {
    return digitalRead(_input_pin) == HIGH;
  }

};

#endif

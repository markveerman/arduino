const unsigned int PIR_INPUT_PIN = 2;
const unsigned int BAUD_RATE = 9600;

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

PassiveInfraredSensor pir(PIR_INPUT_PIN);
int led = 13;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(led, OUTPUT);     
}

void loop() {
  if (pir.motion_detected()) {
    digitalWrite(led, HIGH);
    Serial.println("ALERT: Motion detected!");
  } 
  else {
    digitalWrite(led, LOW);
    Serial.println("CHILL OUT: No motion detected");
  }

  delay(1000);
}


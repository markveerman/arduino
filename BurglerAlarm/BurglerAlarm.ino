#include <SPI.h>
#include <Ethernet.h>

#include "burgler_alarm.h"

const unsigned int PIR_INPUT_PIN = 2;
const unsigned int BAUD_RATE = 9600;

IPAddress smtp_server(68, 87, 26, 155);
const unsigned int SMTP_PORT = 25;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress my_ip(192, 168, 1, 71);

PassiveInfraredSensor pir_sensor(PIR_INPUT_PIN);
SmtpService smtp_service(smtp_server, SMTP_PORT);
BurglerAlarm burgler_alarm(pir_sensor, smtp_service);

void setup() {
  Ethernet.begin(mac, my_ip);
  Serial.begin(BAUD_RATE);
  delay(20 * 1000);
}

void loop() {
  burgler_alarm.check();
  delay(1000);
}

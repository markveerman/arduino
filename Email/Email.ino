#include <SPI.h>
#include <Ethernet.h>
#include "smtp_service.h"

const unsigned int SMTP_PORT = 25;
const unsigned int BAUD_RATE = 9600;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress my_ip(192, 168, 1, 71);
IPAddress smtp_server(68, 87, 26, 155);

SmtpService smtp_service(smtp_server, SMTP_PORT);

void setup() {
  Ethernet.begin(mac, my_ip);
  Serial.begin(BAUD_RATE);
  delay(1000);
  Email email(
    "mark@veerman.com",
    "markveerman@gmail.com",
    "yet another subject",
    "yet another body"
  );
  smtp_service.send_email(email);
}

void loop() {}

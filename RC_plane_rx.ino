/*
 * RC Plane RX
 * Elia Sulimanov
 * ATtiny84
 */

#include <Servo.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

// Digital pins def
const int CE = 0;
const int CS = 1;
const int MOSI = 2;
const int MISO = 3;
const int SCK = 4;

// Radio object def
RF24 radio(CE,CS);
int msg[6];
const uint64_t pipe = 0xE8E8F0F0E1LL;

// LED def
const int NAV_WING_LED = 5;
const int TAIL_LED = 6;
bool state;

// Servos def
Servo rudder;
const int RUDDER_PIN = 7;
Servo elevators;
const int ELEVATORS_PIN = 8;
Servo alierons;
const int ALIERONS_PIN = 9;
int val;

// Motor def
const int MOTOR_PIN = 10;

void setup() {
  
  // Set digital pins as output
  pinMode(NAV_WING_LED, OUTPUT);
  pinMode(TAIL_LED, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  // Attach servos
  rudder.attach(RUDDER_PIN);
  elevators.attach(ELEVATORS_PIN);
  alierons.attach(ALIERONS_PIN);
  
  state = false;

  // Start radio
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    bool done = false;
    while (!done)
    {
      done = radio.read(msg, 1);

      // Set motor speed
      analogWrite(MOTOR_PIN, map(msg[0], 0, 100, 0, 255));
      
      // Set servos value 0-45
      rudder.write(map(msg[1], 0, 100, 0, 45));
      elevators.write(map(msg[2], 0, 100, 0, 45));
      alierons.write(map(msg[3], 0, 100, 0, 45));
  
      // Check for lights message
      if (msg[4] == 1)
      {
        // Lights currently off
        if (!state)
        {
          navLightOn();
          state = true;
        }
        // Lights currently on
        else
        {
          navLightOff();
          state = false;
        }
      }
      delay(1);
    }
  }
}

void navLightOn()
{
  digitalWrite(NAV_WING_LED, HIGH);

  for(int i = 0; i < 6; i++){
     digitalWrite(TAIL_LED, HIGH);
     delay(75);
     digitalWrite(TAIL_LED, LOW);
     delay(75);
    }
    delay(1000);
}

void navLightOff()
{
  digitalWrite(NAV_WING_LED, LOW);
  digitalWrite(TAIL_LED, LOW);
}

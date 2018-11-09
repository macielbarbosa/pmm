#include<Servo.h>

#define BOTAO 2
#define RED_LED 7
#define GREEN_LED 12
#define SERVO 9

Servo servo;
int estado = 1;
volatile int led = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(SERVO, OUTPUT);
  servo.attach(SERVO);
  servo.write(0);
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING);
}

void loop() {
  if (led) {
    digitalWrite(RED_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, LOW);
    delay(1000);
    led= !led;
  }
}

void blink() {
  led = !led;
  digitalWrite(GREEN_LED, led);
}


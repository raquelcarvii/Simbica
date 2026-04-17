
#include <Otto.h>

Otto Otto;

#define LeftLeg 2
#define RightLeg 3
#define LeftFoot 4
#define RightFoot 5
#define Buzzer 13
#define Trigger 8
#define Echo 9

int distancia;

int medirDistancia() {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  long duracao = pulseIn(Echo, HIGH);
  return duracao * 0.034 / 2;
}

void setup() {
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  Otto.sing(S_connection);
  delay(1000);
}

void loop() {
  distancia = medirDistancia();
  if (distancia > 0 && distancia < 15) {
    Otto.sing(S_surprise);
    Otto.walk(2, 1000, -1);
    delay(500);
    Otto.turn(4, 1000, 1);
    delay(500);
  } else {
    Otto.walk(2, 1000, 1);
  }
}

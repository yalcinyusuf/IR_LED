#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTON0 0xFF9867
#define BUTON1 0xFFA25D
#define BUTON2 0xFF629D
#define BUTON3 0xFFE21D
#define BUTON4 0xFF22DD
#define BUTON5 0xFF02FD
#define BUTON6 0xFFC23D
#define BUTON7 0xFFE01F
#define BUTON8 0xFFA857
#define BUTON9 0xFF906F
#define PLAYPAUSE 0xFF38C7
#define STAR 0xFF6897 
#define SQUARE 0xFFB04F
#define UP 0xFF18E7
#define DOWN  0xFF4AB5 
#define PREV 0xFF10EF
#define NEXT 0x
FF5AA5
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
void setup() {
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);

Serial.begin(9600);
irrecv.enableIRIn();

}

void loop() {
if(irrecv.decode(&results))
{
  if(results.value == BUTON1) {
    digitalWrite(led1, !digitalRead(led1));

    if(digitalRead(led1) == HIGH)
    Serial.println("LED 1 Yandi");
    else
    Serial.println("LED 1 Sondu");
  }
  if(results.value == BUTON2) {
    digitalWrite(led2, !digitalRead(led2));

    if(digitalRead(led2) == HIGH)
    Serial.println("LED 2 Yandi");
    else
    Serial.println("LED 2 Sondu");
  }
  if(results.value == BUTON3) {
    digitalWrite(led3, !digitalRead(led3));

    if(digitalRead(led3) == HIGH)
    Serial.println("LED 3 Yandi");
    else
    Serial.println("LED 3 Sondu");
  }
  if(results.value == BUTON4) {
    digitalWrite(led4, !digitalRead(led4));

    if(digitalRead(led4) == HIGH)
    Serial.println("LED 4 Yandi");
    else
    Serial.println("LED 4 Sondu");
  }
  if(results.value == BUTON0) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    Serial.println("Tum ledler sondu");
    }
    if(results.value == BUTON5) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    Serial.println("Tum ledler yandi");
    }
    irrecv.resume();
}
}

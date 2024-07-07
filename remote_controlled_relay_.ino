#include<IRremote.h>
#include"Relay.h"
#include<Wire.h>
#define IR_INPUT 4

IRrecv reciever(IR_INPUT);
decode_results results;
Relay RELAY_IN(9,false);

void setup() {
Serial.begin(9600);
reciever.enableIRIn();
reciever.blink13(true);
RELAY_IN.begin();
}

void loop() {
if(reciever.decode(&results)){
  if(results.value == 0xFFA25D){
    Serial.println(results.value,HEX);
    RELAY_IN.turnOff();
    digitalWrite(8,HIGH);
  }
   if(results.value == 0xFFE21D){
    Serial.println(results.value,HEX);
    RELAY_IN.turnOn();
    digitalWrite(8,LOW);
  }
  reciever.resume();
}

}

/*******************************
author = Alan Hernandez Garcia
date = 5 de Abril 2017
Ejercicio = Ejercicio 6 Paso 3
 ******************************/
const int button=5;
const int ledPos=10;
int anterior;
int state;
int ledState;
int normal=0;
void setup() {
  state = LOW;
  pinMode(button,INPUT);
  pinMode(ledPos,OUTPUT);
  anterior=LOW;
  ledState=LOW;
}
void loop() {
  state=digitalRead(button);
  if(normal==0){
    if(anterior==HIGH){
      ledState=LOW;
      anterior=LOW;
    }else if(anterior==LOW){
      ledState=HIGH;
      anterior=HIGH;
    }
  }
  digitalWrite(ledPos,ledState);
}

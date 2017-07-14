int lectura;
int led;
boolean estado;
boolean anterior;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);

  estado = LOW;
  anterior = LOW;
  led = LOW;
}

void loop() {
  
  lectura = digitalRead(5);

  if(lectura == LOW){
    if(estado != anterior ){
      //estado = anterior;
      led = !led;  
    }
  }

  anterior = lectura;

  digitalWrite(10, led);
}

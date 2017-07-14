int lectura;
int led;
int estado;
int anterior;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);

  estado = 0;
  anterior = 0;
  //led = LOW;
}

void loop() {
  
  lectura = digitalRead(5);

  if(lectura == LOW){
    if(anterior != lectura ){
      estado = 1 - estado;
      //led = !led;  
    }
  }

  anterior = lectura;

  digitalWrite(10, estado);
}

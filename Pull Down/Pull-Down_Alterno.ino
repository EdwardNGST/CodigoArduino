int lectura;
int estado;
int anterior;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);

  lectura = LOW;

  estado = 0;
  anterior = 0;
}

void loop() {
  
  lectura = digitalRead(5);

  if(lectura == HIGH){
    if(anterior != lectura ){
      estado = 1 - estado;  
    }
  }  

  anterior = lectura;

  digitalWrite(10, estado);
}

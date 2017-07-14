int ledRojo = 4;
int ledAmarillo = 3;
int ledVerde = 2;
int tiempo = 60;
int estado = 1;
int rojo, amarillo, verde;
void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  rojo=HIGH;
  verde=LOW;
  amarillo=LOW;
}
void loop() {
  if(estado == 1 && tiempo == 0){
    verde = HIGH;
    amarillo = LOW;
    rojo = LOW;
    estado = 0;
    tiempo = 60;
  }else{
    if(estado == 0 && tiempo == 10){
      verde= LOW;
      amarillo= LOW;
      rojo= LOW;
      estado = 2;
    }else{
      if(tiempo == 0){
        verde = LOW;
        amarillo = LOW;
        rojo = HIGH;
        estado = 1;
        tiempo = 60;
      }
    }
  }
}

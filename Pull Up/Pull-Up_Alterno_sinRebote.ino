int contador;
int periodo;
int led;
int boton;

unsigned long tiempo;
int tiempo_transcurrido;

int lectura;

boolean estado;
boolean anterior;

void setup() {
  contador = 0;
  periodo = 10;
  led = LOW;
  boton = 0;
  
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);

  lectura = HIGH;// esto cambia segun el 
  // resistor pull-up o pull-down utilizado

  // Obtener el tiempo
  tiempo = millis();

  estado = LOW;
  anterior = LOW;
  
}

void loop() {
  // retardo = tiempo transcurrido
  
  lectura = digitalRead(5);
  tiempo_transcurrido = (millis() - tiempo);
  
  if(tiempo_transcurrido >= periodo){
    if(lectura == LOW){
      contador = contador+1;
    }else{
      contador = 0;
      boton = 0;
    }
    
    if(contador == periodo){
      contador = 0;
      boton = 1;
      tiempo = millis();
    }
    
    //digitalWrite(10,led);
  }
    
    if(boton == 1){
      if(anterior != lectura ){
        estado = 1 - estado; 
      }
    }

  anterior = lectura;

  digitalWrite(10, estado);
  
}

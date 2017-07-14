int lectura;
int estado;
int anterior;

int boton;
int contador;
int periodo;
int led;

unsigned long tiempo;
int tiempo_transcurrido;

void setup() {
  contador = 0;
  periodo = 10;
  led = LOW;
  boton = 0;
  
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);

  lectura = LOW; 

  // Obtener el tiempo
  tiempo = millis();

  estado = LOW;
  anterior = LOW;
  
}

void loop() {
    // retardo = tiempo transcurrido
  tiempo_transcurrido = (millis() - tiempo);
  lectura = digitalRead(5);
  
  if(tiempo_transcurrido >= periodo){
    if(lectura == HIGH){
      contador = contador+1;
    }else{
      contador = 0;
      boton = 0;
    }
    
    if(contador == 10){
      contador = 0;
      boton = 1;
      tiempo = millis();
    }

   // digitalWrite(10,led);
  }

  if(boton == 0){
    if(anterior != lectura ){
      estado = 1 - estado;  
    }
  }  

  anterior = lectura;

  digitalWrite(10, estado);
}

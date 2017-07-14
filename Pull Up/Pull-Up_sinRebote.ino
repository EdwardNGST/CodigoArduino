int contador;
int periodo;
int led;

unsigned long tiempo;
int tiempo_transcurrido;

int lectura;

void setup() {
  contador = 0;
  periodo = 10;
  led = LOW;
  
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);

  lectura = HIGH;

  // Obtener el tiempo
  tiempo = millis();
  
}

void loop() {
  // retardo = tiempo transcurrido
  tiempo_transcurrido = (millis() - tiempo);
  lectura = digitalRead(5);
  
  if(tiempo_transcurrido >= periodo){
    if(lectura == LOW){
      contador = contador+1;
    }else{
      contador = 0;
      led = LOW;
    }
    
    if(contador == 10){
      contador = 0;
      led = HIGH;
    }
    tiempo = millis();

    digitalWrite(10,led);
    /*
    if(led == 0){
      digitalWrite(10,LOW);
    }else{
      if(led == 1){
        digitalWrite(10,HIGH); 
      }
    }*/
  }
  /*
  boton = digitalRead(5);
  
  if(boton == LOW){
    digitalWrite(10, HIGH);
  }else{
    digitalWrite(10, LOW);  
  }*/
}

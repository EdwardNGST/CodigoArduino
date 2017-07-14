int ledRojo = 4;
int ledAmarillo = 3;
int ledVerde = 2;
int tiempo = 60;
int estado = 1;

//Variables del Potenciometro
int pot=0;
int lectura=1;

//leds
int rojo, amarillo, verde;

int estadoPot=0;
void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  rojo=HIGH;
  verde=LOW;
  amarillo=LOW;
}

void loop() {
  lectura=analogRead(pot);
  
  Serial.print("Lectura potenciometro: ");
  Serial.println(lectura);
  

  
  /*
  if(lectura>=851 && lectura<=1023){
    tiempo=60;
  }
  if(lectura>=681 && lectura<=850){
    tiempo=50;
  }
  if(lectura>=511 && lectura<=680){
    tiempo=40;
  }
  if(lectura>=341 && lectura<=510){
    tiempo=30;
  }
  if(lectura>=171 && lectura<=340){
    tiempo=20;
  }
  if(lectura>=0 && lectura<=170){
    tiempo=10;
  }
  */
  if(estado == 1 && tiempo == 0){
    verde = HIGH;
    amarillo = LOW;
    rojo = LOW;
    estado = 0;
    if(lectura>512){
      tiempo=60;
    }
    if(lectura<=512){
      tiempo=30;
    }
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
        if(lectura>512){
          tiempo=60;
        }
        if(lectura<=512){
          tiempo=30;
        }
      }
    }
  }
  //Decremento del tiempo
  tiempo = tiempo - 1;
      
  if(estado == 2){
    amarillo = HIGH;
    estado = 3;
  }else if(estado==3){
    amarillo = LOW;
    estado = 2;
  }
      
  digitalWrite(ledVerde, verde);
  digitalWrite(ledAmarillo, amarillo);
  digitalWrite(ledRojo, rojo);
  //Establecer un retardo
  delay(500);
  Serial.print("Tiempo: ");
  Serial.println(tiempo);
}

  // Valores iniciales
  int ledActual;
  int ledAnterior;
  int direccion;
  int boton;
  boolean pausa;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
   
  ledActual = 4;
  ledAnterior = 11;
  direccion = 0;
  boton = LOW;
  pausa = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Leer el boton
    boton = digitalRead(12);
    delay(500);
    
    if(boton == HIGH){
      pausa = !pausa;
    }
    
    if (pausa){
      digitalWrite(ledAnterior, LOW);
      digitalWrite(ledActual, HIGH);
    
      if (direccion == 0){
        //Hacia arriba
        ledAnterior = ledActual;
        ledActual = ledActual + 1;
      
        // Preguntar por los limites
        if(ledActual == 11){
          direccion = 1;
        }
    
      }else{
        // Hacia abajo
        ledAnterior = ledActual;
        ledActual = ledActual - 1;
      
        // Preguntar por los limites
        if(ledActual == 4){
          direccion = 0; 
        }
      }
    }
}

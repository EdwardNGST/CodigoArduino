  // Valores iniciales
  int ledActual;
  int ledAnterior;
  int direccion;


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
   
  ledActual = 4;
  ledAnterior = 11;
  direccion = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledAnterior, LOW);
  digitalWrite(ledActual, HIGH);
  delay(250);
    
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

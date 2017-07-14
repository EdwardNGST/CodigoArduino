/********************************************************
Practica 07:Lectura analogica de un sensonr (potenciometro)
  Mostrar la lectura en el monitor serial
********************************************************/
int pot=0;
int lectura=0;

void setup(){
  //Inicializacion del puerto serial
  Serial.begin(9600);
}

void loop(){
  //Lectura del potenciometro
  lectura=analogRead(pot);
  
  //escribir al puerto serial
  Serial.print("Lectura potenciometro: ");
  Serial.println(lectura);
}

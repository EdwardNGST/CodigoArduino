/*
* Practica 07: Lectura analogica de un sensor (potenciometro).
*              Mostrar a lectura en el monitor serial.
*
*
*/
  // Variables globales
  int pot = 0;
  int lectura;

void setup() {
  // put your setup code here, to run once:
  //Inicializacion del puerto serial
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Lectura del potenciometro
  lectura = analogRead(pot);

  // Escribir al puerto serial
  Serial.print("Lectura potenciometro: ");
  Serial.println(lectura);

}

// Práctica encender LED con botón pulsador y luego apagar LED con el mismo
//boton pulsador
const int LED =10;
const int BOTON = 5;
int val = 0; //val se emplea para almacenar el estado del boton
int state = 0; // 0 LED apagado, mientras que 1 encendido
int old_val = 0; // almacena el antiguo valor de val
int ledState;

unsigned long tiempo;
int tiempo_transcurrido;
int contador;
int periodo;

void setup(){  // definir si la variable es de entrada // o salida.
 pinMode(LED,OUTPUT); // establecer que el pin digital es una señal de salida
 pinMode(BOTON,INPUT); // y BOTON como señal de entrada
 
  contador = 0;
  periodo = 10;
  tiempo = millis();
  ledState=LOW;
  
}
void loop() {       // loop = realice un lazo continuamente
tiempo_transcurrido = (millis() - tiempo);
val= digitalRead(BOTON); // lee el estado del Boton
if ((val == HIGH) && (old_val == LOW)){
state=1-state;
delay(10);
}
old_val = val; // valor del antiguo estado
if (state==1){
  if(tiempo_transcurrido >= periodo){
    if(val == LOW ){
      contador = contador+1;
    }else{
      contador = 0;
      ledState = LOW;
    }
    
    if(contador == 10){
      contador = 0;
      ledState = HIGH;
    }
    tiempo = millis();

    digitalWrite(10,LOW);
  }
}
else{
  if(tiempo_transcurrido >= periodo){
    if(val == LOW ){
      contador = contador+1;
    }else{
      contador = 0;
      ledState = LOW;
    }
    
    if(contador == 10){
      contador = 0;
      ledState = HIGH;
    }
    tiempo = millis();

    digitalWrite(10,HIGH);
  }
}
}



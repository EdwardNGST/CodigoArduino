  // Variablles globales
  int ledPin[] = {2,3,4,5,6,7,8,9};
  int leds = 8;
  int pot = 0;
  int incremento;
  int lectura;

void setup() {
  // put your setup code here, to run once:
    for(int i = 0; i < leds; i++){
      pinMode(ledPin[i],  OUTPUT);
    }
      
    incremento = 1023 / leds;
}

void loop() {
  // put your main code here, to run repeatedly:
      for(int i = 0 , k = 0; i < leds; i++){
      k += incremento;
      if(k <= lectura){
        digitalWrite(ledPin[i], HIGH);
      }else{
        digitalWrite(ledPin[i], LOW);
      }
    }
}

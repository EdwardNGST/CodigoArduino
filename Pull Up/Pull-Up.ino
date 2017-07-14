int lectura;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);

  lectura = HIGH;
}

void loop() {
  
  lectura = digitalRead(5);
  
  if(lectura == LOW){
    digitalWrite(10, HIGH);
  }else{
    digitalWrite(10, LOW);  
  }
}

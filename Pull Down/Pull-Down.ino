int boton;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);

  boton = LOW;
}

void loop() {
  
  boton = digitalRead(5);
  
  if(boton == HIGH){
    digitalWrite(10, HIGH);
  }else{
    digitalWrite(10, LOW);  
  }
  delay(500);
}

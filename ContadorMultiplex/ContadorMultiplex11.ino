int display1;
int display2;
boolean multiplexar;

void setup() {
  // put your setup code here, to run once:
  display1 =8;
  display2 =12;
  multiplexar = false;
  
  pinMode(display1, OUTPUT);
  pinMode(display2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    //Salida ---v
  
  //Multiplexar
  multiplexar = !multiplexar;
  
  //Led a encender
  if(multiplexar){
    digitalWrite(display1,HIGH);
    digitalWrite(display2,LOW);
  }else{
    digitalWrite(display1,LOW);
    digitalWrite(display2,HIGH);
  }
  
  //Retardo 
  delay(60);
}

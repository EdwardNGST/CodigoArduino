//int segmentos[7] = {8,7,6,5,4,3,2};
int segmentos[7] = {2,3,4,5,6,7,8};
int digitos[][7] = {
        //a,b,c,d,e,f,g
        {1,1,1,1,1,1,0},
        {0,1,1,0,0,0,0},
        {1,1,0,1,1,0,1},
        {1,1,1,1,0,0,1},
        {0,1,1,0,0,1,1},
        {1,0,1,1,0,1,1},
        {1,0,1,1,1,1,1},
        {1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1},
        {1,1,1,1,0,1,1}};
int unidades;
int decenas;
int display1;
int display2;
unsigned long tiempo;
int retardo;
boolean multiplexar;

// The setup() method runs once, when the sketch starts  
void setup(){   

  // Your setup code goes here 
  
  display1 = 9;
  display2 = 10;
  multiplexar = false;
  
  
  unidades = 0;
  decenas = 0;
  retardo = 0;
  tiempo = millis();

  for(int i = 0; i < 7; i++){
          pinMode(segmentos[i], OUTPUT);
  }
  
  pinMode(display1, OUTPUT);
  pinMode(display2, OUTPUT);
}

// the loop() method runs over and over again, 
// as long as the Arduino has power 
void loop(){

  // Your loop code goes here 
  //Multiplexar;
  retardo = millis() - tiempo;

  if(retardo >= 1000){
    //Siguiente unidad
    unidades++;
    if(unidades == 10){
            unidades = 0;
            
            //Siguiente decena
            decenas++;
            if(decenas == 10){
                    decenas = 0;
            }
    }
    
    tiempo = millis();
  }

  multiplexar = !multiplexar;
  
  //Led a encender
  if(multiplexar){
          digitalWrite(display1, multiplexar);
          
          // Escribir el numero
          for(int i = 0; i < 7; i++){
                  digitalWrite(segmentos[i], !digitos[unidades][i]);
          }
                    
  }else{
          digitalWrite(display2, multiplexar);
  
          // Escribir el numero
          for(int i = 0; i < 7; i++){
                  digitalWrite(segmentos[i], !digitos[decenas][i]);
          }
  }
  delay(10);
}


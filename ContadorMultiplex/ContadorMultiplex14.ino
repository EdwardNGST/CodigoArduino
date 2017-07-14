  // Variables globales a, b, c, d, e, f, g
  int segmentos[] = {4, 5, 6, 7, 8, 9, 10};
  int digitos[][10] =  {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9 
    };

  boolean multiplexar;
  int retardo;
  unsigned long tiempo;
  
  int decenas;
  int unidades;
  
  int botonP;
  int botonR;
  boolean pausa;
  boolean reiniciar;
  
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++){
      pinMode(segmentos[i], OUTPUT);
    }
    
    // Inicializar display
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    
    multiplexar = false;
    
    // Obtener el tiempo
    tiempo = millis();
    
    // Inicializar el contador
    decenas = 0;
    unidades = 0;
    
    // Boton
    botonP = LOW;
    botonR = LOW;
    pausa = false;
    reiniciar = false;
}

void loop() {
  // put your main code here, to run repeatedly:
    retardo = (millis() - tiempo);
    
    // Aqui lee los botones
    botonP = digitalRead(2);
    botonR = digitalRead(3);
    
    /*if(botonP == HIGH){
      pausa = !pausa;
    }*/
    
    if(botonR == HIGH){
      reiniciar = !reiniciar;
    }
    
    if(retardo >= 1000){// el tiempo que tarda en incrementarse
      // Aqui se pone el boton de pausa
      if(botonP==HIGH){
        //Algoritmo del contador
    
        unidades++;
        if (unidades == 10){
          unidades = 0;
          decenas++;
        
          if(decenas == 10){
            decenas = 0;
          }
        }
        tiempo = millis();
      }
    }
    
    if(reiniciar){
      unidades = 0;
      decenas = 0;
      
      reiniciar = !reiniciar;
      if(reiniciar){
        unidades++;

        if (unidades == 10){
          unidades = 0;
          decenas++;
        
          if(decenas == 10){
            decenas = 0;
          }
        }
        tiempo = millis();
      }
    }
      
    
    multiplexar = !multiplexar;
    
    if (multiplexar){
      // Encender el display
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      
      for(int j = 0; j < 7; j++){
        // Mostrar unidades
        digitalWrite(segmentos[j], !digitos[unidades][j]);
      }
    }else{
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      
      for(int j = 0; j < 7; j++){
        // Mostrar decenas
        digitalWrite(segmentos[j], !digitos[decenas][j]);
      }
    }
    delay(10);
}

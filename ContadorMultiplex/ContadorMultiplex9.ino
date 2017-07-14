  //Variables globales         a, b, c, d, e, f, g
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
  long tiempo;
  
  int decenas;
  int unidades;
  
  int botonP;
  boolean pausa;
  
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++){
      pinMode(segmentos[i], OUTPUT);
    }
    
    // Inicializar display
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    
    pinMode(3, INPUT);
    
    multiplexar = false;
    
    // Obtener el tiempo
    tiempo = millis();
    
    // Inicializar el contador
    decenas = 0;
    unidades = 0;
    
    // Boton
    botonP = LOW;

    pausa = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  retardo = (int) (millis() - tiempo);
    
    // Aqui lee los botones
    botonP = digitalRead(3);
    delay(500);
    
    if(botonP == HIGH){
      pausa = !pausa;
    }
    
    if(retardo >= 1500){// el tiempo que tarda en incrementarse
      // Aqui se pone el boton de pausa
      if(pausa){
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
    
    multiplexar = !multiplexar;
    
    if (multiplexar){
      // Encender el display
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      
      for(int j = 0; j < 7; j++){
        // Mostrar unidades
        digitalWrite(segmentos[j], digitos[unidades][j]);
      }

    }else{
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      
      for(int j = 0; j < 7; j++){
        // Mostrar decenas
        digitalWrite(segmentos[j], digitos[decenas][j]);
      }
    }
    
    delay(200);
}

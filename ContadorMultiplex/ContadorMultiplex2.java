
import muvium.compatibility.arduino.*; 

public class ContadorD extends Arduino{ 
	
	//Variables globales         a, b, c, d, e, f, g
	int[] segmentos = new int[] {4, 5, 6, 7, 8, 9, 10};
	int[][] digitos = new int[][] {
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
	int numero; 
	int retardo;
	long tiempo;
	
	// The setup() method runs once, when the sketch starts  
	public void setup(){   
	
		// Your setup code goes here 
		for (int i = 0; i < 7; i++){
			pinMode(segmentos[i], OUTPUT);
		}
		
		// Inicializar display
		pinMode(11, OUTPUT);
		pinMode(12, OUTPUT);
		
		multiplexar = false;
		numero = 5;
		
		// Obtener el tiempo
		tiempo = millis();

	}

	// the loop() method runs over and over again, 
	// as long as the Arduino has power 
	public void loop(){

		// Your loop code goes here 
		
		retardo = (int) (millis() - tiempo);
		
		// Aqui lee los botones
		
		if(retardo >= 1500){// el tiempo que tarda en incrementarse
			// Aqui se pone el boton de pausa
			//Algoritmo del contador
			// dentro de este if se pone el contador
			numero++;
			if (numero == 10){
				numero = 5;
			}
			tiempo = millis();
		}
		
		multiplexar = !multiplexar;
		
		if (multiplexar){
			// Encender el display
			digitalWrite(11, LOW);
			digitalWrite(12, HIGH);
			
			//			for(int i = 0; i < 10; i++){
			for(int j = 0; j < 7; j++){
				// Mostrar unidades
				digitalWrite(segmentos[j], digitos[numero][j]);
			}
			//			}

		}else{
			digitalWrite(11, HIGH);
			digitalWrite(12, LOW);
			//			for(int i = 0; i < 10; i++){
			for(int j = 0; j < 7; j++){
				// Mostrar decenas
				digitalWrite(segmentos[j], digitos[numero - 1][j]);
			}
			//			}
		}
		
		delay(200);
		
		/*// Encender el display
		digitalWrite(11, LOW);
		digitalWrite(12, LOW);*/

		/*		
		// Mostrar digitos
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 7; j++){
				digitalWrite(segmentos[j], digitos[i][j]);
			}
			delay(500);
		}*/
	}
}



import muvium.compatibility.arduino.*; 

public class RastreoLedPot extends Arduino{ 
	// Variablles globales
	int ledPin[] = {2,3,4,5,6,7,8,9};
	int leds = 8;
	int pot = 0;
	int incremento;
	int lectura;

	// The setup() method runs once, when the sketch starts  
	public void setup(){   
	
		// Your setup code goes here 
		for(int i = 0; i < leds; i++){
			pinMode(ledPin[i], 	OUTPUT);
		}
			
		incremento = 1023 / leds;
	}

	// the loop() method runs over and over again, 
	// as long as the Arduino has power 
	public void loop(){

		// Your loop code goes here 

		lectura = analogRead(pot);
		
		for(int i = 0 , k = 0; i < leds; i++){
			k += incremento;
			if(k <= lectura){
				digitalWrite(ledPin[i], HIGH);
			}else{
				digitalWrite(ledPin[i], LOW);
			}
		}
			
	}
}


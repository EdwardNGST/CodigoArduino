
import muvium.compatibility.arduino.*; 

public class ContadorLed extends Arduino{ 
	
	// Declaración de variables

	int display1;
	int display2;
	boolean multiplexar;

	// The setup() method runs once, when the sketch starts  
	public void setup(){   
	
		// Your setup code goes here 
		display1 = 8;
		display2 = 12;
		multiplexar = false;
  
		pinMode(display1, OUTPUT);
		pinMode(display2, OUTPUT);

	}

	// the loop() method runs over and over again, 
	// as long as the Arduino has power 
	public void loop(){

		// Your loop code goes here 
		//Salida ---v
  
		//Multiplexar
		multiplexar = !multiplexar;
  
		//Led a encender
		if(multiplexar){
			digitalWrite(display1, HIGH);
			digitalWrite(display2, LOW);
		}else{
			digitalWrite(display1, LOW);
			digitalWrite(display2, HIGH);
		}
  
		//Retardo 
		delay(60);
  
		//Salida---^

	}
}


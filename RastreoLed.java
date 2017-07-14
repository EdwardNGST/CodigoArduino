Proceso RastreoLed
	//Valores iniciales
	ledActual<-1;
	ledAnterior<-0;
	direccion<-0;
	
	//Ciclo infinito
	Mientras 1 == 1 Hacer
		//Mostrar el valor actual
		Escribir ledActual;
		
		//Avanzar
		Si direccion == 0 Entonces
			//Hacia arriba
			ledAnterior<-ledActual;
			ledActual<-ledActual + 1;
			
			//Preguntar por los limites
			Si ledActual == 8 Entonces
				direccion<-1;
			Fin Si
		Sino
			//Hacia abajo
			ledAnterior<-ledActual;
			ledActual<-ledActual - 1;
			
			//Preguntar por los limites
			Si ledActual == 1 Entonces
				direccion<-0;
			Fin Si
		Fin Si
	Fin Mientras
FinProceso

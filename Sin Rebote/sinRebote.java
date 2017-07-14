Proceso sinRebote
	contador<-0;
	periodo<-10;
	led<-0;
	
	Mientras (este_corriendo) Hacer
		Si (tiempo_transcurrido == periodo) Entonces
			Si (lectura == ALTO) Entonces
				contador<-contador+1;
			Sino
				contador<-0;
				led<-0;
			FinSi
			
			Si (contador == 10) Entonces
				contador<-0;
				led<-1;
			FinSi
		
			Escribir led;
		FinSi
	Fin Mientras
	
FinProceso

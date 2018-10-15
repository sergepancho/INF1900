
#include <avr/io.h> 
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include "can.h"
#include "memoire_24.h"

//Faire un robot pouvant se faire bronzer...

//Si la lumière est basse (en cachant la photorésistance), la DEL prendra la couleur verte.

//Si la lumière est à un bon niveau (lumière ambiante), la DEL tournera à l'ambré.

//Si la lumière est trop forte (photorésistance sous une lampe de poche), la DEL devient rouge.

void initialisationUART ( void ) 
{

		// 2400 bauds. Nous vous donnons la valeur des deux

		// premier registres pour vous éviter des complications

		UBRR0H = 0;

		UBRR0L = 0xCF;

		// permettre la reception et la transmission par le UART0

		UCSR0A = _BV(MPCM0);//: Multi-processor Communication Mode

		UCSR0B =_BV(RXEN0)|_BV(TXEN0);

		// Format des trames: 8 bits, 1 stop bits, none parity

		UCSR0C = _BV(UCSZ01)|_BV(UCSZ00);//_BV(USBS0); STOP BIT MIS A 1

}
	//SI CA NE MARCHE SET LES BITS D<A<INTERRUPTION DES REGSTRES A 1;

	//affichage a l</cran par le programme EN LIGNE DE COMMANDE$SERIEviausb -1;

    // De l'USART vers le PC

void transmissionUART ( uint8_t donnee )
 {
	/* 
	Wait for empty transmit buffer
	 */
	while
	 ( !( UCSR0A & (1<<UDRE0)) )

	/* 
	Put donnee into buffer, sends the donnee
	 */
	UDR0 = donnee;
}




 int main()
{
	DDRA = 0xff; //Mode sortie
	DDRA = 0xff; //Mode sortie
	DDRC = 0xff; //Mode sortie
	DDRD = 0;	//Mode entree

	for(;;)
	{
		can Can;
		uint8_t valeur=Can.lecture(1)>>2;
		char nombre[100];
		snprintf(nombre,sizeof(nombre,"%d\n",valeur);
		for(int i=0;i<sizeof(nombre);i++)
		{
			transmissionUART(nombre[i]);
		}
		
	}

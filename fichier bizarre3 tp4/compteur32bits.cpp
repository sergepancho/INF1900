/*
 * Nom: compteur 32 bits
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple simple de programme 
 * Version: 1.1
 */
#include <iostream>
#include <avr/io.h>
#define F_CPU 80000000
#include <util/delay.h>

//PLACER UN CAVALIER EST IMORTANT VOIR ESCTION QUI PARLE DES CAVALIERS
//LE CAVALIER EST UN CIRCUIT AVEC DES BROCHES PLACE A CHAQUE EXTREMITE DE LA CONNEXION
//PLACER UN CAVALIER VEUT DIRE RELIER ELECTRIQUEMENT CE CIRCUIT
//DANS L<EXERCICE JE RELIE LE CAVALIER DBGEN AU BROCHES D0 ET D1
	    void initialisationUART ( void ) {

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

void transmissionUART ( uint8_t donnee ) {
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


initialisationUART();
Memoire24CXXX mem=Memoire24CXXX ();
  DDRA = 0xff; // PORT A est en mode sortie
  DDRB = 0xff; // PORT B est en mode sortie
  DDRC = 0xff; // PORT C est en mode sortie
  DDRD = 0; // PORT D est en mode sortie
  
  for(;;)  // boucle sans fin
	{
 
    char mots[21] = "Le robot en INF1900\n";

uint8_t i, j;

for ( i = 0; i < 100; i++ ) {//100 cycles pour permettre la transmittion effective

for ( j=0; j < 20; j++ ) {

transmissionUART ( mots[j] );

}

}

for (uint16_t j=0; j < 20; j++ ) 
{
      uint8_t lu=  mem.lecture(j,&mots[j]);
      std::cout<< lu<<endl;//possible?
        if(lu=FF)
        break;

}
	return 0; 
	
}

	
}



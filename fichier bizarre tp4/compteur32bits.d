/*
 * Nom: compteur 32 bits
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple simple de programme 
 * Version: 1.1
 */

#include <avr/io.h>
#define F_CPU 80000000
#include <util/delay.h>
#include "memoire_24.h"
#include "memoire_24.cpp"
	

int main()
{
Memoire24CXXX mem;
  DDRA = 0xff; // PORT A est en mode sortie
  DDRB = 0xff; // PORT B est en mode sortie
  DDRC = 0xff; // PORT C est en mode sortie
  DDRD = 0; // PORT D est en mode sortie
  
  for(;;)  // boucle sans fin
	{
 
		//attenuer_vert();

		attenuer_rouge();
			
	}
//inserer le fichier de dependance
//ecriture(0x00,00101010);//*commmenbt ecrire la valeur de p sur 8 bits utilise t<il la table askyy?
//_delay_ms(5);
//ici il  faut signakler un changement d<adrese?
char[] text =  "*P*O*L*Y*T*E*C*H*N*I*Q*U*E* *M*O*N*T*R*E*A*L*";

for ( int i = 0 ;i <30; i++)
{
	mem.ecriture(i+8,text[i]);//*voir si l<adresse sera +8
	_delay_ms(5);
}
Lecture(0x00,0x00,8bi)

for ( int i = 0 ;i <30; i++)
{
	if(mem.lecture(i+8,text[i])==text[i])//faire en sorte que l<adress commence a 0
	  PORTA=0b10;
	 else
	  PORTA=0b01;
	
	
	//*voir si l<adresse sera +8
	
}
/*Vous devrez faire un programme qui écrit la chaîne de caractères
 « *P*O*L*Y*T*E*C*H*N*I*Q*U*E* *M*O*N*T*R*E*A*L*»
  suivi d'un 0x00 en mémoire externe. La chaîne commencera à l'adresse
   0x00. Faire en sorte que votre programme puisse aller relire la
    chaîne en question. Comparez la chaîne de caractères envoyée à
     la mémoire et celle relue. Il suffira de faire afficher la DEL
      en vert si elles sont identiques et en rouge dans le cas 
      contraire. Cette démarche est un peu douteuse au départ,
       mais elle se raffinera avec le problème 3.
        Il faut prévoir un délai de 5 ms après l'écriture d'un octet en mémoire et
         l'accès suivant à la mémoire. De cette façon, la mémoire peut 
compléter son cycle d'écriture sans problème. */






	return 0; 
	
}


/* 0 
 * wait(3000- x);
 * x-=5
 * 1
 * 
 * wait(x)
 * 
 * 
 * */


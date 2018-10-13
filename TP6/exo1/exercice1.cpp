
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t minuterieExpiree;
volatile uint8_t boutonPoussoir=0;
volatile  double compteur=0;
volatile bool pesepuisrelache=false;
enum Etat { INIT,vert,rouge};
volatile Etat state=INIT;
Etat futur=vert;



ISR(TIMER1_COMPA_vect)
{ 

	minuterieExpiree = 1;
	//il a etet  incrementer 2 fois
}
//3fois le temps
ISR(INT0_vect)
{
	if(PIND&0x04){
		
	_delay_ms(10);
		if (PIND & 0x04)
		{
		 boutonPoussoir = 1;
		} else
      boutonPoussoir=0; 
      }
      
      EIFR |= (1 << INTF0) ;
 }

void partirMinuterie(uint16_t duree)
{

	minuterieExpiree = 0; 

	// mode CTC du timer 1 avec horloge divise par 1024
	// interruption aprEs la dure sp

	TCNT1 = 0;

	OCR1A = duree*3;//il atteint plusieurs fois

	TCCR1A = 0;

	TCCR1B = _BV(WGM12) | _BV(CS12) | _BV(CS10);
	//MODE ctc ET CLOCK/1024

	TCCR1C = 0;

	TIMSK1 = _BV(OCIE1A);
}


void initialisation(void)
{

	// cli est une routine qui bloque toutes les interruptions.

	// Il serait bien mauvais d'�tre interrompu alors que

	// le microcontroleur n'est pas pr�t...

	cli();

	// configurer et choisir les ports pour les entr�es

	// et les sorties. DDRx... Initialisez bien vos variables
	DDRA = 0xff; //Mode sortie
	DDRB = 0xff;
	DDRC = 0xff; //Mode sortie
	DDRD = 0x00;	//Mode entree

	// cette proc�dure ajuste le registre EIMSK
	// de lATmega324PA pour permettre les interruptions externes

	EIMSK |= (1 << INT0);

	// il faut sensibiliser les interruptions externes aux

	// changements de niveau du bouton-poussoir

	// en ajustant le registre EICRA

	EICRA |= (1 << ISC00);

	// sei permet de recevoir � nouveau des interruptions.

	sei();
}

//ou doit on faire l'initialisation?

int main()
{
	for(;;){
	initialisation();
		//
			compteur =0;
	//partirMinuterie(F_CPU/10240);///wait 1/10s
	//_delay_ms(101);
	//if(minuterieExpiree==1){
		//while(boutonPoussoir!=0)
	///wait 1/10s et envoie un signal
	/* while(1)
	  {
		if(boutonPoussoir==1)
			PORTA=0b01;
		if((PIND&0b100)==0){
				PORTA=0;
				boutonPoussoir=0;
			}
			
	  }
  }*/

				
 // if(boutonPoussoir==1){

 boutonPoussoir=0;//faire lesetat
 while(boutonPoussoir==0){}//quand le bouton <est pas appuy/ ne rien faire

		do
		{
			
			
			// cli();

			
			 //envoie le signal 10 fois par seconde
                  //    partirMinuterie(3906);//attendre 1/10 secone et augmente le cmpteur de 1;-200 pour 1 seconde
                     partirMinuterie(2600);//.*un changement entre 100*
         //_delay_ms(110);//attendre 1/10 de secondes pour eviter la boucle infini
		
                     //PORTA=0b10;//vert
                while(minuterieExpiree==0){};
                compteur+=10;
             //  		} while (compteur!=120 && ( PIND&04));//si le bouton est toujours appuye ou bien si le compteur!= 
		} while (compteur!=120 && ( PIND&04));//si le bouton est toujours appuye ou bien si le compteur!= 120



   /* PORTA=0b01;
     _delay_ms(2000);
     * */
     
  //   }
 // }


		// Une interruption s'est produite. Arr�ter toute

		// forme d'interruption. Une seule r�ponse suffit.

		//cli();
		// Verifier la r�ponse
		
			for(int i=0;i<5;i++)
			{
				PORTA=0b10;//vert
				_delay_ms(50);
				PORTA=0b00;//clignoter 1/2 seconde
				_delay_ms(50);
		    }
		
		
		_delay_ms(2000);//attendre 2 secondes
		//allumer rouge
		//25
	unsigned int comp =compteur/2;
		if((compteur)==30){
		PORTA=0b10;
		_delay_ms(5000);}
		for(unsigned int i=0;i<comp;i++)//clignote compteur/2 (5 fois)si compteur=10
			{
				PORTA=0b01;
				_delay_ms(250);
				PORTA=0b00;//clignoter
				_delay_ms(250);//le delai total est egale a 400 *5 foisdonne 2secondes
				PORTA=0b01;
				_delay_ms(250);
				PORTA=0b00;
				_delay_ms(250);
				
		    }
		    PORTA=0b10;//vert 1 secondes
		_delay_ms(1000);//attendre 1secondes
		
		PORTA=0b00;//eteint
		//}
}

//int main()
//{
	//initialisation();
	
	////enum Etat { INT,ambre,vert,rouge,eteint,vert2};
	////Etat state = eteint;
	//for (;;)//comment appele l<interruption
	//{
		/**/
		
		
	////	while(boutonpoussoir==1 && compteur!=120)
		////{//il incrementera
		////if(minuterieExpire==1)
		//partirMinuterie(00000001);//mettre le bon top ici a chaue 1/10 s il envoie un signal d<interruption
		////partirMinuterie(10);
		////le compteur increment une fois chaue 1/10 seconde et atteindra 10 fois a la seconde
	    ////}
	    
	     //if(minuterieExpire==0)
	    //{
	    //PORTA=0b01;
	    //_delay_ms(10000);
	    //}
	    //if(minuterieExpire==1)
	    //{
	    //PORTA=0b10;
	    //_delay_ms(10000);
	    //}
		////if(boutonpoussoir==0 ||compteur==120)
		////{
			////for(int i=0;i<5;i++)
			////{
				////PORTA=0b01;
				////_delay_ms(50);
				////PORTA=0b00;//clignoter
				////_delay_ms(50);
		    ////}
		 	////_delay_ms(2000);//2s
			////PORTA=0b10;//rouge
			////for(int i=0;i<compteur/2;i++)//clignote compteur/2 (5 fois)si compteur=10
			////{
				////PORTA=0b10;
				////_delay_ms(200);
				////PORTA=0b00;//clignoter
				////_delay_ms(200);//le delai total est egale a 400 *5 foisdonne 2secondes
		    ////}
		     ////PORTA=0b01;//vert
		     ////_delay_ms(1000);//1secondes
		     ////PORTA=0b00;
		     
		     
		     //return 0;
			
		////}
		 
	}


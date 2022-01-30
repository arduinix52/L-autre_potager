/**/

/*adding librairy*/

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

/*function initialisation*/

void interrupt_init(void){
	EICRA=0x04;			// External Interrupt Control Register A (1<<ISC10)
	EIMSK=0x02;			// External Interrupt Mask Register (1<<INT0)
}

void adc_init(void){

}

/*interruption function*/
ISR (INT1_vect){

}

ISR (ADC_vect){

}

void main(void){
	sei();				//enable global interruption
	while(1){

	}
}

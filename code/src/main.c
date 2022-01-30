/* L'autre potager
 * code by arduinix
 * for 'l autre potager' project
*/

/*librairy add-in*/

	#include<avr/io.h>
	#include<avr/interrupt.h>
	#include<util/delay.h>
/*init fonction*/
void interrupt_init(void){
	EICRA=0x04;				//External Interrupt Control (sense control)
	EIMSK=0x02;				//EIMSK External Interrupt Mask Register (external interrupt request enable)
	EIFR=0x02;
	sei();					//Enables interrupts by setting the global interrupt mask
}

void adc_init(void){
	ADMUX=0x61;				//ADC Multiplexer Selection Register (volatge reference,adjust result, read ADC)
	ADCSRA=0xFF;				//ADC Control and Status Register A (ADC enable,Start conversion, Auto trigger,Interrupt enable
	ADCSRB=0x03;				
}
void InitTimer0(void){
	TCNT0=0;				//set timer inital value
}
/*interrupt functions*/
ISR (INT1_vect){

	while(PIND & (1<<PIND3)){
		PORTD= (1<<6);	
		_delay_ms(500);
		PORTD= (0<<6);
		_delay_ms(500); 		//led blink
	}
}

ISR (ADC_vect){
	PORTD=0x40;	
}

void main(void){
	DDRD=0x40;
	DDRC=0x00;
	PORTD=0x40;				//setup IO
	
	interrupt_init();			//init interruption

	while(1){
	}	
}

#ifndef F_CPU
#define F_CPU 8000000UL 
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB |= 1 << PINB1;

	TCCR1A |= (1 << WGM11) | (1 << COM1A1);
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
	ICR1 = 39999;
	int offset = 800;

	while(1) {
		OCR1A = 2199 + offset;

		_delay_ms(1000);
		
		OCR1A = 3999 + offset;

		_delay_ms(1000);

		OCR1A = 3799 - offset;

		_delay_ms(1000);
		
		OCR1A = 1199 + offset;

		_delay_ms(1000);
		
	}

	return 0;
}
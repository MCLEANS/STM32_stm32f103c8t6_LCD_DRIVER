/*
 * LCD.h
 *
 *  Created on: Aug 24, 2019
 *      Author: MCLEANS
 */

#ifndef LCD_H_
#define LCD_H_

#define D0PORT	GPIOB
#define D0PIN	14
#define D1PORT 	GPIOB
#define D1PIN 	13
#define D2PORT	GPIOB
#define D2PIN	12
#define D3PORT	GPIOB
#define D3PIN	9
#define D4PORT	GPIOB
#define D4PIN	8
#define D5PORT	GPIOB
#define D5PIN	6
#define D6PORT	GPIOB
#define D6PIN	10
#define D7PORT	GPIOB
#define D7PIN	11
#define ENABLEPORT	GPIOA
#define ENABLEPIN	11
#define RWPORT	GPIOA
#define RWPIN	12
#define RSPORT GPIOB
#define RSPIN 5

#define TIMEDELAYBEFOREENABLE 40
#define TIMEDELAYBEFOREDISABLE  80

#include "stm32f10x.h"
#include "stdio.h"

namespace custom_drivers {



class LCD {
private:
	int duration = 0;
	char data[16];
	int row = 0;
	int column = 0;





public:
	LCD();
	virtual ~LCD();
	void enable_port(GPIO_TypeDef* PORT);
	void configure_pin_for_output(GPIO_TypeDef* PORT, uint8_t PIN);
	void configure_pins();
	void initialize();
	void delay_ms(int duration);
	void send_bit_to_pin(GPIO_TypeDef* PORT, uint8_t PIN, uint8_t state);
	void send_byte(char byte);
	void enable();
	void set_to_read_mode();
	void set_to_write_mode();
	void set_to_instruction_mode();
	void set_to_character_mode();
	void send_character(char character);
	void send_instruction(char byte);
	void clear();
	void newline();
	void send_string(char *data);
	void set_cursor_to_location(int row, int column);


};

} /* namespace custom_drivers */

#endif /* LCD_H_ */

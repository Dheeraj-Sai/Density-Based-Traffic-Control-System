#include <alcd.h>
#include <delay.h>
#include <mega16.h>
#include <stdio.h>
void main(void){
lcd_init(16);
lcd_clear();
DDRB = 0x01;
//set port B as output
DDRD = 0x00;
//set port D as input
while (1)
{
if (PIND.5 == 1 && PIND.7 == 0)
//check if the over voltage pin is high and the other is low
delay_ms(100);//delay for 0.1 sec to see if the fault is still happening
if (PIND.5 == 1 && PIND.7 == 0)
//check for the fault again
{
lcd_clear();
PORTB.0 = 1;
//activate the output and drive the relay
lcd_gotoxy(0,0);
lcd_puts("Operation status");
lcd_puts("OVER VOLTAGE ");
delay_ms(500);
//delay for fluctuations possibility
}
if (PIND.7 == 1 && PIND.5 == 0)
//check if under voltage pin is high and the other is low
delay_ms(100);//delay for the same purpose as before
if (PIND.7 == 1 && PIND.5 == 0)
//check the pin again
{
PORTB.0 = 1;
//activate the output and drive the relay
lcd_clear();
lcd_gotoxy(0,0);
lcd_puts("Operation status");
lcd_puts("UNDER VOLTAGE ");
delay_ms(500);
//delay for fluctuations possibility
}
if (PIND.5 == 0 && PIND.7 == 0)
//chck if there is no under voltage or over voltage
{
PORTB.0 = 0;
lcd_clear();
lcd_gotoxy(0,0);
lcd_puts("Operation status");
lcd_puts("NORMAL OPERATION");
}}}

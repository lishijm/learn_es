#include "adc.h"
#include "uart4.h"

extern void uart_init();
extern void printf(const char *fmt, ...);
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}
int main()
{
	unsigned short adc_value;
	uart_init();
	adc_init();

	while(1){
		delay_ms(2000);
		adc_value=get_value(1);
		adc_value = adc_value * 3300 / 65536;
		printf("adc_value = %dmv\r\n", adc_value);
	}
	return 0;
}

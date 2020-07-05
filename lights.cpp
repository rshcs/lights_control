
#include "lights.h"

LightsClass::LightsClass(uint8_t init_val)
{
	DDRL = 0xFF;
	DDRC = 0xFF;
	DDRA = 0xFF;

	PORTL = 0b00001111;
	PORTC = 0xFF;
	PORTA = 0;

	disp_time = millis();

}

void LightsClass::led_out(uint8_t inVal)
{
	inVal = ~inVal & 0b00001111;
	uint8_t port_val = PORTL & 0b11110000;
	port_val |= inVal;
	PORTL = port_val;
}

void LightsClass::led_ctrl(uint8_t inVal)
{
	uint8_t port_val = PORTL & 0b00001111;
	port_val |= inVal << 4;
	PORTL = port_val;
}

void LightsClass::led_light(uint8_t ledNum, uint8_t ctrlNum)
{
	led_out(ledNum);
	led_ctrl(ctrlNum);
}

void LightsClass::portl_config(uint8_t val1, uint8_t val2, uint8_t val3)
{
	PORTL = val1;  // <= A
	delay(MUX_DELAY);
	PORTL = val2;  // <= B
	delay(MUX_DELAY);
	PORTL = val3;  // <= C
	delay(MUX_DELAY);
}

void LightsClass::state_config()
{
	if (current_state == 1)
	{
		portl_config(0x19, 0x23, 0x47);
	}
	else if (current_state == 2)
	{
		portl_config(0x17, 0x29, 0x43);
	}
	else if (current_state == 3)
	{
		portl_config(0x1D, 0x27, 0x49);
	}
}

void LightsClass::time_config()
{
	if (millis() - disp_time > DISP_DELAY)
	{
		disp_time = millis();
		current_state++;
		if (current_state > 3)
		{
			current_state = 1;
		}
	}
}
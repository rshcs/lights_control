#define YELLOW 1
#define GREEN 2
#define GREEN_2 4
#define RED 8

#define A_POINT 1
#define B_POINT 2
#define C_POINT 4
 
#define MUX_DELAY 3
#define DISP_DELAY 10000

uint32_t disp_time = 0;
int8_t current_state = 1;



void setup()
{
	Serial.begin(9600);

	DDRL = 0xFF;
	DDRC = 0xFF;
	DDRA = 0xFF;

	PORTL = 0b00001111;
	PORTC = 0xFF;
	PORTA = 0;

	disp_time = millis();
}

void loop()
{
	/*
	led_light(RED, A_POINT);
	delay(1000);
	led_light(YELLOW, A_POINT);
	delay(1000);
	led_light(GREEN, A_POINT);
	delay(1000);
	led_light(GREEN_2, A_POINT);
	delay(1000);

	led_light(RED, B_POINT);
	delay(1000);
	led_light(YELLOW, B_POINT);
	delay(1000);
	led_light(GREEN, B_POINT);
	delay(1000);
	led_light(GREEN_2, B_POINT);
	delay(1000);

	led_light(RED, C_POINT);
	delay(1000);
	led_light(YELLOW, C_POINT);
	delay(1000);
	led_light(GREEN, C_POINT);
	delay(1000);
	led_light(GREEN_2, C_POINT);
	delay(1000);
	*/
	//portl_config(0x19, 0x23, 0x47);
	
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

void led_out(uint8_t inVal)
{
	inVal = ~inVal & 0b00001111;
	uint8_t port_val = PORTL & 0b11110000;
	port_val |= inVal;
	PORTL = port_val;	
}

void led_ctrl(uint8_t inVal)
{
	uint8_t port_val = PORTL & 0b00001111;
	port_val |= inVal << 4;
	PORTL = port_val;
}

void led_light(uint8_t ledNum, uint8_t ctrlNum)
{
	led_out(ledNum);
	led_ctrl(ctrlNum);
}

void portl_config(uint8_t val1, uint8_t val2, uint8_t val3)
{
	PORTL = val1;  // <= A
	delay(MUX_DELAY);
	PORTL = val2;  // <= B
	delay(MUX_DELAY);
	PORTL = val3;  // <= C
	delay(MUX_DELAY);
}


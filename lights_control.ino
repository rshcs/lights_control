#define YELLOW 1
#define GREEN 2
#define GREEN_2 4
#define RED 8

#define A_POINT 1
#define B_POINT 2
#define C_POINT 4
 
void setup()
{
	Serial.begin(9600);

	DDRL = 0xFF;
	DDRC = 0xFF;
	DDRA = 0xFF;

	PORTL = 0b00001111;
	PORTC = 0xFF;
	PORTA = 0;
}

void loop()
{
	
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
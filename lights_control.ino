#include "lights.h"


LightsClass lights(0);

void setup()
{
	//Serial.begin(9600);

	
}

void loop()
{
	lights.state_config();
	lights.time_config();
	
	
}




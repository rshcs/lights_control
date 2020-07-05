#include "lights.h"


LightsClass lights(0);

void setup()
{
	//Serial.begin(9600);

	
}

void loop()
{
	lights.state_config();
	lights.time_config(3);
	lights.mux_time_config(3);
	
}




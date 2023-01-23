//
#include "Plutopilot.h" // All required pilot files
#include "Estimate.h" //For Sensors
#include "Utils.h" // Graphs, LED(flags), PRINT
#include "Sensor.h" //For Sensors
#include "User.h"

int g=2;

void plutoInit(){}

void onLoopStart() // one time start commands
{
LED.flightStatus(DEACTIVATE);

}

void plutoLoop() // infinite loop
{
	if(Acceleration.getNetAcc()<=g) // Accelaration check
	{
		if( !FlightStatus.check(FS_CRASHED))   // Accelaration check after crash safety
		{

			LED.set(BLUE,ON);

      		Command.arm(); // Arming - Stopping exactly at that position by starting all motors simultaneously

			Monitor.println("Z: %d", Acceleration.getNetAcc());
			Graph.red(Acceleration.getNetAcc(),1);
		}
    	}

	else
	{
		LED.set(BLUE,OFF);

	}
}
void onLoopFinish() // one time start commands
{
LED.flightStatus(DEACTIVATE);

}





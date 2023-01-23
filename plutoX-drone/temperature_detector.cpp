// Do not remove the include below
#include "PlutoPilot.h"
#include "Sensor.h"
#include "Utils.h"
#include "User.h"
#include "Math.h"
#include "Control.h"

int16_t init_temperature;
int16_t temperature;

void Plutoinit()
{


}




//The function is called once before plutoLoop() when you activate developer mode
void onLoopStart()
{
LED.flightStatus(DEACTIVATE);
init_temperature=Barometer.get(TEMPERATURE);

}



//The loop function is called in an endless loop
void plutoLoop()
{
//Add your repeated code here

temperature=Barometer.get(TEMPERATURE);



if(fabs(temperature-init_temperature)>3)
{
	Command.arm();


}
init_temperature=(init_temperature*0.5+temperature*0.5);
Monitor.println("temperature:",temperature);
Graph.red(temperature);
}
//The function is called once after plutoLoop() when you deactivate developer mode
void onLoopFinish()
{

	LED.flightStatus(ACTIVATE);
}






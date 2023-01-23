// Do not remove the include below
#include "PlutoPilot.h"
#include "Sensor.h"
#include "Utils.h"
#include "User.h"
#include "Math.h"
#include "Control.h"

int16_t init_pressure;
int16_t pressure;


//The setup function is called once at Pluto's hardware startup
void plutoInit()
{


}




//The function is called once before plutoLoop() when you activate developer mode
void onLoopStart()
{
LED.flightStatus(DEACTIVATE);
init_pressure=Barometer.get(PRESSURE);

}



//The loop function is called in an endless loop
void plutoLoop()
{
//Add your repeated code here

pressure=Barometer.get(PRESSURE);



if(fabs(pressure-init_pressure)>3)
{
	Command.arm();


}
init_pressure=(init_pressure*0.5+pressure*0.5);
Monitor.println("Pressure:",pressure);
Graph.red(pressure);
}
//The function is called once after plutoLoop() when you deactivate developer mode
void onLoopFinish()
{

	LED.flightStatus(ACTIVATE);
}





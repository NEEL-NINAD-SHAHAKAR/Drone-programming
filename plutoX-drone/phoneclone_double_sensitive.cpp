// Do not remove the include below
#include "PlutoPilot.h" // access to piloting power
#include "User.h" // access to phones heading
#include"Utils.h" // access to API,s eg.Flags
#include "Control.h" //access drones heading
#include "Estimate.h" //Drones heading values

int16_t Error = 0, PlutoXHeading = 0;


//The setup function is called once at Pluto's hardware startup
void plutoInit()
{
//no spare hardwares required.

}

//The function is called once before plutoLoop() when you activate developer mode
void onLoopStart()
{
	LED.flightStatus(DEACTIVATE); //DisableS default behavior
	Error = App.getAppHeading() - Angle.get(AG_YAW); //set error
	Monitor.println("Error is: ",Error);
	Graph.red(Error,1);

}

//The loop function is called in an endless loop
void plutoLoop()
{
Monitor.println("Phone_Heading: ",App.getAppHeading());

PlutoXHeading =2* App.getAppHeading()-Error;

if(PlutoXHeading<0)
{
	PlutoXHeading+=360;
	LED.set(BLUE,ON);
}
else
{
	LED.set(GREEN,ON);
}

Monitor.println("PlutoXHeading value should be set to: ",PlutoXHeading);
Graph.green(PlutoXHeading,2);

DesiredAngle.set(AG_YAW,PlutoXHeading);
Graph.blue(Angle.get(AG_YAW));

Monitor.println("PlutoX is at: ",Angle.get(AG_YAW));

LED.set(RED,ON);


}



//The function is called once after plutoLoop() when you deactivate developer mode
void onLoopFinish()
{
LED.flightStatus(ACTIVATE);
}






#include 'PlutoPilot.h' // All required pilot files
#include 'Estimate.h' //For Sensors
#include 'Utils.h' // Graphs, LED(flags), PRINT


void onloopstart()
{
LED.flightstatus(DEACTIVATE);

}

void PlutoLoop()
{
	if(Velocity.get(z)>0)
	{
		LED.set(RED,ON);
		LED.set(GREEN,OFF);
	}
	else
	{
		LED.set(GREEN,ON);
		LED.set(RED,OFF);
	
		Monitor.printIn('Z',velocity.get(Z));
		Graph.red(Velocity.get(Z),1);
	}

void onloopfinish()
{
LED.flightstatus(ACTIVATE);

}



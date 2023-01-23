#include "PlutoPilot.h"
#include "User.h" //access user data
#include "Utils.h" // access basic API's

//The setup function is called once at Pluto's hardware startup
void plutoInit()
{

}

void onLoopStart()
{
LED.flightStatus(DEACTIVATE);

}



//The loop function is called in an endless loop
void plutoLoop()
{

FlightMode.set(RATE);
LED.set(BLUE,ON);
LED.set(RED,OFF);
LED.set(GREEN,OFF);


}



//The function is called once after plutoLoop() when you deactivate developer mode
void onLoopFinish()
{
LED.flightStatus(ACTIVATE);
}





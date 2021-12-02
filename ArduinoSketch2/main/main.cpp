/*
* main.cpp
*
* Main 
*
* Created: 10/7/2021 12:17:58 AM
* Author: Andi
*/

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include <Arduino.h>
#include "Modules/Sensors/SPS/SPS.h";
#include "Modules/Sensors/SPS/SPS_Master.h";
#include "Modules/Actuators/Buzzer/Buzz.h";

#pragma endregion

/************************************************************************/
/*				Global Declarations and Initializations					*/
/************************************************************************/

#pragma region Global Declarations and Initializations

SPS*	S1 = new SPS	(3, 2, 8);
//SPS*	S2 = new SPS	(4, 5, 9);
//SPS*	S3 = new SPS	(6, 7, 10);
//SPS*	S4 = new SPS	(11, 12, 13);

//SPS_Master s1(	3, 2, 8, 
//				4, 5, 9,
//				6, 7, 10, 
//				11, 12, 13	);

#pragma endregion

/************************************************************************/
/*						Startup and Infinite Loop						*/
/************************************************************************/

#pragma region Startup
/*
 *	Setup Function
 *	Used as Startup function, called before infinite loop starts and it runs only once 
 */
void setup() {
	
	Serial.begin(9600);
	Serial.print("SMART_CAR SPS TEST STARTED");

	pinMode		(S1->			getTrigPin(),	OUTPUT);
	pinMode		(S1->			getEchoPin(),	INPUT);
	
	pinMode		(S1->buzzer->	getSigPin(),	OUTPUT);
	
	S1->buzzer->Buzz(1000);	
}
#pragma endregion

#pragma region Infinite Loop
/*
 *	Loop Function
 *	Used as infinite loop
 */
void loop() {
	S1->Task();
}
#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/

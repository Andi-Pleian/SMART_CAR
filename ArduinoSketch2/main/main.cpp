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
SPS*	S2 = new SPS	(3, 4, 9);
//SPS*	S3 = new SPS	(6, 7, 10);
//SPS*	S4 = new SPS	(11, 12, 13);

//SPS_Master s1(	3, 2, 8, 
//				4, 5, 9,
//				6, 7, 10, 
//				11, 12, 13	);

#pragma endregion

/************************************************************************/
/*							Init Functions                              */
/************************************************************************/

#pragma region Init Functions

void SPS_INIT(SPS* s) {
	pinMode		(s->			getTrigPin(),	OUTPUT);
	pinMode		(s->			getEchoPin(),	INPUT);
	
	pinMode		(s->buzzer->	getSigPin(),	OUTPUT);
}

#pragma endregion

/************************************************************************/
/*							Setup and Loop							    */
/************************************************************************/

#pragma region Setup

/*
 *	Setup Function
 *	Called before infinite loop starts and it runs only once 
 */
void setup() {
	
	Serial.begin(9600);
	Serial.print("SMART_CAR SPS TEST STARTED");

	SPS_INIT(S1);
	SPS_INIT(S2);
	
	S1->buzzer->Buzz(1000);	
	S2->buzzer->Buzz(1000);
}

#pragma endregion

#pragma region Infinite Loop

/*
 *	Loop Function
 *	Used as infinite loop
 */
void loop() {
	S1->Task();
	S2->Task();
}

#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/

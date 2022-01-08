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
//#include "IRRemote/IRremote.h"
#include "Modules/Sensors/SPS/SPS.h";
#include "Modules/Sensors/SPS/SPS_Master.h";
#include "Modules/Actuators/Buzzer/Buzz.h";
//#include "Modules/Actuators/MotorControl/Motor_Control.h";

#pragma endregion

/************************************************************************/
/*				Global Declarations and Initializations					*/
/************************************************************************/

#pragma region Global Declarations and Initializations

SPS*	S1 = new SPS	(3, 8, 12); //Back SPS
SPS*	S2 = new SPS	(5, 4, 7);  //Front SPS

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
	Serial.begin(115200);
	Serial.println("SMART_CAR SPS TEST STARTED");

	SPS_INIT(S1);
	SPS_INIT(S2);
	
	S1->buzzer->Buzz(1000);	
	S2->buzzer->Buzz(1000);
	
	Serial.println("Buzzer Tested");
}

#pragma endregion

#pragma region Infinite Loop

/*
 *	Loop Function
 *	Used as infinite loop
 */
void loop() {
	S1->Task();
	//Serial.println("S1 Task tested");
	
	S2->Task();
	//Serial.println("S1 Task tested");
}

#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/


// /*
// * main.cpp
// *
// * Main 
// *
// * Created: 10/7/2021 12:17:58 AM
// * Author: Andi
// */
// 
// /************************************************************************/
// /*								Includes								*/
// /************************************************************************/
// 
// #pragma region Includes
// 
// #include <Arduino.h>
// #include "IRRemote/IRremote.h"
// #include "Modules/Sensors/SPS/SPS.h";
// #include "Modules/Sensors/SPS/SPS_Master.h";
// #include "Modules/Actuators/Buzzer/Buzz.h";
// #include "Modules/Actuators/MotorControl/Motor_Control.h";
// 
// #pragma endregion
// 
// /************************************************************************/
// /*				Global Declarations and Initializations					*/
// /************************************************************************/
// 
// #pragma region Global Declarations and Initializations
// 
// const int RECV_PIN = 7;
// 
// Motor_Control* MotorControl = new Motor_Control(6, 8, 2, 3, 4, 5);
// 
// //SPS*	S1 = new SPS	(3, 2, 8);
// //SPS*	S2 = new SPS	(3, 4, 9);
// 
// //SPS*	S3 = new SPS	(6, 7, 10);
// //SPS*	S4 = new SPS	(11, 12, 13);
// 
// //SPS_Master s1(	3, 2, 8, 
// //				4, 5, 9,
// //				6, 7, 10, 
// //				11, 12, 13	);
// 
// #pragma endregion
// 
// /************************************************************************/
// /*							Init Functions                              */
// /************************************************************************/
// 
// #pragma region Init Functions
// 
// void SPS_INIT(SPS* s) {
// 	pinMode		(s->			getTrigPin(),	OUTPUT);
// 	pinMode		(s->			getEchoPin(),	INPUT);
// 	
// 	pinMode		(s->buzzer->	getSigPin(),	OUTPUT);
// }
// 
// #pragma endregion
// 
// /************************************************************************/
// /*							Setup and Loop							    */
// /************************************************************************/
// 
// #pragma region Setup
// 
// /*
//  *	Setup Function
//  *	Called before infinite loop starts and it runs only once 
//  */
// void setup() {
// 	/*
// 	Serial.begin(9600);
// 	Serial.print("SMART_CAR SPS TEST STARTED");
// 
// 	SPS_INIT(S1);
// 	SPS_INIT(S2);
// 	
// 	S1->buzzer->Buzz(1000);	
// 	S2->buzzer->Buzz(1000);*/
// 	
// 	pinMode(MotorControl->in1, OUTPUT);
// 	pinMode(MotorControl->in2, OUTPUT);
// 	pinMode(MotorControl->in3, OUTPUT);
// 	pinMode(MotorControl->in4, OUTPUT);
// 	
// 	/*
//      * Start the receiver, enable feedback LED and take LED feedback pin from the internal boards definition
//      */
// 	Serial.begin(115200);
//     IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
// 
//     Serial.print(("Ready to receive IR signals at pin "));
//     Serial.println(RECV_PIN);
// 
// }
// 
// #pragma endregion
// 
// #pragma region Infinite Loop
// 
// /*
//  *	Loop Function
//  *	Used as infinite loop
//  */
// void loop() {
// 	//S1->Task();
// 	//S2->Task();
// 	
// 	//motor 1 controller
// 	//if both are high or low the motor stops
// 	digitalWrite(MotorControl->in1, LOW);
// 	digitalWrite(MotorControl->in2, LOW);
// 	
// 	//motor 2 controller
// 	//if both are high or low the motor stops
// 	digitalWrite(MotorControl->in3, LOW);
// 	digitalWrite(MotorControl->in4, LOW);
// 	
// 	
// 	if (IrReceiver.decode()) {
// 		unsigned long keycode = IrReceiver.decodedIRData.command;
// 		Serial.println(keycode);
// 		
// 		if (keycode == 21) {
// 			//motor 1 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in3, LOW);
// 			digitalWrite(MotorControl->in4, HIGH);
// 			
// 			//motor 2 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in1, HIGH);
// 			digitalWrite(MotorControl->in2, LOW);
// 			delay(500);
// 		} else if (keycode == 7) {
// 			//motor 1 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in1, HIGH);
// 			digitalWrite(MotorControl->in2, LOW);
// 			
// 			//motor 2 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in3, LOW);
// 			digitalWrite(MotorControl->in4, HIGH);
// 			delay(500);
// 		} else if (keycode == 68) {
// 			//motor 1 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in1, LOW);
// 			digitalWrite(MotorControl->in2, HIGH);
// 			
// 			//motor 2 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in3, LOW);
// 			digitalWrite(MotorControl->in4, LOW);
// 			delay(500);
// 		} else if (keycode == 64) {
// 			//motor 1 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in1, HIGH);
// 			digitalWrite(MotorControl->in2, LOW);
// 			
// 			//motor 2 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in3, LOW);
// 			digitalWrite(MotorControl->in4, LOW);
// 			delay(500);
// 		}
// 		
// 		
// 		
// 		if ((IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)) {
// 			IrReceiver.resume();
// 			return;
// 		}
// 		
// 		IrReceiver.resume();
//     }
// 	
// }
// 
// #pragma endregion
// 
// /************************************************************************/
// /*								End of File								*/
// /************************************************************************/



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
#include "IRRemote/IRremote.h"
#include "Modules/Sensors/SPS/SPS.h";
#include "Modules/Sensors/SPS/SPS_Master.h";
#include "Modules/Actuators/Buzzer/Buzz.h";
#include "Modules/Actuators/MotorControl/Motor_Control.h";

#pragma endregion

/************************************************************************/
/*				Global Declarations and Initializations					*/
/************************************************************************/

#pragma region Global Declarations and Initializations

const int RECV_PIN = 7;

Motor_Control* MotorControl = new Motor_Control(6, 8, 2, 3, 4, 5);

#pragma endregion

/************************************************************************/
/*							Init Functions                              */
/************************************************************************/

#pragma region Init Functions

#pragma endregion

/************************************************************************/
/*								Motor Functions                         */
/************************************************************************/

void forward()
{
	digitalWrite(MotorControl->leftForward, HIGH);
	digitalWrite(MotorControl->rightForward, HIGH);
	digitalWrite(MotorControl->leftBackward, LOW);
	digitalWrite(MotorControl->rightBackward, LOW);
	delay(1000);
}

void back()
{
	digitalWrite(MotorControl->leftBackward, HIGH);
	digitalWrite(MotorControl->rightBackward, HIGH);
	
	digitalWrite(MotorControl->leftForward, LOW);
	digitalWrite(MotorControl->rightForward, LOW);
	delay(1000);
}

void left()
{
	digitalWrite(MotorControl->leftForward, LOW);
	digitalWrite(MotorControl->rightBackward, LOW);
	
	digitalWrite(MotorControl->leftBackward, HIGH);
	digitalWrite(MotorControl->rightForward, HIGH);
	
// 	delay(500);
// 	
// 	digitalWrite(MotorControl->leftForward, HIGH);
// 	digitalWrite(MotorControl->rightForward, HIGH);
// 	
// 	digitalWrite(MotorControl->leftBackward, LOW);
// 	digitalWrite(MotorControl->rightBackward, LOW);
	//delay(1000);
}

void right()
{
	digitalWrite(MotorControl->leftForward, HIGH);
	digitalWrite(MotorControl->rightBackward, HIGH);
	
	digitalWrite(MotorControl->leftBackward, LOW);
	digitalWrite(MotorControl->rightForward, LOW);
	
// 	delay(500);
// 	
// 	digitalWrite(MotorControl->leftForward, HIGH);
// 	digitalWrite(MotorControl->rightForward, HIGH);
// 	
// 	digitalWrite(MotorControl->leftBackward, LOW);
// 	digitalWrite(MotorControl->rightBackward, LOW);
	//delay(1000);
	
}

void Stop()
{
	digitalWrite(MotorControl->leftForward, LOW);
	digitalWrite(MotorControl->rightBackward, LOW);
	
	digitalWrite(MotorControl->leftBackward, LOW);
	digitalWrite(MotorControl->rightForward, LOW);
}

/************************************************************************/
/*							Setup and Loop							    */
/************************************************************************/

unsigned short int RESET_PIN = 12;

void(* RESET) (void) = 0;

#pragma region Setup

/*
 *	Setup Function
 *	Called before infinite loop starts and it runs only once 
 */
void setup() {
	digitalWrite(RESET_PIN, HIGH);
	delay(200);
	pinMode(RESET_PIN, OUTPUT);
	
	pinMode(MotorControl->enA, OUTPUT);
	pinMode(MotorControl->enB, OUTPUT);
	
	digitalWrite(MotorControl->enA, HIGH);
	digitalWrite(MotorControl->enB, HIGH);
	
	pinMode(MotorControl->rightBackward, OUTPUT);
	pinMode(MotorControl->rightForward, OUTPUT);
	pinMode(MotorControl->leftForward, OUTPUT);
	pinMode(MotorControl->leftBackward, OUTPUT);
	
	//motor 1 controller
	//if both are high or low the motor stops
	digitalWrite(MotorControl->rightBackward, LOW);
	digitalWrite(MotorControl->rightForward, LOW);
	
	//motor 2 controller
	//if both are high or low the motor stops
	digitalWrite(MotorControl->leftForward, LOW);
	digitalWrite(MotorControl->leftBackward, LOW);
	
	
	/*
     * Start the receiver, enable feedback LED and take LED feedback pin from the internal boards definition
     */
	Serial.begin(115200);
    IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

    Serial.print(("Ready to receive IR signals at pin "));
    Serial.println(RECV_PIN);

}

#pragma endregion

#pragma region Infinite Loop

/*
 *	Loop Function
 *	Used as infinite loop
 */
void loop() {
	
	
	if (IrReceiver.decode()) {
		unsigned long keycode = IrReceiver.decodedIRData.command;
		Serial.println(keycode);
		
		switch (keycode) {
			case 21:
				forward();
				break;
			case 7:
// 				motor 1 controller
// 								//if both are high or low the motor stops
// 								digitalWrite(MotorControl->rightBackward, HIGH);
// 								digitalWrite(MotorControl->rightForward, LOW);
// 								
// 								//motor 2 controller
// 								//if both are high or low the motor stops
// 								digitalWrite(MotorControl->leftForward, LOW);
// 								digitalWrite(MotorControl->leftBackward, HIGH);
// 								delay(500);
				back();
				break;
			case 68:
				left();
				break;
			case 64:
				right();
				break;
			case 9:
				Stop();
				break;
			case 71:
				digitalWrite(RESET_PIN, LOW);
				break;
		}
		
// 		if (keycode == 21) {
// // 			motor 1 controller
// // 						//if both are high or low the motor stops
// // 						digitalWrite(MotorControl->in_4, LOW);
// // 						digitalWrite(MotorControl->in_5, HIGH);
// // 						
// // 						//motor 2 controller
// // 						//if both are high or low the motor stops
// // 						digitalWrite(MotorControl->in_2, HIGH);
// // 						digitalWrite(MotorControl->in_3, LOW);
// // 						delay(500);
// 			forward();
// 		} else if (keycode == 7) {
// 			//motor 1 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in_2, HIGH);
// 			digitalWrite(MotorControl->in_3, LOW);
// 			
// 			//motor 2 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in_4, LOW);
// 			digitalWrite(MotorControl->in_5, HIGH);
// 			delay(500);
// 		} else if (keycode == 68) {
// 			//motor 1 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in_2, LOW);
// 			digitalWrite(MotorControl->in_3, HIGH);
// 			
// 			//motor 2 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in_4, LOW);
// 			digitalWrite(MotorControl->in_5, LOW);
// 			delay(500);
// 		} else if (keycode == 64) {
// 			//motor 1 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in_2, HIGH);
// 			digitalWrite(MotorControl->in_3, LOW);
// 			
// 			//motor 2 controller
// 			//if both are high or low the motor stops
// 			digitalWrite(MotorControl->in_4, LOW);
// 			digitalWrite(MotorControl->in_5, LOW);
// 			delay(500);
// 		}
		
// 		if ((IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)) {
// 			IrReceiver.resume();
// 			return;
// 		}
		
		IrReceiver.resume();
    }
	
}

#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/


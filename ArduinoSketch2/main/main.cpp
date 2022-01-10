
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
#include "IRRemote/IRremote.h";
#include "Modules/Sensors/ParkingSensor/ParkingSensor.h";
#include "Modules/Actuators/Buzzer/Buzzer.h";
#include "Modules/Actuators/MotorControl/Motor_Control.h";

#pragma endregion

/************************************************************************/
/*				Global Declarations and Initializations					*/
/************************************************************************/

#pragma region Global Declarations and Initializations

/*
 *	Pin used to reset the microprocessor
 */
unsigned short int RESET_PIN = 12;

//void(* RESET) (void) = 0;


/*
 *	IR Reciever PIN
 */
const int RECV_PIN = 7;	

/*
 *	Motor driver initialization
 */
Motor_Control* MotorControl = new Motor_Control(6, 8, 2, 3, 4, 5);

#pragma endregion

/************************************************************************/
/*								Motor Functions                         */
/************************************************************************/

#pragma region Motor Functions

/*
 *	Function to move the car forward
 */
void forward()
{
	digitalWrite(MotorControl->leftForward, HIGH);
	digitalWrite(MotorControl->rightForward, HIGH);
	
	digitalWrite(MotorControl->leftBackward, LOW);
	digitalWrite(MotorControl->rightBackward, LOW);
	delay(1000);
}

/*
 *	Function to move the car backward
 */
void back()
{
	digitalWrite(MotorControl->leftBackward, HIGH);
	digitalWrite(MotorControl->rightBackward, HIGH);
	
	digitalWrite(MotorControl->leftForward, LOW);
	digitalWrite(MotorControl->rightForward, LOW);
	delay(1000);
}

/*
 *	Function to move the car left
 */
void left()
{
	digitalWrite(MotorControl->leftForward, LOW);
	digitalWrite(MotorControl->rightBackward, LOW);
	
	digitalWrite(MotorControl->leftBackward, HIGH);
	digitalWrite(MotorControl->rightForward, HIGH);
}

/*
 *	Function to move the car right
 */
void right()
{
	digitalWrite(MotorControl->leftForward, HIGH);
	digitalWrite(MotorControl->rightBackward, HIGH);
	
	digitalWrite(MotorControl->leftBackward, LOW);
	digitalWrite(MotorControl->rightForward, LOW);
}

/*
 *	Function to stop the car
 */
void Stop()
{
	digitalWrite(MotorControl->leftForward, LOW);
	digitalWrite(MotorControl->rightBackward, LOW);
	
	digitalWrite(MotorControl->leftBackward, LOW);
	digitalWrite(MotorControl->rightForward, LOW);
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
	/*
	 *	"Initialize" the reset pin
	 *  Now if the pin will be set to LOW, the arduino will reset
	 */
	digitalWrite(RESET_PIN, HIGH);
	delay(200);
	pinMode(RESET_PIN, OUTPUT);
	
	/*
	 *	Initialize motor pins as OUTPUT
	 */
	pinMode(MotorControl->enA, OUTPUT);
	pinMode(MotorControl->enB, OUTPUT);
	
	/*
	 *	Set enA and enB pins to HIGH
	 */
	digitalWrite(MotorControl->enA, HIGH);
	digitalWrite(MotorControl->enB, HIGH);
	
	pinMode(MotorControl->rightBackward, OUTPUT);
	pinMode(MotorControl->rightForward, OUTPUT);
	pinMode(MotorControl->leftForward, OUTPUT);
	pinMode(MotorControl->leftBackward, OUTPUT);
	
	/*
	 *	Set all motor pins to LOW
	 */
	
	// Motor 1 controller
	// If both are high or low the motor stops
	digitalWrite(MotorControl->rightBackward, LOW);
	digitalWrite(MotorControl->rightForward, LOW);
	
	// Motor 2 controller
	// If both are high or low the motor stops
	digitalWrite(MotorControl->leftForward, LOW);
	digitalWrite(MotorControl->leftBackward, LOW);
	
	
	/*
     * Start the IR receiver
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
		/*
		 *	keycode => signal sent from ir remote
		 */
		unsigned long keycode = IrReceiver.decodedIRData.command;
		Serial.println(keycode);
		
		switch (keycode) {
			case 21:	// Move forward
				forward();
				break;
			case 7:		// Move backward
				back();
				break;
			case 68:	// Move left
				left();
				break;
			case 64:	// Move right
				right();
				break;
			case 9:		// Stop
				Stop();
				break;
			case 71:	// RESET
				digitalWrite(RESET_PIN, LOW);
				break;
		}
		
		IrReceiver.resume();
    }
	
}

#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/


/* 
* ParkingSensor.cpp
*
* Created: 10/7/2021 12:17:58 AM
* Author: Andi
*/

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include "ParkingSensor.h"
#include <string.h>
#include "..\..\..\..\ArduinoCore\include\core\Arduino.h"

#pragma endregion

/************************************************************************/
/*                         Default Constructors							*/
/************************************************************************/

#pragma region Default Constructors

/**
 *	Default constructor (Basic Init)
 */
ParkingSensor::ParkingSensor()
{
	this->trigPin = 1;
	this->echoPin = 2;
} //ParkingSensor

/**
 *	Copy constructor (NOT USED)
 */
 ParkingSensor::ParkingSensor(const ParkingSensor &s)
 {
	this->trigPin = s.trigPin;
	this->echoPin = s.echoPin;
	
	this->buzzer->setSigPin(s.buzzer->getSigPin());
 }

/**
 *	Default destructor (Empty)
 */
ParkingSensor::~ParkingSensor()
{
} //~ParkingSensor

#pragma endregion

/************************************************************************/
/*                         Public Functions								*/
/************************************************************************/

#pragma region Public Functions

/**
 *	Custom constructor
 *  used for initializing a new ParkingSensor
 *
 *	@param[in] trigPin_arg TriggerPin
 *	@param[in] echoPin_arg EchoPin
 *	@param[in] tag_arg ParkingSensor's tag
 */
ParkingSensor::ParkingSensor(unsigned short int trigPin_arg, 
		 unsigned short int echoPin_arg, 
		 unsigned short int buzzerPin_arg) {
			
	this->trigPin			= trigPin_arg;
	this->echoPin			= echoPin_arg;
	this->buzzer->setSigPin(buzzerPin_arg);
}

/**
 *	This function sends an ultrasound through trigPin and
 *  receives it back in echoPin from where we get the wave travel time
 *	with pulseIn() method
 *
 *	@return Sound wave travel time
 */
long ParkingSensor::getWaveComebackTime() {
	digitalWrite(this->trigPin, LOW);						
	delayMicroseconds(2);
	
	digitalWrite(this->trigPin, HIGH);						 
	delayMicroseconds(10);								
	digitalWrite(this->trigPin, LOW);							
		
	return pulseIn(echoPin, HIGH);						
}

/**
 *	Measures distance (in cm) to object based on ultrasound comeback time,
 *	using the following formula: Distance = (Time * Speed) / 2
 *	
 *	@return Distance in cm to object
 */
int ParkingSensor::getDistanceToObject() {
	return (getWaveComebackTime() * SOUND_SPEED_MS) / 2;	
}

/**
 *	Prints distance to object measured by ParkingSensor to Serial COM
 *
 *	(!!!USED FOR SINGLE ParkingSensor TESTING!!!)
 */
void ParkingSensor::serialPrintDistance() {
	Serial.print("Distance: ");
	Serial.print(this->getDistanceToObject());
	Serial.println(" cm");
}

/**
 *	ParkingSensor's Task
 *	
 *	This function is used to Check distance to object for each stage and call
 *	Buzzer's Task to react to it.
 *	
 */
void ParkingSensor::Task() {
	if ((this->getDistanceToObject() <= PS_1ST_STAGE_CM) && (this->getDistanceToObject() > PS_2ST_STAGE_CM)) {

		this->buzzer->Buzz(BUZZER_1ST_STAGE_DELAY_MS);
	} else if ((this->getDistanceToObject() <= PS_2ST_STAGE_CM) && (this->getDistanceToObject() > PS_3ST_STAGE_CM)) {
		
		this->buzzer->Buzz(BUZZER_2ST_STAGE_DELAY_MS);
	} else if ((this->getDistanceToObject() <= PS_3ST_STAGE_CM) && (this->getDistanceToObject() > PS_4ST_STAGE_CM)) {

		this->buzzer->Buzz(BUZZER_3ST_STAGE_DELAY_MS);
	} else if ((this->getDistanceToObject() <= PS_4ST_STAGE_CM) && (this->getDistanceToObject() > PS_5ST_STAGE_CM)) {

		this->buzzer->Buzz(BUZZER_4ST_STAGE_DELAY_MS);
	} else if ((this->getDistanceToObject() <= PS_5ST_STAGE_CM) && (this->getDistanceToObject() > PS_MIN_DISTANCE_CM)) {

		this->buzzer->Buzz(BUZZER_5ST_STAGE_DELAY_MS);
	} else if (this->getDistanceToObject() <= PS_MIN_DISTANCE_CM) {

		this->buzzer->Buzz(BUZZER_MIN_STAGE_DELAY_MS);
	}
}

/*
 *	Trig Pin getter
 */
unsigned short int ParkingSensor::getTrigPin()
{
	return this->trigPin;
}

/*
 *	Echo Pin getter
 */
unsigned short int ParkingSensor::getEchoPin()
{
	return this->echoPin;
}

/*
 *	Trig Pin setter
 */
void ParkingSensor::setTrigPin(unsigned short int trigPin_arg)
{
	this->trigPin = trigPin_arg;
}

/*
 *	Echo Pin setter
 */
void ParkingSensor::setEchoPin(unsigned short int echoPin_arg)
{
	this->echoPin = echoPin_arg;
}

#pragma endregion 

/************************************************************************/
/*								End of File								*/
/************************************************************************/


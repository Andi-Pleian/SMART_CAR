/* 
* SPS.cpp
*
* Created: 10/7/2021 12:17:58 AM
* Author: Andi
*/

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include "SPS.h"
#include <string.h>
#include "..\..\..\..\ArduinoCore\include\core\Arduino.h"

#pragma endregion

/************************************************************************/
/*                         Default Constructors							*/
/************************************************************************/

#pragma region Default Constructors
/**
 *	Default constructor (empty)
 */
SPS::SPS()
{
	this->trigPin = 1;
	this->echoPin = 2;
} //SPS

 SPS::SPS(const SPS &s)
 {
	this->trigPin = s.trigPin;
	this->echoPin = s.echoPin;
	
	this->buzzer->setSigPin(s.buzzer->getSigPin());
 }
/*
SPS& SPS::operator=(const SPS &s)
{
	delete this->trigPin;
	delete this->echoPin;
	delete this->buzzer->getSigPin();
	
	this->trigPin = s.trigPin;
	this->echoPin = s.echoPin;
	this->buzzer->setSigPin(s.buzzer->getSigPin());
	return *this;
}*/

/**
 *	Default destructor (empty)
 */
SPS::~SPS()
{
} //~SPS

#pragma endregion

/************************************************************************/
/*                         Public Functions								*/
/************************************************************************/

#pragma region Public Functions
/**
 *	Custom constructor
 *  used for initializing a new SPS
 *
 *	@param[in] trigPin_arg TriggerPin
 *	@param[in] echoPin_arg EchoPin
 *	@param[in] tag_arg SPS's tag
 */
SPS::SPS(unsigned short int trigPin_arg, 
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
long SPS::getWaveComebackTime() {
	digitalWrite(this->trigPin, LOW);						
	delayMicroseconds(2);
	
	digitalWrite(trigPin, HIGH);						 
	delayMicroseconds(10);								
	digitalWrite(trigPin, LOW);							
	
	
	return pulseIn(echoPin, HIGH);						// Reads the echoPin, returns the sound wave travel time in microseconds
}

/**
 *	Measures distance (in cm) to object based on ultrasound comeback time,
 *	using the following formula: Distance = (Time * Speed) / 2
 *	
 *	@return Distance in cm to object
 */
int SPS::getDistanceToObject() {
	return (getWaveComebackTime() * SOUND_SPEED_MS) / 2;	
}

/**
 *	Prints distance to object measured by SPS to Serial COM
 *	
 */
void SPS::serialPrintDistance() {
	Serial.print("Distance: ");
	Serial.print(this->getDistanceToObject());
	Serial.println(" cm");
}

/**
 *	SPS's Task
 *	
 *	This function is used to Check distance to object for each stage and call
 *	Buzzer's Task to react to it.
 *	
 */
void SPS::Task() {
	if ((this->getDistanceToObject() <= SPS_1ST_STAGE_CM) && (this->getDistanceToObject() > SPS_2ST_STAGE_CM)) {
		
		this->serialPrintDistance();
		this->buzzer->Task(BUZZER_1ST_STAGE_DELAY_MS);
		
	} else if ((this->getDistanceToObject() <= SPS_2ST_STAGE_CM) && (this->getDistanceToObject() > SPS_3ST_STAGE_CM)) {
		
		this->serialPrintDistance();
		this->buzzer->Task(BUZZER_2ST_STAGE_DELAY_MS);
		
	} else if ((this->getDistanceToObject() <= SPS_3ST_STAGE_CM) && (this->getDistanceToObject() > SPS_4ST_STAGE_CM)) {
		
		this->serialPrintDistance();
		this->buzzer->Task(BUZZER_3ST_STAGE_DELAY_MS);
		
	} else if ((this->getDistanceToObject() <= SPS_4ST_STAGE_CM) && (this->getDistanceToObject() > SPS_5ST_STAGE_CM)) {
		
		this->serialPrintDistance();
		this->buzzer->Task(BUZZER_4ST_STAGE_DELAY_MS);
		
	} else if ((this->getDistanceToObject() <= SPS_5ST_STAGE_CM) && (this->getDistanceToObject() > SPS_MIN_DISTANCE_CM)) {
		
		this->serialPrintDistance();
		this->buzzer->Task(BUZZER_5ST_STAGE_DELAY_MS);
		
	} else if (this->getDistanceToObject() <= SPS_MIN_DISTANCE_CM) {
		
		this->serialPrintDistance();
		this->buzzer->Task(BUZZER_MIN_STAGE_DELAY_MS);
		
	}
}

/*
 *	Trig Pin getter
 */
unsigned short int SPS::getTrigPin()
{
	return this->trigPin;
}

/*
 *	Echo Pin getter
 */
unsigned short int SPS::getEchoPin()
{
	return this->echoPin;
}

/*
 *	Trig Pin setter
 */
void SPS::setTrigPin(unsigned short int trigPin_arg)
{
	this->trigPin = trigPin_arg;
}

/*
 *	Echo Pin setter
 */
void SPS::setEchoPin(unsigned short int echoPin_arg)
{
	this->echoPin = echoPin_arg;
}
#pragma endregion 

/************************************************************************/
/*								End of File								*/
/************************************************************************/


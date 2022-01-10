/* 
* Buzzer.cpp
*
* Created: 10/7/2021 12:21:52 AM
* Author: Andi
*/

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include "Buzzer.h"
#include "..\..\..\..\ArduinoCore\include\core\Arduino.h"

#pragma endregion

/************************************************************************/
/*                         Default Constructors							*/
/************************************************************************/

#pragma region Default Constructors

/**
 *	Default constructor (empty)
 */
Buzzer::Buzzer()
{
} //Buzzer

/**
 *	Default destructor (empty)
 */
Buzzer::~Buzzer()
{
} //~Buzzer//PS

#pragma endregion

/************************************************************************/
/*                         Public Functions								*/
/************************************************************************/

#pragma region Public Functions

	/**
	 *	Custom constructor
	 *  used for initializing a new Buzzer
	 *
	 *	@param[in] sigPin_arg TriggerPin
	 */
	Buzzer::Buzzer(unsigned short int sigPin_arg) {
		this->sigPin = sigPin_arg;
	}

	/*
	 *	SigPin getter
	 */
	unsigned short int Buzzer::getSigPin()
	{
		return this->sigPin;
	}

	/*
	 *	SigPin setter
	 */
	void Buzzer::setSigPin(unsigned short int sigPin_arg)
	{
		this->sigPin = sigPin_arg;
	}

	/*
	 *	Buzz function that makes the piezo buzzer transmit sounds
	 */
	void Buzzer::Buzz(unsigned int buzzDelay_arg) {
		
		tone(this->getSigPin(), BUZZER_FREQ, BUZZER_DEFAULT_DURATION);
		delay(buzzDelay_arg);
	}

#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/
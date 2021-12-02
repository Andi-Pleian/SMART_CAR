/* 
* Buzzer.cpp
*
* Created: 10/7/2021 12:21:52 AM
* Author: Andi
*/

#pragma region Includes

#include "Buzz.h"
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
} //~Buzzer//SPS

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

	unsigned short int Buzzer::getSigPin()
	{
		return this->sigPin;
	}

	void Buzzer::setSigPin(unsigned short int sigPin_arg)
	{
		this->sigPin = sigPin_arg;
	}

	void Buzzer::Buzz(unsigned int buzzDelay_arg)
	{
		
		tone(this->getSigPin(), BUZZER_FREQ, BUZZER_DEFAULT_DURATION);
		delay(buzzDelay_arg);
		
	}

#pragma endregion

/************************************************************************/
/*                         Private Functions							*/
/************************************************************************/

#pragma region Private Functions

#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/

/* 
* Buzzer.h
*
* Created: 10/7/2021 12:21:52 AM
* Author: Andi
*/

#ifndef __BUZZER_H__
#define __BUZZER_H__

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include "Buzz_Config.h";

#pragma endregion

/************************************************************************/
/*                 Buzzer Class Implementation                          */
/************************************************************************/

#pragma region SPS Implementation

/**
 *	\brief Buzzer
 *	
 *	This class is used for implementing the buzzer used for SPS. 
 */
class Buzzer
{
	
/************************************************************************/
/*                         Private Attributes							*/
/************************************************************************/

#pragma region Private attributes

private:

	/**	Signal Pin*/
	unsigned short int	sigPin;

#pragma endregion

/************************************************************************/
/*                       Public function declarations					*/
/************************************************************************/

#pragma region Public functions declarations

public:
	Buzzer();
	~Buzzer();
	Buzzer(unsigned short int);
	
	unsigned short int getSigPin();
	
	void setSigPin(unsigned short int );
	
	void Buzz(unsigned int);
	
#pragma endregion

/************************************************************************/
/*                       Private function declarations					*/
/************************************************************************/

#pragma region Private functions declarations

private:
	
	
#pragma endregion

}; //Buzzer

#pragma endregion

#endif //__BUZZER_H__

/************************************************************************/
/*								End of File								*/
/************************************************************************/


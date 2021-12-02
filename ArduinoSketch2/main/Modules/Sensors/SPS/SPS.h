/* 
* SPS.h
*
* Smart Parking Sensor
*
* Created: 10/7/2021 12:17:58 AM
* Author: Andi
*/

#ifndef __SPS_H__
#define __SPS_H__

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include "SPS_Config.h";
#include <Buzz.h>

#pragma endregion

/************************************************************************/
/*                         SPS Class Implementation						*/
/************************************************************************/

#pragma region SPS Implementation

/**
 *	\brief Smart Parking Sensor
 *	
 *	This class is used for implementing the Smart Parking Sensor
 */
class SPS
{
	
/************************************************************************/
/*                         Public Attributes							*/
/************************************************************************/

#pragma region Public attributes
public:
	/**	Buzzer associated with this SPS*/
	Buzzer* buzzer;

#pragma endregion

/************************************************************************/
/*                         Private Attributes							*/
/************************************************************************/

#pragma region Private attributes
private:
	/**	Trigger pin*/
	unsigned short int	trigPin;
	
	/**	Echo pin*/	
	unsigned short int	echoPin;
	
#pragma endregion

/************************************************************************/
/*                       Public function declarations					*/
/************************************************************************/

#pragma region Public functions declarations
public:
	SPS();
	~SPS();
	SPS(unsigned short int, unsigned short int, unsigned short int);
	
	SPS( const SPS &s );
	
	int getDistanceToObject();
	long getWaveComebackTime();
	void serialPrintDistance();
	
	unsigned short int getTrigPin();
	unsigned short int getEchoPin();
	
	void setTrigPin(unsigned short int );
	void setEchoPin(unsigned short int );
	
	void Task();
	
#pragma endregion

}; //SPS

#pragma endregion

#endif //__SPS_H__

/************************************************************************/
/*								End of File								*/
/************************************************************************/


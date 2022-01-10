/* 
* ParkingSensor.h
*
* Parking Sensor
*
* Created: 10/7/2021 12:17:58 AM
* Author: Andi
*/

#ifndef __PS_H__
#define __PS_H__

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include "ParkingSensor_Config.h";
#include <Buzzer.h>

#pragma endregion

/************************************************************************/
/*                         ParkingSensor Class Implementation						*/
/************************************************************************/

#pragma region ParkingSensor Implementation

/**
 *	\brief Smart Parking Sensor
 *	
 *	This class is used for implementing the Smart Parking Sensor
 * 
 *  The parking sensor consists of:
 *									- one ultrasonic sensor (used for measuring distance to objects)
 *									- one piezo buzzer      (used to alert us when we are too close to an object)
 */
class ParkingSensor
{
	
/************************************************************************/
/*                         Public Attributes							*/
/************************************************************************/

#pragma region Public attributes
public:
	/**	Buzzer associated with this ParkingSensor*/
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
	ParkingSensor();
	~ParkingSensor();
	ParkingSensor(unsigned short int, unsigned short int, unsigned short int);
	
	ParkingSensor( const ParkingSensor &s );
	
	int getDistanceToObject();
	long getWaveComebackTime();
	void serialPrintDistance();
	
	unsigned short int getTrigPin();
	unsigned short int getEchoPin();
	
	void setTrigPin(unsigned short int );
	void setEchoPin(unsigned short int );
	
	void Task();
	
#pragma endregion

}; //ParkingSensor

#pragma endregion

#endif //__PS_H__

/************************************************************************/
/*								End of File								*/
/************************************************************************/


/* 
* SPS_Master.h
*
* Smart Parking Sensor Master
*
* Created: 11/1/2021 6:08:39 PM
* Author: Andi
*/


#ifndef __SPS_MASTER_H__
#define __SPS_MASTER_H__

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include "SPS.h";
#include "SPS_Config.h";
#include <Buzz.h>

#pragma endregion

/************************************************************************/
/*                       SPS_Master Class Implementation				*/
/************************************************************************/

#pragma region SPS_Master Implementation

/**
 *	\brief Smart Parking Sensor Master
 *	
 *	This class is used for implementing the Smart Parking Sensor Master. 
 */
class SPS_Master
{
	
/************************************************************************/
/*                         Public Attributes							*/
/************************************************************************/

#pragma region Public attributes
public:
	/**	Left-Front SPS*/
	SPS SPS_LF;
	
	/**	Right-Front SPS*/
	SPS SPS_RF;
	
	/**	Left-Back SPS*/
	SPS SPS_LB;
	
	/**	Right-back SPS*/
	SPS SPS_RB;
	
	/**	SPS Array*/
	SPS SPS_a[3];

#pragma endregion

/************************************************************************/
/*                         Private Attributes							*/
/************************************************************************/

#pragma region Private attributes
private:

#pragma endregion

/************************************************************************/
/*                       Public function declarations					*/
/************************************************************************/

#pragma region Public functions declarations
public:
	SPS_Master(	unsigned short int, unsigned short int, 
				unsigned short int, unsigned short int, 
				unsigned short int, unsigned short int, 
				unsigned short int, unsigned short int, 
				unsigned short int, unsigned short int, 
				unsigned short int, unsigned short int);
				
	~SPS_Master();
	
	void Master_Task();
	
#pragma endregion

}; //SPS_Master
#pragma endregion

#endif //__SPS_MASTER_H__

/************************************************************************/
/*								End of File								*/
/************************************************************************/


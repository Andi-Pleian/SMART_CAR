/* 
* SPS_Master.cpp
*
* Created: 11/1/2021 6:08:39 PM
* Author: Andi
*/

/************************************************************************/
/*								Includes								*/
/************************************************************************/

#pragma region Includes

#include "SPS_Master.h"

#pragma endregion

/************************************************************************/
/*                         Default Constructors							*/
/************************************************************************/

#pragma region Default Constructors
// default destructor
SPS_Master::~SPS_Master()
{
} //~SPS_Master
#pragma endregion

/************************************************************************/
/*                         Public Functions								*/
/************************************************************************/

#pragma region Public Functions
/**
 *	Custom constructor
 *  used for initializing a new SPS Master
 *
 *	@param[in] trigPin_arg TriggerPin for each SPS X 4
 *	@param[in] echoPin_arg EchoPin for each SPS X 4
 *	@param[in] tag_arg BuzzerPin for each SPS X 4
 */
SPS_Master::SPS_Master(	unsigned short int trigPin_LB_arg,
						unsigned short int echoPin_LB_arg,
						unsigned short int buzzerPin_LB_arg,
						unsigned short int trigPin_RB_arg,
						unsigned short int echoPin_RB_arg,
						unsigned short int buzzerPin_RB_arg,
						unsigned short int trigPin_LF_arg,
						unsigned short int echoPin_LF_arg,
						unsigned short int buzzerPin_LF_arg,
						unsigned short int trigPin_RF_arg,
						unsigned short int echoPin_RF_arg,
						unsigned short int buzzerPin_RF_arg)
{
	
	this->SPS_LB.setEchoPin(echoPin_LB_arg);
	this->SPS_LB.setTrigPin(trigPin_LB_arg);
	this->SPS_LB.buzzer->setSigPin(buzzerPin_LB_arg);
	
	this->SPS_RB.setEchoPin(echoPin_RB_arg);
	this->SPS_RB.setTrigPin(trigPin_RB_arg);
	this->SPS_RB.buzzer->setSigPin(buzzerPin_RB_arg);
	
	this->SPS_LF.setEchoPin(echoPin_LF_arg);
	this->SPS_LF.setTrigPin(trigPin_LF_arg);
	this->SPS_LF.buzzer->setSigPin(buzzerPin_LF_arg);
	
	this->SPS_RF.setEchoPin(echoPin_RF_arg);
	this->SPS_RF.setTrigPin(trigPin_RF_arg);
	this->SPS_RF.buzzer->setSigPin(buzzerPin_RF_arg);
	
	this->SPS_a[0] = SPS_LB;
	this->SPS_a[1] = SPS_RB;
	this->SPS_a[2] = SPS_LF;
	this->SPS_a[3] = SPS_RF;
} //SPS_Master_Task

void SPS_Master::Master_Task() {
	this->SPS_a[0].Task();
	this->SPS_a[1].Task();
	this->SPS_a[2].Task();
	this->SPS_a[3].Task();
}
#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/

/* 
* Motor_Control.cpp
*
* Created: 1/8/2022 2:48:48 PM
* Author: Andi
*/


#include "Motor_Control.h"

// default constructor
Motor_Control::Motor_Control()
{
} //Motor_Control

// default destructor
Motor_Control::~Motor_Control()
{
} //~Motor_Control

// default constructor
Motor_Control::Motor_Control(
								unsigned short int enA_arg, 
								unsigned short int enB_arg,
								unsigned short int in1_arg,
								unsigned short int in2_arg,
								unsigned short int in3_arg,
								unsigned short int in4_arg	) {
									
	this->enA = enA_arg;
	this->enB = enB_arg;
	
	this->rightBackward = in1_arg;
	this->rightForward = in2_arg;
	this->leftForward = in3_arg;
	this->leftBackward = in4_arg;		
									
} //Motor_Control

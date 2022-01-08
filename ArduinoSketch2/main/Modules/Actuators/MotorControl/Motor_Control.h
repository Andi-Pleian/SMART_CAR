/* 
* Motor_Control.h
*
* Created: 1/8/2022 2:48:48 PM
* Author: Andi
*/


#ifndef __MOTOR_CONTROL_H__
#define __MOTOR_CONTROL_H__


class Motor_Control {
public:
	unsigned short int enA;
	unsigned short int enB;
	
	unsigned short int in1;
	unsigned short int in2;
	unsigned short int in3;
	unsigned short int in4;

//functions
public:
	Motor_Control();
	Motor_Control(	unsigned short int, unsigned short int,
					unsigned short int, unsigned short int,
					unsigned short int, unsigned short int	);
	~Motor_Control();
protected:
private:
	Motor_Control( const Motor_Control &c );
	Motor_Control& operator=( const Motor_Control &c );

}; //Motor_Control

#endif //__MOTOR_CONTROL_H__

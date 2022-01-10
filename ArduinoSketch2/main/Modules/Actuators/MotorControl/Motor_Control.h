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
	
	unsigned short int rightBackward;
	unsigned short int rightForward;
	unsigned short int leftForward;
	unsigned short int leftBackward;

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


/************************************************************************/
/*								Motor Functions                         */
/************************************************************************/

// void forward()
// {
// 	digitalWrite(2, HIGH);
// 	digitalWrite(3, LOW);
// 	digitalWrite(5, HIGH);
// 	digitalWrite(4, LOW);
// }
// 
// void back()
// {
// 	digitalWrite(2, LOW);
// 	digitalWrite(3, HIGH);
// 	digitalWrite(4, LOW);
// 	digitalWrite(5, HIGH);
// }
// 
// void left()
// {
// 	digitalWrite(2, LOW);
// 	digitalWrite(3, HIGH);
// 	digitalWrite(4, HIGH);
// 	digitalWrite(5, LOW);
// }
// 
// void right()
// {
// 	digitalWrite(2, HIGH);
// 	digitalWrite(3, LOW);
// 	digitalWrite(4, LOW);
// 	digitalWrite(5, HIGH);
// }
// 
// void Stop()
// {
// 	digitalWrite(2, LOW);
// 	digitalWrite(3, LOW);
// 	digitalWrite(4, LOW);
// 	digitalWrite(5, LOW);
// }
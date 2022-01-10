/*
 * ParkingSensor_Config.cpp
 *
 * Parking Sensor configuration header
 *
 * Created: 10/20/2021 10:25:41 PM
 *  Author: Andi
 */ 

/************************************************************************/
/*								Defines									*/
/************************************************************************/

#pragma region Defines

/*
 *	Speed of sound in ms
 */
#define SOUND_SPEED_MS			0.034	

/*
 *	Maximum distance that can be 
 *	recorded accurately by the PS (in cm)
 */
#define PS_MAX_DISTANCE_CM		70

/*
 *	Minimum distance that can be 
 *  recorded accurately by the PS (in cm)
 */
#define PS_MIN_DISTANCE_CM		0

/*
 *	First distance stage (20 cm)
 */
#define PS_1ST_STAGE_CM		20 

/*
 *	Second distance stage (15 cm)
 */
#define PS_2ST_STAGE_CM		15

/*
 *	Third distance stage (10 cm)
 */
#define PS_3ST_STAGE_CM		10

/*
 *	Fourth distance stage (5 cm)
 */
#define PS_4ST_STAGE_CM		5

/*
 *	Fifth distance stage (2 cm)
 */
#define PS_5ST_STAGE_CM		2

#pragma endregion

/************************************************************************/
/*								End of File								*/
/************************************************************************/

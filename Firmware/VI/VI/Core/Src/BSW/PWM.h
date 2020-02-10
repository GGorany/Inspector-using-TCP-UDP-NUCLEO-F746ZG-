/*
 * PWM.h
 *
 *  Created on: Oct 20, 2019
 *      Author: DHKim
 */

#ifndef SERVO_PWM_H_
#define SERVO_PWM_H_


/**********************************************************************************************************************
* MODULES USED
**********************************************************************************************************************/
#include <stdio.h>

/**********************************************************************************************************************
* DEFINITIONS AND MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
* TYPEDEFS AND STRUCTURES
**********************************************************************************************************************/
typedef enum
{
	Forward   	= 0x00,
	Backward	= 0x01
} Direction_Type;

/**********************************************************************************************************************
* PROTOTYPES OF FUNCTIONS
**********************************************************************************************************************/
void PWM_Stop(void);
void PWM_Set(Direction_Type dir, uint16_t speed);

/**********************************************************************************************************************
* DECLARATIONS OF VARIABLES
**********************************************************************************************************************/


#endif /* SERVO_PWM_H_ */
/*
 * PWM.c
 *
 *  Created on: Oct 20, 2019
 *      Author: DHKim
 */


/**********************************************************************************************************************
* MODULES USED
**********************************************************************************************************************/
#include "PWM.h"

#include "main.h"
#include "stm32f7xx_hal.h"

/**********************************************************************************************************************
* DEFINITIONS AND MACROS
**********************************************************************************************************************/
// Init - 1Khz frequency
#define PERIOD_HERTZ	1000
#define MAX_PWM_DUTY	1000
#define PRESCALER		((216000000/MAX_PWM_DUTY)/PERIOD_HERTZ)	// 216

/**********************************************************************************************************************
* TYPEDEFS AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
* PROTOTYPES OF FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
* DECLARATIONS OF VARIABLES
**********************************************************************************************************************/
extern TIM_HandleTypeDef htim2;


/*--------------------------------------------------------------------------*/
/* Name      | Operation_Init                                               */
/*--------------------------------------------------------------------------*/
void PWM_Stop(void)
{
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
}

/*--------------------------------------------------------------------------*/
/* Name      | Operation_Set                                                */
/*--------------------------------------------------------------------------*/
void PWM_Set(Direction_Type dir, uint16_t speed)
{
	if (dir == Backward)
	{
		HAL_GPIO_WritePin(SERVO_DIRECTION_GPIO_Port, SERVO_DIRECTION_Pin, GPIO_PIN_RESET);
	}
	else //  (dir == Forward)
	{
		HAL_GPIO_WritePin(SERVO_DIRECTION_GPIO_Port, SERVO_DIRECTION_Pin, GPIO_PIN_SET);
	}

	// speed 1 is 10Hz Period		// speed 1000 is 10000Hz Period
	if (speed == 0)
	{
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
	}
	else
	{
		__HAL_TIM_SET_PRESCALER(&htim2, (int)(21600/speed));
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 500);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	}
}

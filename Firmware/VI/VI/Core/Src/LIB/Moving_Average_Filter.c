/*
 * Moving_Average_Filter.c
 *
 *  Created on: Nov 29, 2019
 *      Author: DH.Kim
 */


/**********************************************************************************************************************
* MODULES USED
**********************************************************************************************************************/
#include "Moving_Average_Filter.h"

/**********************************************************************************************************************
* DEFINITIONS AND MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
* TYPEDEFS AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
* PROTOTYPES OF FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
* DECLARATIONS OF VARIABLES
**********************************************************************************************************************/


/*--------------------------------------------------------------------------*/
/* Function  | Create the moving average filter                             */
/* Name      | moving_average_create                                        */
/*--------------------------------------------------------------------------*/
/* Parameter | Nothing                                                      */
/* Return    | Nothing                                                      */
/*--------------------------------------------------------------------------*/
void moving_average_create(movingAverage_t *context, uint16_t *buffer, uint8_t bufferSize)
{
    context->size = bufferSize;
    context->buffer = buffer;
    context->index = 0;
    context->sum = 0;
    context->fill = 0;
    context->filtered = 0;
}

/*--------------------------------------------------------------------------*/
/* Function  | filter the moving average                                    */
/* Name      | moving_average_filter                                        */
/*--------------------------------------------------------------------------*/
/* Parameter | Nothing                                                      */
/* Return    | Nothing                                                      */
/*--------------------------------------------------------------------------*/
void moving_average_filter(movingAverage_t *context, uint16_t data)
{
    if (context->fill)
    {
        context->sum -= context->buffer[context->index];
    }

    context->buffer[context->index] = data;
    context->sum += context->buffer[context->index];

    context->index++;
    if (context->index >= context->size)
    {
        context->index = 0;
    }

    if (context->fill < context->size)
    {
        context->fill++;
    }

    context->filtered = (uint16_t)(context->sum / context->fill);
}


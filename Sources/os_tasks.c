/* ###################################################################
**     Filename    : os_tasks.c
**     Project     : dd_scheduler
**     Processor   : MK22FN512VLH12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-03-24, 22:43, # CodeGen: 40
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Aperiodic_task - void Aperiodic_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file os_tasks.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup os_tasks_module os_tasks module documentation
**  @{
*/         
/* MODULE os_tasks */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "generator_task.h"
#include "scheduler_task.h"
#include "monitor_task.h"
#include "periodic_task.h"
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "dd_scheduler.h"

#define APERIODIC_EXEC_TIME (1000)

/*
** ===================================================================
**     Callback    : Aperiodic_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Aperiodic_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	GPIO_DRV_ClearPinOutput(LEDRGB_BLUE);
	GPIO_DRV_ClearPinOutput(LEDRGB_RED);
	GPIO_DRV_ClearPinOutput(LEDRGB_GREEN);
	for (uint32_t i=0; i < DELAY_CONST*APERIODIC_EXEC_TIME; i++);
	GPIO_DRV_SetPinOutput(LEDRGB_BLUE);
	GPIO_DRV_SetPinOutput(LEDRGB_RED);
	GPIO_DRV_SetPinOutput(LEDRGB_GREEN);

	uint32_t result = dd_delete(_task_get_id());
	assert(result == MQX_OK);
}

/* END os_tasks */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

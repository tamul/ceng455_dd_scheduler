/* ###################################################################
**     Filename    : rtos_main_task.c
**     Project     : dd_scheduler
**     Processor   : MK22FN512VLH12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-03-17, 13:08, # CodeGen: 1
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         main_task - void main_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file rtos_main_task.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup rtos_main_task_module rtos_main_task module documentation
**  @{
*/         
/* MODULE rtos_main_task */

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
#include <klog.h>
#include <mqx.h>
#include <timer.h>

#include "task_list.h"

/* Initialization of Processor Expert components function prototype */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
extern void PEX_components_init(void);
#endif 

/*
** ===================================================================
**     Callback    : main_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void main_task(os_task_param_t task_init_data)
{

  /* Initialization of Processor Expert components (when some RTOS is active). DON'T REMOVE THIS CODE!!! */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
  PEX_components_init(); 
#endif 
  /* End of Processor Expert components initialization.  */

//  _int_install_unexpected_isr();
  _mqx_uint old_prior;

  // Initialize mutexes
  tasks_m = _mem_alloc(sizeof(MUTEX_STRUCT));
  tasks_m_attr = _mem_alloc(sizeof(MUTEX_ATTR_STRUCT));
  assert(_mutatr_init(tasks_m_attr) == MQX_EOK);
  assert(_mutatr_set_wait_protocol(tasks_m_attr, MUTEX_PRIORITY_QUEUEING) == MQX_EOK);
  assert(_mutex_init(tasks_m, tasks_m_attr) == MQX_EOK);

  // Init timer component
  _timer_create_component(0, 2048);
  // Priority of 0 sets default priority, not actual 0 priority.
  // Timer task's id is the next free ID, which will be our ID plus one.
  _task_set_priority(_task_get_id()+1,
		  _sched_get_max_priority(MQX_SCHED_FIFO)+1, &old_prior);

  // create kernel log
  _klog_create(2048, 0);
  _klog_control(KLOG_ENABLED | KLOG_CONTEXT_ENABLED |
		  KLOG_TASKING_FUNCTIONS |
		  KLOG_FUNCTIONS_ENABLED |
		  KLOG_IO_FUNCTIONS, TRUE);
  _klog_control(KLOG_INTERRUPTS_ENABLED, FALSE);

  // Initialize scheduler, generator tasks
  _task_id sched = _task_create(0, SCHEDULER_TASK, 0);
  _task_set_priority(sched, _sched_get_max_priority(MQX_SCHED_FIFO), &old_prior);
  _task_id gen = _task_create(0, GENERATOR_TASK, 0);
  _task_set_priority(gen, _sched_get_max_priority(MQX_SCHED_FIFO)+1, &old_prior);

  _task_block();
}

/* END rtos_main_task */

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

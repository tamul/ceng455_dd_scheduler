/*
 * task_list.h
 *
 *  Created on: Mar 22, 2018
 *      Author: mtayler
 */

#ifndef SOURCES_TASK_LIST_H_
#define SOURCES_TASK_LIST_H_

#include <mqx.h>
#include <mutex.h>
#include <timer.h>

// Synchronize between list activity
MUTEX_ATTR_STRUCT_PTR tasks_m_attr = NULL;
MUTEX_STRUCT_PTR tasks_m = NULL;


// List of running tasks
typedef struct task_list {
	uint32_t tid;
	MQX_TICK_STRUCT deadline;
	uint32_t task_type;
	MQX_TICK_STRUCT creation_time;
	_timer_id timer;
	struct task_list *next_cell;
	struct task_list *previous_cell;
} task_list_t, * task_list_ptr;

/* ----------------------------------------------------------------------------
 * add_task					Add a task to the sorted linked list
 * ----------------------------------------------------------------------------
 * Arguments:
 *  task_list_ptr * list	Task list to add task to.
 * 	task_list_ptr task		Task to add to the list, next_cell and previous_cell
 * 								will be overwritten by this function.
 * Returns:
 * 	Nothing
 *
 * Adds the task to the list of tasks, sorted by deadline.
 */
void add_task(task_list_ptr * list, task_list_ptr task);

/* ----------------------------------------------------------------------------
 * delete_task				Add a task to the sorted linked list
 * ----------------------------------------------------------------------------
 * Arguments:
 *  task_list_ptr * list	Task list to delete the task from.
 * 	_task_id tid			Task ID of the task to remove from the list.
 * Returns:
 * 	_mqx_uint				MQX_OK if success, otherwise error.
 *
 * Removes the task specified by _task_id from the task list
 */
task_list_ptr delete_task(task_list_ptr * list, _task_id tid);

/* ----------------------------------------------------------------------------
 * get_task				Get a task from the sorted linked list
 * ----------------------------------------------------------------------------
 * Arguments:
 *  task_list_ptr list	Task list to find the associated task from.
 * 	_task_id tid		Task ID of the task_list entry to find.
 *
 * Returns:
 * 	task_list_ptr		Pointer to the task with ID tid, NULL if not found.
 *
 * Get the pointer to a task_list item with specified ID.
 */
task_list_ptr get_task(task_list_ptr list, _task_id tid);

/* ----------------------------------------------------------------------------
 * update_priorities		Set priority of each task in the list
 * ----------------------------------------------------------------------------
 * Arguments:
 *  task_list_ptr list		Task list to set priorities for.
 *  uint32_t start_priority	The priority to start assigning after.
 *
 * Returns:
 * 	_mqx_uint				The lowest assigned priority or 0 on an error.
 *
 * Sets ascending priorities for each task in the list.
 */
_mqx_uint update_priorities(task_list_ptr list, uint32_t start_priority);

#endif /* SOURCES_TASK_LIST_H_ */

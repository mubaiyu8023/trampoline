/**
 * @file tpl_time_enforcement.h
 *
 * @section descr File description
 *
 * Function to wait for a date. Used in time enforcement
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_TIME_ENFORCEMENT
#define TPL_TIME_ENFORCEMENT

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_app_custom_types.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

extern VAR(uint32, OS_VAR) tpl_time_enforcement_timers_init[];
extern VAR(uint32, OS_VAR) tpl_time_enforcement_timers[];

/*
 * Start a stopwatch
 */
FUNC(void, OS_APPL_CODE) tpl_start_enforcement_timer(void);

/*
 * Wait for a stopwatch
 */
FUNC(void, OS_APPL_CODE) tpl_wait_enforcement_timer(
  CONST(uint32, AUTOMATIC) startDate,
  CONST(uint32, AUTOMATIC) absoluteDeadline);

/*
 * Get the current value of the enforcement timers
 */
FUNC(uint32, OS_APPL_CODE) tpl_get_enforcement_timer(void);

/*
 * Set the current value of the enforcement timers
 */
FUNC(void, OS_APPL_CODE) tpl_set_enforcement_timer(
  CONST(uint32, AUTOMATIC) time);

/*
 * Save the enforcement timer to a table indexed by the task id
 */
FUNC(void, OS_APPL_CODE) tpl_save_enforcement_timer(
  CONST(tpl_proc_id, AUTOMATIC) task_id);

/*
 * Retore the enforcement timer to a table indexed from the task id
 */
FUNC(void, OS_APPL_CODE) tpl_restore_enforcement_timer(
  CONST(tpl_proc_id, AUTOMATIC) task_id);

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_TIME_ENFORCEMENT */
#endif
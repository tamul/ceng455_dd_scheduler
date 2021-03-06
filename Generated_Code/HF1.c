/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : HF1.c
**     Project     : dd_scheduler
**     Processor   : MK22FN512VLH12
**     Component   : HardFault
**     Version     : Component 01.001, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-03-23, 21:11, # CodeGen: 26
**     Abstract    :
**          Component to simplify hard faults for ARM/Kinetis.
**     Settings    :
**          Component name                                 : HF1
**     Contents    :
**         HardFaultHandler - void HF1_HardFaultHandler(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     Web:    www.mcuoneclipse.com
**     This an open source software for Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file HF1.c
** @version 01.00
** @brief
**          Component to simplify hard faults for ARM/Kinetis.
*/         
/*!
**  @addtogroup HF1_module HF1 module documentation
**  @{
*/         

/* MODULE HF1. */

#include "HF1.h"


/* Internal method prototypes */
static void HandlerC(uint32_t *hardfault_args);

/*
** ===================================================================
**     Method      :  HandlerC (component HardFault)
**
**     Description :
**         Additional handler which decodes the processor status
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/**
 * HardFaultHandler_C:
 * This is called from the HardFaultHandler with a pointer the Fault stack
 * as the parameter. We can then read the values from the stack and place them
 * into local variables for ease of reading.
 * We then read the various Fault Status and Address Registers to help decode
 * cause of the fault.
 * The function ends with a BKPT instruction to force control back into the debugger
 */
static void HandlerC(uint32_t *hardfault_args)
{
  volatile unsigned long stacked_r0;
  volatile unsigned long stacked_r1;
  volatile unsigned long stacked_r2;
  volatile unsigned long stacked_r3;
  volatile unsigned long stacked_r12;
  volatile unsigned long stacked_lr;
  volatile unsigned long stacked_pc;
  volatile unsigned long stacked_psr;
  volatile unsigned long _CFSR;
  volatile unsigned long _HFSR;
  volatile unsigned long _DFSR;
  volatile unsigned long _AFSR;
  volatile unsigned long _BFAR;
  volatile unsigned long _MMAR;

  /* suppress warnings about unused variables */
  (void)stacked_r0;
  (void)stacked_r1;
  (void)stacked_r2;
  (void)stacked_r3;
  (void)stacked_r12;
  (void)stacked_lr;
  (void)stacked_pc;
  (void)stacked_psr;
  (void)_CFSR;
  (void)_HFSR;
  (void)_DFSR;
  (void)_AFSR;
  (void)_BFAR;
  (void)_MMAR;

  stacked_r0 = ((unsigned long)hardfault_args[0]);
  stacked_r1 = ((unsigned long)hardfault_args[1]);
  stacked_r2 = ((unsigned long)hardfault_args[2]);
  stacked_r3 = ((unsigned long)hardfault_args[3]);
  stacked_r12 = ((unsigned long)hardfault_args[4]);
  stacked_lr = ((unsigned long)hardfault_args[5]);
  stacked_pc = ((unsigned long)hardfault_args[6]);
  stacked_psr = ((unsigned long)hardfault_args[7]);

  /* Configurable Fault Status Register */
  /* Consists of MMSR, BFSR and UFSR */
  _CFSR = (*((volatile unsigned long *)(0xE000ED28)));

  /* Hard Fault Status Register */
  _HFSR = (*((volatile unsigned long *)(0xE000ED2C)));

  /* Debug Fault Status Register */
  _DFSR = (*((volatile unsigned long *)(0xE000ED30)));

  /* Auxiliary Fault Status Register */
  _AFSR = (*((volatile unsigned long *)(0xE000ED3C)));

  /* Read the Fault Address Registers. These may not contain valid values.
   * Check BFARVALID/MMARVALID to see if they are valid values
   * MemManage Fault Address Register
   */
  _MMAR = (*((volatile unsigned long *)(0xE000ED34)));
  /* Bus Fault Address Register */
  _BFAR = (*((volatile unsigned long *)(0xE000ED38)));

  __asm("BKPT #0\n") ; /* cause the debugger to stop */
}

/*
** ===================================================================
**     Method      :  HF1_HardFaultHandler (component HardFault)
**     Description :
**         Hard Fault Handler
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__attribute__((naked))
void HF1_HardFaultHandler(void)
{
  __asm volatile (
    " movs r0,#4      \n"  /* load bit mask into R0 */
    " movs r1, lr     \n"  /* load link register into R1 */
    " tst r0, r1      \n"  /* compare with bitmask */
    " beq _MSP        \n"  /* if bitmask is set: stack pointer is in PSP. Otherwise in MSP */
    " mrs r0, psp     \n"  /* otherwise: stack pointer is in PSP */
    " b _GetPC        \n"  /* go to part which loads the PC */
    "_MSP:            \n"  /* stack pointer is in MSP register */
    " mrs r0, msp     \n"  /* load stack pointer into R0 */
    "_GetPC:          \n"  /* find out where the hard fault happend */
    " ldr r1,[r0,#20] \n"  /* load program counter into R1. R1 contains address of the next instruction where the hard fault happened */
    " b HandlerC      \n"  /* decode more information. R0 contains pointer to stack frame */
  );
  HandlerC(0); /* dummy call to suppress compiler warning */
}

/* END HF1. */

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

/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : HF1.h
**     Project     : dd_scheduler
**     Processor   : MK22FN512VLH12
**     Component   : HardFault
**     Version     : Component 01.001, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-03-23, 04:21, # CodeGen: 28
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
** @file HF1.h
** @version 01.00
** @brief
**          Component to simplify hard faults for ARM/Kinetis.
*/         
/*!
**  @addtogroup HF1_module HF1 module documentation
**  @{
*/         

#ifndef __HF1_H
#define __HF1_H

/* MODULE HF1. */

/* Include inherited beans */

#include "Cpu.h"




void HF1_HardFaultHandler(void);
/*
** ===================================================================
**     Method      :  HF1_HardFaultHandler (component HardFault)
**     Description :
**         Hard Fault Handler
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END HF1. */

#endif
/* ifndef __HF1_H */
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

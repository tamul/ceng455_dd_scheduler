
/*HEADER**********************************************************************
*
* Copyright 2013 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale MQX RTOS License
* distributed with this Material.
* See the MQX_RTOS_LICENSE file distributed for more details.
*
* Brief License Summary:
* This software is provided in source form for you to use free of charge,
* but it is not open source software. You are allowed to use this software
* but you cannot redistribute it or derivative works of it in source form.
* The software may be used only in connection with a product containing
* a Freescale microprocessor, microcontroller, or digital signal processor.
* See license agreement file for full license terms including other restrictions.
*****************************************************************************
*
* Comments:
*
*   This is a private header for stdio.h header.
*
*
*END************************************************************************/
#ifndef __std_prv_h__
#define __std_prv_h__

#include <fcntl.h>
#include <nio.h>
#include <stdint.h>

#ifndef STD_FP_IO
#define STD_FP_IO 0
#endif
//Wraper for standard io
#ifndef _OPEN
#define _OPEN(name, flags, mode)    open(name, flags, mode)
#endif
#ifndef _CLOSE
#define _CLOSE(fd)                  close(fd)
#endif
#ifndef _READ
#define _READ(fd, buf, nbytes)      read(fd, buf, nbytes)
#endif
#ifndef _WRITE
#define _WRITE(fd, buf, nbytes)     write(fd, buf, nbytes)
#endif
#ifndef _LSEEK
#define _LSEEK(fd, offset, whence)  lseek(fd, offset, whence)
#endif
#ifndef _STD_LOCK
#define _STD_LOCK()                 _int_disable()
#endif
#ifndef _STD_UNLOCK
#define _STD_UNLOCK()               _int_enable()
#endif

#define _MODE_ORDONLY    O_RDONLY    /* open for reading only */
#define _MODE_OWRONLY    O_WRONLY    /* open for writing only */
#define _MODE_ORDWR      O_RDWR      /* open for reading and writing */
#define _MODE_OACCMODE   O_ACCMODE   /* mask for above modes */
#define _MODE_OAPPEND    O_APPEND    /* set append mode */
#define _MODE_OTRUNC     O_TRUNC     /* truncate to zero length */
#define _MODE_OCREAT     O_CREAT     /* create if nonexistant */

/* Set if file should be freed on close */
#define _MODE_FOC       (0x00010000)
#define _MODE_EOF       (0x00020000)
#define _MODE_ERR       (0x00040000)

/* If value in one byte buffer is valid for write */
#define _MODE_LASTCR    (0x00080000)
/* If value in one byte buffer is valid for read */
#define _MODE_UC        (0x00100000)

#endif

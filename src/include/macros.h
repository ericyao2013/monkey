/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Monkey HTTP Daemon
 *  ------------------
 *  Copyright (C) 2001-2011, Eduardo Silva P. <edsiper@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef MK_MACROS_H
#define MK_MACROS_H

#include <stdlib.h>
#include "limits.h"

/* Boolean */
#define MK_TRUE   1
#define MK_FALSE  0
#define MK_ERROR -1

/* Architecture */
#define INTSIZE sizeof(int)

/* Print macros */
#define MK_INFO     0x1000
#define MK_ERR      0X1001
#define MK_WARN     0x1002
#define MK_BUG      0x1003

#define mk_info(...)  mk_print(MK_INFO, __VA_ARGS__)
#define mk_err(...)   mk_print(MK_ERR, __VA_ARGS__)
#define mk_warn(...)  mk_print(MK_WARN, __VA_ARGS__)

/* ANSI Colors */
#define ANSI_BOLD "\033[1m"
#define ANSI_CYAN "\033[36m" 
#define ANSI_MAGENTA "\033[35m"
#define ANSI_RED "\033[31m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"
#define ANSI_GREEN "\033[32m"
#define ANSI_WHITE "\033[37m"
#define ANSI_RESET "\033[0m"

/* Transport type */
#define MK_TRANSPORT_HTTP  "http"
#define MK_TRANSPORT_HTTPS "https"

/* 
 * Validation macros
 * -----------------
 * Based on article http://lwn.net/Articles/13183/
 *
 * ---
 * ChangeSet 1.803, 2002/10/18 16:28:57-07:00, torvalds@home.transmeta.com
 *
 *	Make a polite version of BUG_ON() - WARN_ON() which doesn't
 *	kill the machine.
 *	
 *	Damn I hate people who kill the machine for no good reason. 
 * ---
 *
 */

#define unlikely(x) __builtin_expect((x),0)

#define mk_bug(condition) do {                  \
        if (unlikely((condition)!=0)) {         \
            mk_print(MK_BUG, "Bug found in %s() at %s:%d",             \
                     __FUNCTION__, __FILE__, __LINE__);                 \
            abort();                                                    \
        }                                                               \
} while(0)

#endif

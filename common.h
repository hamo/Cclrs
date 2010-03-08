/*
 *
 * Copyright (C) 2010 Yang Hamo Bai < hamo.by@gmail.com >
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#ifndef RETURN_VALUE
#define RETURN_VALUE
#define SUCCESS 0
#define FAILURE 1
#endif

#ifndef BOOL
#define BOOL
#define TRUE 1
#define FALSE 0
#endif

#ifndef ERRCODE
#define ERRCODE
#define NOERR 0
#define ALLOCMEM -1
#define INPUTERR -2
#endif

int err(int);  // deal with some errors

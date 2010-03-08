/*
 *
 * Copyright (C) 2010 Yang Hamo Bai < hamo.by@gmail.com >
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int err(int errcode){  // deal with some errors
    switch(errcode) {
        case ALLOCMEM: fprintf(stderr,"ALLOC MEMORY ERROR!EXIT!\n");
                       exit(-1);
        case INPUTERR: fprintf(stderr,"INPUT ERR.EXIT!\n");
                       exit(-1);
    }
}

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
#include "../common.h"
#include "insertion-sort.h"

int insertionsort(long * p,long length){
    long *out;
    long *in;
    for(out = p+1;out < p+length;out++){
        long key = *(out);
        in = out -1;
        while(in >= p && *in > key){
            *(in +1)=*(in);
            in--;
        }
        *(in + 1)=key;
    }
	return SUCCESS;
}

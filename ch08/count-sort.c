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
#include <limits.h>
#include "../common.h"
#include "count-sort.h"

int countsort(long * p,long from,long to){
    long max = maxone(p,from,to);
    long * tmp = malloc((max+1) * sizeof(long));
    if (tmp == NULL){
        err(ALLOCMEM);
    }
    long ptr;
    for (ptr = 0;ptr < max + 1;ptr++){
        tmp[ptr]=0;
    }
    for (ptr = from;ptr <= to;ptr++){
        tmp[p[ptr]]++;
    }
    long move = 0;
    for (ptr = 0;ptr < max +1;ptr++){
        if (tmp[ptr] != 0){
            long i;
            for (i = tmp[ptr];i>0;i--){
                p[move] = ptr;
                move++;
            }
        }
    }
}

long maxone(long * p,long from,long to){
    long max = LONG_MIN;
    for (;from <= to;from++){
        if (p[from] < 0){
            err(INPUTERR);
        }
        if (p[from] > max){
            max = p[from];
        }
    }
    return max;
}

int mt(long a,long b){
    return (a > b) ? TRUE : FALSE;
}

int lt(long a,long b){
    return (a < b) ? TRUE : FALSE;
}

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
#include "heapsort.h"

int swap(long *p,long a,long b){
    long tmp;
    tmp = p[a];
    p[a] = p[b];
    p[b] = tmp;
}

int maxheapify(long *p,long size,long number){
    long l,r;
    long ll,rl;
    long largest;
    l = left(number);
    r = right(number);
    ll = num2lower(l);
    rl = num2lower(r);
    if (l <= size && p[ll] > p [num2lower(number)]){
        largest = l;
    }
    else{
        largest = number;
    }
    if (r <= size && p[rl] > p[num2lower(largest)]){
        largest = r;
    }
    if (largest != number){
        swap(p,num2lower(number),num2lower(largest));
        maxheapify(p,size,largest);
    }
    return SUCCESS;
}

int buildmaxheap(long *p,long length){
    long size = length;
    long i;
    for (i = length / 2;i > 0;i--){
        maxheapify(p,size,i);
    }
}

int heapsort(long *p,long length){
    buildmaxheap(p,length);
    long i;
    long size=length;
    for(i=length;i>1;i--){
        swap(p,0,num2lower(i));
        size -= 1;
        maxheapify(p,size,1);
    }
}

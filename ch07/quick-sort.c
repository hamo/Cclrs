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
#include <time.h>
#include "../common.h"
#include "quick-sort.h"

int quicksort(long * p,long from,long to,int (*compare)(long,long)){
	if (from < to){
		long q;
		q = partition(p,from,to,compare);
		quicksort(p,from,q-1,compare);
		quicksort(p,q+1,to,compare);
	}
	else
		return;
}

long partition(long * p,long from,long to,int (*compare)(long,long)){
    srand(time(NULL));
    double random;
    random = (double)rand();
    random = random * 0.1 - (int)(random * 0.1);
    long middle;
    middle = from + (long)((to - from) * random);
    swap(p,middle,to); 
    long std = p[to];
    long former = from - 1;
    long ptr;
    for (ptr = from ; ptr <= to - 1;ptr++){
        if (compare(p[ptr],std)){
            former++;
            swap(p,former,ptr);
        }
    }
    swap(p,former + 1,to);
    return former + 1;
}

int swap(long * p,long a,long b){
	long tmp;
	tmp = p[a];
	p[a] = p[b];
	p[b] = tmp;
	return SUCCESS;
}

int mt(long a,long b){
    return (a > b) ? TRUE : FALSE;
}

int lt(long a,long b){
    return (a < b) ? TRUE : FALSE;
}

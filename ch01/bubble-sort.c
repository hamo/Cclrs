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
#include "bubble-sort.h"

int bubblesort(long * p,long length,int (*compare)(long,long)){
    long i,j;
    for(i =0; i < length;i++){
        for(j=length-1;j>i;j--){
            if((*compare)(p[j],p[j-1])){
                long tmp;
                tmp = p[j-1];
                p[j-1]=p[j];
                p[j]=tmp;
            }
        }
    }
	return SUCCESS;
}

int mt(long a,long b){
    return (a > b) ? TRUE : FALSE;
}

int lt(long a,long b){
    return (a < b) ? TRUE : FALSE;
}

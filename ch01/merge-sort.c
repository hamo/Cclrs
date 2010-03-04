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
#include "merge-sort.h"

int merge(long *p,long n1,long n2,long n3,int (*compare)(long,long)){
    long i,j,k;
    long number1 = n2 - n1 + 1;
    long number2 = n3 - n2 ;
    long *p1,*p2;
    p1 = malloc((number1+1)*sizeof(long));
    p2 = malloc((number2+1)*sizeof(long));
    if (p1 == NULL || p2 == NULL){
        errcode = -1;
        goto err;
    }
    for (i = 0;i < number1;i++){
        p1[i] = p[n1 + i];
    }
    p1[i]=LONG_MAX;
    for (i = 0;i < number2;i++){
        p2[i] = p[n2 + 1 + i];
    }
    p2[i]=LONG_MAX;
    i=0;
    j=0;
    for(k=n1;k <= n3;k++){
        if (p1[i] == LONG_MAX){
            p[k] = p2[j];
            j++;
        }
        else if (p2[j] == LONG_MAX){
            p[k] = p1[i];
            i++;
        }
        else if (compare(p1[i],p2[j])){
            p[k] = p1[i];
            i++;
        }
        else {
            p[k] = p2[j];
            j++;
        }
    }
    free(p1);
    free(p2);
    return SUCCESS;

err:switch(errcode) {
        case ALLOCMEM: fprintf(stderr,"ALLOC MEMORY ERROR!EXIT!\n");
                       exit(-1);
    }
}

int mergesort(long * p,long n1,long n3,int (*compare)(long,long)){
    int i;
    long n2;
    if (n1 < n3){
        n2 = (n1 + n3) /2;
        mergesort(p,n1,n2,compare);
        mergesort(p,n2+1,n3,compare);
        merge(p,n1,n2,n3,compare);
    }
    return SUCCESS;
}

int mt(long a,long b){
    return (a > b) ? TRUE : FALSE;
}

int lt(long a,long b){
    return (a < b) ? TRUE : FALSE;
}

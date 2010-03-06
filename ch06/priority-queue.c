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
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "../common.h"
#include "priority-queue.h"

queue * NewQueue(long maxlen){
    queue * p;
    p = malloc(sizeof(queue));
    if (p == NULL){
        err(ALLOCMEM);
    }
    element * q;
    q = malloc(maxlen * sizeof(element));
    if (q == NULL){
        err(ALLOCMEM);
    }
    p->maxlen = maxlen;
    p->currentlen = 0;
    p->ele = q;
    return p;
}

element * NewElement(int prior,char * text){
    element * p;
    p = malloc(sizeof(element));
    if (p == NULL){
        err(ALLOCMEM);
    }
    p->prior = prior;
    strcpy(p->text,text);
    return p;
}

int DelElement(element * p){
    if (p == NULL){
        printf("Del NULL pointer.Maybe some errors happen.\n");
        return SUCCESS;
    }
    else {
        free(p);
        return SUCCESS;
    }
}

int insert(queue * p,element * e){
    if (p->currentlen == p-> maxlen){
        printf("Queue is full.Insert failed.\n");
        return FAILURE;
    }
    (p->currentlen)++;
    (p->ele)[num2sub(p->currentlen)].prior = INT_MIN;
    strcpy((p->ele)[num2sub(p->currentlen)].text,e->text);
    IncreaseKey(p,p->currentlen,e->prior);
    return SUCCESS;
}

element Maximum(queue * p){
    if (p->currentlen == 0){
        printf("No element in queue.\n");
        return;
    }
    return p->ele[0];
}

element ExtractMax(queue * p){
    if (p->currentlen == 0){
        printf("No element in queue.\n");
        return;
    }
    element e;
    e.prior = (p->ele)[0].prior;
    strcpy(e.text,(p->ele)[0].text);
    (p->ele)[0].prior = (p->ele)[num2sub(p->currentlen)].prior;
    strcpy((p->ele)[0].text,(p->ele)[num2sub(p->currentlen)].text);
    p->currentlen --;
    QueueMaxHeapify(p,p->currentlen,1);
    return e;
}

int IncreaseKey(queue * p,long number,int k){
    if((p->currentlen) < number){
        printf("No element %d,noting to do.",number);
        return SUCCESS;
    }
    else if((p->ele)[num2sub(number)].prior > k){
        printf("current priority is more than %d,nothing to do.",k);
        return SUCCESS;
    }
    else {
        (p->ele)[num2sub(number)].prior = k;
        while(number > 1 && (p->ele)[num2sub(parent(number))].prior < (p->ele)[num2sub(number)].prior){
            SwapElement(p,num2sub(number),num2sub(parent(number)));
            number = parent(number);
        }
        return SUCCESS;
    }
}

int SwapElement(queue *p,long a,long b){
    element tmp;
    tmp.prior = (p->ele)[a].prior;
    strcpy(tmp.text,(p->ele)[a].text);
    (p->ele)[a].prior = (p->ele)[b].prior;
    strcpy((p->ele)[a].text,(p->ele)[b].text);
    (p->ele)[b].prior = tmp.prior;
    strcpy((p->ele)[b].text,tmp.text);
    return SUCCESS;
}

int QueueMaxHeapify(queue * p,long size,long number){
    long l,r;
    long ll,rl;
    long largest;
    l = left(number);
    r = right(number);
    ll = num2sub(l);
    rl = num2sub(r);
    if (l <= size && (p->ele)[ll].prior > (p->ele)[num2sub(number)].prior){
        largest = l;
    }
    else{
        largest = number;
    }
    if (r <= size && (p->ele)[rl].prior > (p->ele)[num2sub(largest)].prior){
        largest = r;
    }
    if (largest != number){
        SwapElement(p,num2sub(number),num2sub(largest));
        QueueMaxHeapify(p,size,largest);
    }
    return SUCCESS;
}

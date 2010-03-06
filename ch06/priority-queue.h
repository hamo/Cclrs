/*
 *
 * Copyright (C) 2010 Yang Hamo Bai < hamo.by@gmail.com >
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#define parent(X) (X/2)

#define left(X) (2*X)

#define right(X) (2*X + 1)

#define num2sub(X) (X - 1)

typedef struct ele{
    int prior;
    char text[500];
} element;

typedef struct que{
    long maxlen;  // max length of queue
    long currentlen; //current length of queue
    element * ele;  // point to the first element of queue
} queue;

queue * NewQueue(long); // create a new queue

element * NewElement(int,char *); //create a new element

int DelElement(element *); //destroy an element

int insert(queue *,element *);  // insert element into queue

element Maximum(queue *);  // return the maximum priority element.

element ExtractMax(queue *); // return the maximum priority element and remove it from the queue.

int IncreaseKey(queue * p,long number,int k);  // increase the prior of  p[subtitle] to k.

int SwapElement(queue *p,long a,long b);

int QueueMaxHeapify(queue *,long size,long number);

/*
 *
 * Copyright (C) 2010 Yang Hamo Bai < hamo.by@gmail.com >
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

int bubblesort(long * p,long length,int (*compare)(long,long));
/* bubble-sort function. p pointer should be pointed to the first element of the array and length should be the length of the array,compare function return TRUE when that two numbers are order-right. */

int mt(long a,long b);  //more than

int lt(long a,long b);  //less than

/*
 *
 * Copyright (C) 2010 Yang Hamo Bai < hamo.by@gmail.com >
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

int mergesort(long * p,long n1,long n2);
/* merge-sort function. p pointer should be the name of the array ,n1 is the first element number to sort and n2 should be the last element number to sort. */

int merge(long * p,long n1,long n2,long n3);
/* merge two arrays,the first array is from n1 to n2,the second is from n2 to n3.used by function mergesort. */

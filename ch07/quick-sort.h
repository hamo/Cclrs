/*
 *
 * Copyright (C) 2010 Yang Hamo Bai < hamo.by@gmail.com >
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

int quicksort(long * p,long from,long to,int (*compare)(long,long));

long partition(long * p,long from,long to,int (*compare)(long,long));

int swap(long * p,long a,long b);

int mt(long a,long b);

int lt(long a,long b);

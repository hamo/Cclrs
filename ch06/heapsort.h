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

#define num2lower(X) (X - 1)

int maxheapify(long *p,long size,long number);

int buildmaxheap(long *p,long length);

int heapsort(long *p,long length);

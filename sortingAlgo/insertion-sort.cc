/**
 *  \file insertion-sort.cc
 *
 *  \brief Implement your insertion sort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

void
mySort (int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
	int i,j,key;
	for(j=1;j<N;j++)
	{
		key=A[j];//get the key at element A[j]
		i=j-1;//get the ith index
		while(i>=0 && A[i]>key)
		{
			A[i+1]=A[i];//swap element
			i=i-1;//adjust the ith index
			A[i+1]=key;//swap element
		}

	}
}

/* eof */

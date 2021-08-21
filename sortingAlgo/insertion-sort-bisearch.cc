/**
 *  \file insertion-sort-bisearch.cc
 *
 *  \brief Implement your insertion sort with binary search in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.hh"

int binarySearch(keytype * A, int item, int low, int high)
{
  int mid=(low + high)/2;
  if(high<=low)
    return (A[low]<item) ? (low+1):low;

  if(item==A[mid])//return mid+1;
    return mid;
  else if(item>A[mid])//if the item is greater than the item at the middle of our list
    return binarySearch(A,item,mid+1,high);//check on the second half of the list
  else //if item is less than the item at the middle of our list
   return binarySearch(A,item,low,mid-1);//then check in the lower half of the array
}


void mySort(int N, keytype *A)
{
  /* Lucky you, you get to start from scratch */	
  int key,i,j,position;
  for(j=1;j<N;j++)
  {
  	 key=A[j];//get the key at element A[j]
  	 i=j-1;//get the ith index
  	 //find the position where the selected element should be inserted
  	 position=binarySearch(A,key,0,j);

  	 //MOve all elements
  	 while(i>=position)
  	 {
  	 	 A[i+1]=A[i];
  	 	 i--;
  	 }
  	 A[position]=key;//insert key at the position index
  }
}


/* eof */

/**
 *  \file mergesort.cc
 *
 *  \brief Implement your mergesort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

void merge(keytype*A, keytype* left_arr,keytype * right_arr, int rightsize,int leftsize)
{

	// left:  index of left subarray (left_arr).
	// right: index of right subarray (right_arr).
	// i:     index of merged array (A).
	int left=0,right=0,i=0;
	//for(left,right;left<leftsize&&right<rightsize;left++,right++)//iterate through subarrays
	for(left,right; left<leftsize && right<rightsize;) //iterate through subarrays
	{
		//if the element in left subarray < than element in right subarray
		//add it to merged array and increment the index to merged array;
		//otherwise the element in right subarray is smaller and add that 
		//to the merged array (A) and increment its index.
		if(left_arr[left] < right_arr[right]) 
		{
			A[i]=left_arr[left];
			left++;//increment left subarrayindex
			i++;
		}
		else
		{
			A[i]=right_arr[right];
			right++;//increment right subarray index
			i++;
		}
	}

	while(left < leftsize)
	{ 
		A[i++] = left_arr[left++];
	}
	while(right < rightsize)
	{

		A[i++] = right_arr[right++];
	}
}


void mySort (int N, keytype* A)
{

	int mid;
	keytype * left_arr, * right_arr;
	if(N==1)
		return; //base case
	mid=N/2;
	left_arr=newKeys(mid);//elements from 0 to mid-1;
	right_arr=newKeys(N-mid);//elements from mid to n-1;

	for(int i=0;i<mid;i++)
		left_arr[i]=A[i];//create left arr

	for(int i=mid;i<N;i++)
		right_arr[i-mid]=A[i];//create right arr

	mySort(mid,left_arr);//sort left array
	mySort(N-mid,right_arr);//sort right array
	merge(A,left_arr,right_arr,N-mid,mid);

}


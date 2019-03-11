
// QuickSort

#include <stdio.h>
#define DOOR 4
typedef int ElemType;

void QuickSort(ElemType *arr, int l, int r)
{
	int i=l+1, j=r;
	ElemType t;
	
	if( r-l+1<=DOOR )
	{
		for(i=l; i<=r; i++)
			for(j=i+1; j<=r; j++)
				if( arr[i]>arr[j] )
				{ t=arr[i]; arr[i]=arr[j]; arr[j]=t; }
	}
	else 
	{
		while( i<=j )
		{
			if( arr[i]>arr[l] )
			{ t=arr[i]; arr[i]=arr[j]; arr[j]=t; j--; }
			else 
			{ i++; }
		}
		t=arr[i-1]; arr[i-1]=arr[l]; arr[l]=t; 
		QuickSort(arr, l, i-1-1);
		QuickSort(arr, j+1, r);
	}
}

void sort(ElemType *arr, int len)
{
	QuickSort(arr, 0, len-1);
}

int main()
{
	int i, n=10;
	int A[10]={2, 5, 7, 3, 0, 4, 9, 1, 6, 8};
	
	for(i=0; i<n; i++)
		printf("%d ", A[i]);
	printf("\n");
	
	sort(A, n);
	for(i=0; i<n; i++)
		printf("%d ", A[i]);
	printf("\n");
	
	return 0;
}


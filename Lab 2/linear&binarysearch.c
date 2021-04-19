#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearsearch(int A[],int x,int index,int n)
{
	if(index >= n)
    {
        return -1;
    }
    else if(A[index] == x)
    {
        return index;
    }
    else
    {
        return linearsearch(A,x,index+1,n);
    }
    return index;
}

void bubblesort(int A[],int n)
{
	int i,j,temp;
	
	for (i = 0 ; i < n ; i++) 
	{     
		for (j = i+1 ; j < n ; j++) 
		{     
           if(A[i] > A[j]) 
           {    
               temp = A[i];    
               A[i] = A[j];    
               A[j] = temp;    
           }     
        }
    }
    //print sorted array
    printf("\n\nBubble Sorted Array:"); 
    for(i=0;i<n;i++)
	{
		printf("%d ",A[i]); 
	}
    
}

int binarysearch(int A[], int lo, int hi, int x)
{
	int mid;
	
    if (lo > hi)
    {
        return -1;
    }
    mid = (lo + hi) / 2;
    if (A[mid] == x)
    {
		return mid;
    }
    else if (A[mid] > x)
    {
       return binarysearch(A, lo, mid - 1, x);
    }
    else if (A[mid] < x)
    {
       return binarysearch(A, mid + 1, hi, x);
    }
    return -1;
}

void display(int y)
{
	if(y == -1)
	{
			printf("\nElement is not present in the given array");
	}
	printf("\n\nElement is present at index %d",y);	
}

int main()
{
	int A[2000],x,y,n,i;
	clock_t start,end;
	double time_taken;
	
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		A[i]=rand()%200; 
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]); 
	}
	
	printf("\n\nEnter the element to be searched in the array: ");
	scanf("%d",&x);
	
	//linear search
	start = clock();
	y = linearsearch(A,x,0,n);
	end = clock();
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
	display(y);
	printf("\nTime taken for linear search: %lf s",time_taken);
	
	//binary search
	start = clock();
	bubblesort(A,n);
	y = binarysearch(A,0,n,x);
	end = clock();
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
	display(y);
	printf("\nTime taken for binary search: %lf s",time_taken);
	
	return 0;
}

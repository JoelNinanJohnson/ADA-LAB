#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swap function
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

//Selection Sort
void selectionsort(int A[],int n)
{
	int i, j, min; 
  
    for(i = 0; i < n-1; i++) 
    { 
        min = i; 
        for(j = i+1; j < n; j++)
        { 
			if(A[j] < A[min]) 
            {
				min = j; 
			}
		}
        swap(&A[min],&A[i]); 
    } 
}

//Bubble Sort
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
}

//display array
void display(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]); 
	}	
}

int main()
{
	int A[2000],n,i;
	clock_t start,end;
	double time_taken;
	
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		A[i]=rand()%200; 
	}
	printf("\n\nUnsorted Array:\n");
	display(A,n);
	
	//Selection Sort
	start = clock();
	selectionsort(A,n);
	end = clock();
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nArray after Selection Sort:\n");
	display(A,n);
	printf("\n\nTime taken for Selection Sort: %lf s",time_taken);
	
	//Bubble Sort
	start = clock();
	bubblesort(A,n);
	end = clock();
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nArray after Bubble Sort:\n");
	display(A,n);;
	printf("\n\nTime taken for Bubble Sort: %lf s",time_taken);
	
	return 0;
}


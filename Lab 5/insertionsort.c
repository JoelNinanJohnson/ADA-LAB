#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//insertion sort function
void insertionsort(int A[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
		key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
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
	
	start = clock();
	insertionsort(A,n);
	end = clock();
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nArray after Insertion Sort:\n");
	display(A,n);
	printf("\n\nTime taken for Insertion Sort: %lf s",time_taken);
	
	return 0;
}


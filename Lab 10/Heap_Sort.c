#include <stdio.h> 
#include <time.h>
int temp;  
 
void delay()
{
	for (int i=0;i<10000000;i++){
		//delay
	}
} 

void heapify(int arr[], int size, int i)
 {  
	int largest = i;    
	int left = 2 * i + 1;    
	int right = 2 * i + 2;    
	  
	if (left < size && arr[left] >arr[largest]){
		largest = left;  
	}
	if (right < size && arr[right] > arr[largest]){  
		largest = right;  
	}
	if (largest != i)  {  
		temp = arr[i];  
		arr[i]= arr[largest];   
		arr[largest] = temp;  
	heapify(arr, size, largest);  
	}  
}  
  
void heapSort(int arr[], int size)  
{  
	int i;  
	for (i = size / 2 - 1; i >= 0; i--){
		heapify(arr, size, i);  
	}
	for (i=size-1; i>=0; i--)  {  
		temp = arr[0];  
		arr[0]= arr[i];   
		arr[i] = temp;  
	heapify(arr, i, 0);  
	}  
	delay();
}  
  
 //display array
void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]); 
	}	
}

int main()
{
	int i, n, arr[2000];
	int rand(void);
	clock_t start,end;
    double timetaken;
    
	printf("Enter the number of elements :\t");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		arr[i]=rand() % 2000 + 1;
	}
	printf("\n\nUnsorted Array:\n");
	display(arr,n);
	
	start=clock();
	heapSort(arr, n);
	end=clock();
	timetaken=((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("\n\nArray after Heap Sort:\n");
	display(arr,n);
		
    printf("\n\nTime taken for Heap Sort: %lf s",timetaken);
	return 0;
}

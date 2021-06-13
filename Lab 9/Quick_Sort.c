#include <stdio.h>
#include <time.h>

void delay(){
	for (int i=0;i<10000000;i++){
		//delay
	}
}

void quicksort(int arr[2000],int f,int l){
	int i, j, pivot, temp;
	if(f<l){
		pivot=f;
		i=f;
		j=l;
		while(i<j){
			while(arr[i]<=arr[pivot]&&i<l){
				i++;
			}
			while(arr[j]>arr[pivot]){
				j--;
			}
			if(i<j){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=temp;
		
		quicksort(arr,f,j-1);
		quicksort(arr,j+1,l);
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

int main(){
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
	quicksort(arr,0,n-1);
	end=clock();
	timetaken=((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("\n\nArray after Quick Sort:\n");
	display(arr,n);
		
    printf("\n\nTime taken for Quick Sort: %lf s",timetaken);
	return 0;
}

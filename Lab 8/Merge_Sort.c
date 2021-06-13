#include <stdio.h>
#include <time.h>
 
void delay(){
	for (int i=0;i<10000000;i++){
		//delay
	}
} 

void merge(int a[],int low1,int high1,int low2,int high2)
{
	int temp[1000];	
	int i,j,k;
	i=low1;	
	j=low2;	
	k=0;
	
	while(i<=high1 && j<=high2)	
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=high1)	
		temp[k++]=a[i++];
		
	while(j<=high2)	
		temp[k++]=a[j++];
		
	
	for(i=low1,j=0;i<=high2;i++,j++)
		a[i]=temp[j];
}

 
void sort(int a[],int low,int high)
{
	int mid;
		
	if(low<high)
	{
		mid=(low+high)/2;
		sort(a,low,mid);		
		sort(a,mid+1,high);	
		merge(a,low,mid,mid+1,high);
	}
	delay();
}

//display array
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]); 
	}	
}

int main()
{
	int a[1000],n,i;
	int rand(void);
	clock_t start,end;
    double timetaken;
    
	printf("Enter no of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		a[i]=rand() % 2000 + 1;
	printf("\n\nUnsorted Array:\n");
	display(a,n);

	start = clock();	
	sort(a,0,n-1);
	end = clock();
	printf("\nSorted array is :");
	timetaken=((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("\n\nArray after Merge Sort:\n");
	display(a,n);
		
    printf("\n\nTime taken for Merge Sort: %lf s",timetaken);
		
	return 0;
}

 


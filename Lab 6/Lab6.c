#include <stdio.h>
 
int main()
{
	int i,j,k,n,A[10][10],indeg[10],flag[10],count=0;
 
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
 
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
 
	for(i=0;i<n;i++)
	{
        indeg[i] = 0;
        flag[i] = 0;
    }
 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            indeg[i] = indeg[i] + A[j][i];
		}
	}	

    printf("\nThe topological order is:");
 
    while(count<n)
    {
        for(k=0;k<n;k++)
        {
            if((indeg[k] == 0) && (flag[k] == 0))
            {
                printf("%d ",(k+1));
                flag[k] = 1;
            }
            for(i=0;i<n;i++)
            {
                if(A[i][k] == 1){ indeg[k]--; }
            }
        }
        count++;
    }
 
    return 0;
}

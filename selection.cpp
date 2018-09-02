#include<stdio.h>

void selection(int ar[],int n)
{
	int min;
    for(int i=0;i<n-1;i++)
    {
    	min=i;
        for(int j=i+1;j<n;j++)
        {
            if(ar[j]<ar[min])
            {
                min=j;
            }
        }
        
        if(ar[min]<ar[i])
        {
        	int temp = ar[i];
        	ar[i] = ar[min];
        	ar[min] = temp;
		}
    }
    
}

main()
{
    int n;
    printf("\nEnter the total number of elements to be sorted   ");
    scanf("%d",&n);
    printf("Enter the elements to be sorted\n");
    int ar[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    selection(ar,n);
    printf("\nElements after sorting\n");
    for(int i=0;i<n;i++)
        printf("%d ",ar[i]);
}

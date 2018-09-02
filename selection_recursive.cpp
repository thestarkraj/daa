#include<stdio.h>
void selectionsort(int ar[], int i,int size)
{
    if (i>=size-1)
        return;
    int min=i;
    for (int j=i+1;j<size;j++ )
    {
        if (ar[j]<ar[min])
            min=j;
    }
    int temp = ar[i];
    ar[i] = ar[min];
    ar[min]=temp;
    selectionsort(ar,i+1,size);
}

main()
{
	int ar[20],n;
	printf("Enter the total number of elements to be sorted	");
	scanf("%d",&n);
	printf("\nEnter the elements for sorting\n");
	for(int i=0;i<n;i++)
		scanf("%d",&ar[i]);
	selectionsort(ar,0,n);
	printf("\nSorted elements are\n");
		for(int i=0;i<n;i++)
			printf("%d ",ar[i]);
}

#include<stdio.h>

void insertionsort(int ar[], int i,int size)
{
	if(i>size)
		return;
	int beg=ar[i];
	int j=i-1;
	while((j>=0)&&(ar[j]>beg))
	{
		ar[j+1]=ar[j];
		j--;
	}

	ar[j+1]=beg;
	insertionsort(ar,i+1,size);
}

main()
{
	int n;
	printf("Enter the total number of elements to be sorted	");
	scanf("%d",&n);
	int ar[n];
	printf("\nEnter the elements for sorting\n");
	for(int i=0;i<n;i++)
		scanf("%d",&ar[i]);
	insertionsort(ar,1,n);
	printf("\nSorted elements are\n");
		for(int i=0;i<n;i++)
			printf("%d ",ar[i]);
}

#include<stdio.h>

void quicksort(int ar[],int start, int end)
{
	if(start>end)
		return;
	int i=start-1;
	int pindex=end;
	for(int j=start;j<end;j++)
	{
		if(ar[j]<ar[pindex])
		{
			i=i+1;
			int temp=ar[j];
			ar[j]=ar[i];
			ar[i]=temp;
		}
	}
	i=i+1;
	int flag=ar[i];
	ar[i]=ar[end];
	ar[end]=flag;
	quicksort(ar,start,i-1);
	quicksort(ar,i+1,end);
}

void print(int ar[],int n)
{
	printf("\nSorted elements are\n");
	for(int i=0;i<n;i++)
		printf("%d ",ar[i]);
}
main()
{
	int n;
	printf("\nEnter the no of elements for sorting	");
	scanf("%d",&n);
	int ar[n];
	printf("\nEnter te elements for sorting\n");
	for(int i=0;i<n;i++)
		scanf("%d",&ar[i]);
	quicksort(ar,0,n-1);
	print(ar,n);
	
	
}

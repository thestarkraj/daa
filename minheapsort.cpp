#include<stdio.h>

void swap(int ar[],int start,int end)
{
	printf("%d ",ar[start]);
	int temp=ar[start];
	ar[start]=ar[end];
	ar[end]=temp;
	
}

void minheap(int ar[],int n)
{
	if(n<1)
		return;
	for(int i=1;i<=n;i++)
	{
		while((ar[i]<ar[i/2])&&i!=1)
		{
			int temp=ar[i];
			ar[i]=ar[i/2];
			ar[i/2]=temp;
			i=i/2;
		}
	}
	swap(ar,1,n);
	minheap(ar,n-1);
	
}


main()
{
	int n;
	printf("\nHow many numbers you want to sort	");
	scanf("%d",&n);
	int ar[n+1];
	printf("\nEnter the numbers in heap\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);
	}
	printf("\nNumbers after heap sort\n");
	minheap(ar,n);
}

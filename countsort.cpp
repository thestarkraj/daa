#include<stdio.h>

void print(int arr[],int n)
{
	printf("\nElements after sorting are\n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
}

void countsort(int ar[],int n)
{
	int b[10]={0};
	int c[n];
	for(int i=0;i<n;i++)
		b[ar[i]]++;
	for(int i=1;i<10;i++)
		b[i]=b[i]+b[i-1];
	for(int i=0;i<n;i++)
	{
		int pos = b[ar[i]];
		c[pos-1]=ar[i];
		b[ar[i]]--;
	}
	print(c,n);
}

main()
{
	int size;
	printf("\nEnter how many elements you want to sort	");
	scanf("%d",&size);
	int ar[size];
	printf("\nEnter elements\n");
	for(int i=0;i<size;i++)
		scanf("%d",&ar[i]);
	countsort(ar,size);
}

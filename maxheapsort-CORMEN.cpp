#include<stdio.h>

void swap(int ar[],int value1,int value2)
{
	int temp=ar[value1];
	ar[value1]=ar[value2];
	ar[value2]=temp;
}

void maxheapify(int ar[],int index,int n)
{
	int highindex=index;
	if((2*index<=n)&&ar[2*index]>ar[highindex])
		highindex=2*index;
	if((2*index+1<=n)&&ar[2*index+1]>ar[highindex])
		highindex=2*index+1;
	if(highindex!=index)
	{
		swap(ar,index,highindex);
		maxheapify(ar,highindex,n);
	}
}

void buildmaxheap(int ar[],int n)
{
	if(n<1)
		return ;
	for(int i=n/2;i>=1;i--)
		maxheapify(ar,i,n);
	swap(ar,1,n);
	buildmaxheap(ar,n-1);
}

void print(int ar[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ar[i]);
	}
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
	buildmaxheap(ar,n);
	print(ar,n);
}

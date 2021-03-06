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

void print(int ar[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ar[i]);
	}
}

int Extractmax(int ar[],int n)
{
	int max=ar[1];
	swap(ar,1,n);
	n=n-1;
	maxheapify(ar,1,n);
	return max;
	
}

void increasepriority(int ar[],int index,int key)
{
	if(ar[index]>=key)
		return;
	while(index>1&&ar[index]>ar[index/2])
	{
		swap(ar,index,index/2);
		index=index/2;
	}
}

void insertnew(int ar[],int element,int n)
{
	n=n+1;
	ar[n]=-9999;
	increasepriority(ar,n,element);
}

main()
{
	int n,choice,index,priority,value;
	char ans='y';
	printf("\nHow many numbers you want to sort	");
	scanf("%d",&n);
	int ar[n+1];
	printf("\nEnter the numbers in heap\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);
	}
	
	do
	{
		printf("\n\n1.Extract the max element from heap\n2.Increase Priority\n3.Insert new element in queue\n\nEnter your choice	");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : value=Extractmax(ar,n);
					 printf("\nMax value is %d ",value);
					 	break;
			case 2 : printf("Enter the index of priority and new priority\n");
					 scanf("%d %d",&index,&priority); 
					 increasepriority(ar,index,priority);
					 print(ar,n);
					 	break;
			case 3 : printf("\nEnter the new element for insertion	");
					 int element;
					 scanf("%d",&element);
					 insertnew(ar,element,n);
					 print(ar,n);
						break;
			case 4 : printf("\nWRONG CHOICE\n");
						break;
		}
		printf("\nDo you want to continue	");
		scanf("\n%c",&ans);
	}while(ans=='y');
	
}



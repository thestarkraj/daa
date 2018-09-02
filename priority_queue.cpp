#include<stdio.h>

int top1=-1,top2=-1;

void push(int stack[],int element,int &top)
{
	stack[top]=element;
}

int prioritycheck(int stack[],int top1)
{
	int min=top1;
	while(top1>=0)
	{
		if(stack[top1]<=stack[min])
			min=top1;
		top1=top1-1;
	}
	return min;
	
}

void pop(int stack1[],int stack2[],int &top1,int &top2)
{
	if(top1==-1)
	{
		printf("\nUNDERFLOW\n");
		return ;
	}
	int priority=prioritycheck(stack1,top1);
	while(top1>=priority)
	{
		top2=top2+1;
		push(stack2,stack1[top1],top2);
		top1=top1-1;
	}
	printf("%d ",stack2[top2]);
	top2=top2-1;
	while(top2>=0)
	{
		top1=top1+1;
		push(stack1,stack2[top2],top1);
		top2=top2-1;
	}
}

main()
{
	int n,element;
	printf("\nEnter how many numbers you want to insert	");
	scanf("%d",&n);
	int stack1[n],stack2[n];
	printf("\nEnter the priority\n");
	for(int i=0;i<n;i++)
	{
		top1=top1+1;
		scanf("%d",&element);
		push(stack1,element,top1);
	}
	printf("\nElements are popped in this priority\n");
	for(int i=0;i<n;i++)
	{
		pop(stack1,stack2,top1,top2);
	}
}

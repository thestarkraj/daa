#include<stdio.h>
#include<string.h>
#include<ctype.h>
const int size=20;

int pop(char stack[],int &top)
{
	return stack[top--];
}

void push(char x,char stack[],int &top)
{
	if(top==size-1)
	{
		printf("\nOVERFLOW...");
		return ;
	}
	stack[++top]=x;
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

void conversion(char e[],char stack[],int &top)
{
	char x;
	while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e,stack,top);
        else if(*e == ')')
        {
            while((x = pop(stack,top)) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop(stack,top));
            push(*e,stack,top);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop(stack,top));
    }
}



int main()
{
	char stack[size],ar[size];
	int top=-1;
	printf("\nEnter the string	");
	scanf("%s",ar);
	int l=strlen(ar);
	for(int i=0;i<l;i++)
	{
		if(ar[i]=='(')
			push(ar[i],stack,top);
		else if(ar[i]==')')
			pop(stack,top);
	}
	if(top!=-1)
	{
		printf("\nString is Not parenthesized");
		return 0;
	}
	conversion(ar,stack,top);
		
}

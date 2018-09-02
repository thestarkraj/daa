#include<stdio.h>
#include<ctype.h>
#include<string.h>

void print(char ar[],int k)
{
	for(int i=0;i<k;i++)
		printf("%c",ar[i]);
}
void push(char x,char stack[],int &top)
{
    stack[++top] = x;
}
 
char pop(char stack[],int &top)
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
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
	char ar[20];
	int k=0;
	printf("\nExpression after converting from Infix to Postfix is \n");
	char x;
	while(*e != '\0')
    {
        if(isalnum(*e))
    	{
    		ar[k]=*e;
    		k=k+1;
		}
        else if(*e == '(')
            push(*e,stack,top);
        else if(*e == ')')
        {
            while((x = pop(stack,top)) != '(')
            {
            	ar[k]=x;
            	k=k+1;
			}
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            {
            	int ans=pop(stack,top);
            	ar[k]=ans;
            	k++;
			}
            push(*e,stack,top);
        }
        e++;
    }
    if(top!=0)
    {
    	printf("\nINCORRECT EXPRESSION\n");
    	return;
	}
    while(top != -1)
    {
        int ans=pop(stack,top);
           	ar[k]=ans;
           	k++;
    }
    print(ar,k);
}
 
main()
{
	int top=-1;
    char exp[20],stack[20];
    printf("Enter the expression in Infix:: ");
    scanf("%s",exp);
    conversion(exp,stack,top);
    
}

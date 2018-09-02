#include<stdio.h>
#include<ctype.h>
#include<string.h>
const int size=20;
int stack[size];
int top=-1;

int push(int x)
{
	stack[++top]=x;
	return 0;
}

int pop()
{
	return(stack[top--]);
}

int postfixeval(char ar[],int size)
{
		for(int i=0;i<size;i++)
	{
		if(isdigit(ar[i]))
			push(ar[i]-'0');
		else
			{
				int n1=pop();
				int n2=pop();
				switch(ar[i])
				{
					case '+':push(n1+n2);
								break;
					case '-':push(n2-n1);
								break;
					case '*':push(n2*n1);
								break;
					case '/':push(n2/n1);
								break;
					default : printf("\nError!!");
								break;
				}
			}
	}
	return stack[top];
}

int main()
{
	char ar[size];
	printf("Enter the postfix ");
	scanf("%s",ar);
	int l=strlen(ar);
	float ans = postfixeval(ar,l);
	
	printf("\n\nThe evaluation of postfix expression %s is %f",ar,ans);
}

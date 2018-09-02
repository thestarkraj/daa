#include<stdio.h>
void inssort(int ar[],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		int temp=ar[i];
		j=i-1;
		while(temp<ar[j])
		{
			ar[j+1]=ar[j];
			j--;
		}
		ar[j+1]=temp;
	}
	printf("The elements after sorting is\n\n");
	for(i=0;i<n;i++)
		printf("%d ",ar[i]);

}

main()
{
	int n;
	printf("\nEnter the total number of elements to be sorted  ");
	scanf("%d",&n);
	int ar[n];
	printf("Enter the elements to be sorted\n");
	for(int i=0;i<n;i++)
		scanf("%d",&ar[i]);
	inssort(ar,n);

}

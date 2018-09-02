#include<stdio.h>

int binarysearch(int ar[],int start,int end,int key)
{
	if(end<=start)
		return (ar[start]>key)? start:start+1;
	int mid=(start+end)/2;
	if(ar[mid]==key)
		return mid+1;
	if(ar[mid]>key)
		return binarysearch(ar,start,mid-1,key);
	else
		return binarysearch(ar,mid+1,end,key);
}

void inssort(int ar[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		int temp=ar[i];
		j=i-1;
		int pos = binarysearch(ar,0,j,temp);
		while(j>=pos)
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

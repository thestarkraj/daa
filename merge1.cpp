#include<stdio.h>

void merge(int a[],int l,int m,int h)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=h-m;
    int ar1[n1],ar2[n2];
    for(i=0;i<n1;i++)
    {
    	ar1[i]=a[l+i];
	}
	for(j=0;j<n2;j++)
		ar2[j]=a[m+1+j];
		
	ar1[i]=9999;
	ar2[j]=9999;
	i=0;j=0;
	for(k=l;k<=h;k++)
	{
		if(ar1[i]<=ar2[j])
			a[k]=ar1[i++];
		else
			a[k]=ar2[j++];
	}
}
 
void mergesort(int a[],int start,int end)
{
    int mid;
        
    if(start<end)
    {
        mid=(start+end)/2;
        mergesort(a,start,mid);  
        mergesort(a,mid+1,end);  
        merge(a,start,mid,end);    
    }
}
 
int main()
{
    int n,i;
    printf("Enter no of elements for sorting:	");
    scanf("%d",&n);
    int ar[n];
    
    printf("Enter the elements for sorting :\n");
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        
    mergesort(a,0,n-1);
    
    printf("\nSorted elements are :");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
        
    return 0;
}
 

 


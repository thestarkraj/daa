#include<stdio.h>
void merge(int arr[],int start,int end,int mid)
{
    
    int i =start;
    int j=mid+1;
    int k=start;
    int temp[end-start];
    while(i<=mid && j<=end)
    {
        if(arr[i]>=arr[j])
        {
            temp[k]=arr[j];
            j=j+1;
        }
        else{
            temp[k]=arr[i];
            i=i+1;
        }
        k=k+1;
        
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int i=start;i<=end;i++)
    {
        arr[i]=temp[i];
    }
}
void mergesort2(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid =(start+end)/2;
        mergesort2(arr,start,mid);
        mergesort2(arr,mid+1,end);
        merge(arr,start,end,mid);
    }
}
void print(int arr[],int n)
{
    printf("the values of list after passing through merge sort are \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n;
    printf("enter the number of elements you want to be in you list \n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values of list one by one \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    int start =0;
    int end =n-1;
    mergesort2(arr,start,end);
    print(arr,n);
}

#include<stdio.h>

void insertion(int ar[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[j]<ar[i])
            {
                int temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    printf("\nArray after sorting\n");
    for(int i=0;i<n;i++)
        printf("%d ",ar[i]);
}

main()
{
    int n;
    printf("\nEnter the size of array   ");
    scanf("%d",&n);
    printf("Enter the array\n");
    int ar[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    insertion(n);
}

#include<stdio.h>
int partition(int ar[],int low,int high)
{
   int i,j,pivot,temp;

   if(low<high)
   {
      pivot=low;
      i=low;
      j=high;

      while(i<j)
	  {
         while(ar[i]<ar[pivot]&&i<high)
            i++;
         while(ar[j]>ar[pivot])
            j--;
         if(i<j)
		 {
            temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
         }
      }

      temp=ar[pivot];
      ar[pivot]=ar[j];
      ar[j]=temp;
   return j;   

   }
}

quicksort(int ar[],int low,int high)
{
	int pivotloc;
	if(low>high)
		return 0;
    pivotloc=partition(ar,low,high);
	quicksort(ar,low,pivotloc-1);
    quicksort(ar,pivotloc+1,high);
}


int main()
{
   int i,n;

   printf("How much numbers you want to sort	");
   scanf("%d",&n);
	int ar[n];
   printf("\nEnter the numbers for sorting\n");
   for(i=0;i<n;i++)
      scanf("%d",&ar[i]);

   quicksort(ar,0,n-1);

   printf("\nSorted elements are\n");
   for(i=0;i<n;i++)
      printf(" %d",ar[i]);

   return 0;
}

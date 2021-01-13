#include<stdio.h>
#include<stdlib.h>
int main()
 {
    int *arr,i,n,max,rep,occ=0;
    printf("Enter the size of the dynamic array");
     scanf("%d",&n);
    arr=(int*)calloc(n,sizeof(int));
     if (arr== NULL) {
        printf("Error!!! memory not allocated.");
        exit(0);
    }
     for(i=0;i<n;i++)
     {
         scanf("%d",arr+i);
      }
    max=arr[0];
   for(i=0;i<=n;i++)
   {
       if(max<*(arr+i))
         {
           printf("Test");
          occ=0;
         max=*(arr+i);
         rep=max;
         }
       if(rep==*(arr+i))
       {
        occ++;
        printf("c");
       }
    }
   printf(" The largest number in the array is %d and it occured %d times in the array ",max,occ);
 return 0;
}
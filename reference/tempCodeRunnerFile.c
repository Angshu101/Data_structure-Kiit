#include<stdio.h>
#include<stdlib.h>
int main()
 {
    int *arr,i,n,max,rep,occ;
    printf("Enter the size of the dynamic array");
     scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
     for(i=0;i<n;i++)
     {
         scanf("%d",arr+i);
      }
    max=*(arr+i);
   for(i=0;i<n;i++)
   {
       if(max<*(arr+i))
         {
          occ=0;
         max=*(arr+i);
         rep=max;
         }
       if(rep==*(arr+i))
        occ++;
    }
   printf(" The largest number in the array is %d and it occured %d times in the array ",max,occ);
 return 0;
}
       
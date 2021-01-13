#include<stdio.h>
#include<stdlib.h>
int main()
 {
    int *arr,i,n,count=0;
    printf("Enter the size of the dynamic array");
     scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
     for(i=0;i<n;i++)
     {
         scanf("%d",arr+i);
      }
    for(i=0;i<n;i++)
     {
         if(*(arr+i)==0)
          count++;
     }
    for(i=0;i<count;i++)
      *(arr+i)=0;
    for(i=count;i<n;i++)
       *(arr+i)=1;
    for(i=0;i<n;i++)
      printf("%d ",*(arr+i));
  return 0;
}
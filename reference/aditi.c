#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *arr,j,next=0,i,n;
  printf("Enter the Number of elements in the array");
  scanf("%d",&n);
  arr=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
   {
     scanf("%d",arr+i);
   }
  for(i=0;i<n;i++)
  {
     next=-1;
     int b=(*arr+i);
    for(j=i+1;j<n;j++)
      {
          if(*(arr+i)<*(arr+j))
           {
              next=*(arr+j);
               break;
            }
      }
        printf(" %d %d \n",b,next);
  }
  return 0;
}



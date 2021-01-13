#include<stdio.h>
#include<stdlib.h>
int main()
 {
    int *arr,*brr,i,n,k;
    printf("Enter the size of the dynamic array");
     scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    brr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
     {
         scanf("%d",arr+i);
      }
    for(i=0;i<n;i++)
    {
        if(i==0)
       *(brr+i)=*(arr+(n-1)) * *(arr+(i+1));
       else if(i==(n-1))
         *(brr+i)=*(arr+(i-1)) * *(arr+0);
         else
       *(brr+i)=*(arr+(i-1)) * *(arr+(i+1));
     }
   for(i=0;i<n;i++)
    {
       printf("%d ",*(brr+i));
    }
return 0;
}

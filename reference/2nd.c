#include<stdio.h>
#include<stdlib.h>
int main()
 {
    int *arr,large=0,small=0,smax=0,smin=0,i,n;
    printf("Enter the size of the dynamic array");
     scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
     {
         scanf("%d",arr+i);
      }
     large=0;
     small=*(arr+0);
     smax=0;
     smin=*(arr+0);
    for(i=0;i<n;i++)
    {
       if(*(arr+i)>large)
         large=*(arr+i);
       if(*(arr+i)<small)
          small=*(arr+i);
     }
     for(i=0;i<n;i++)
     {
        if((*(arr+i)>smax)&&(*(arr+i)!=large))
             smax=*(arr+i);
         if((*(arr+i)<smin)&&(*(arr+i)!=small))
             smin=*(arr+i);
     }
    printf(" The Second largest element in the array is:- %d \n The Second minimal element array is :- %d ",smax,smin);
    return 0;
}

    

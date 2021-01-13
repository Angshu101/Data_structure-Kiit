#include <stdio.h>
#include<stdlib.h>
int main()
{
    int *arr,n,x,i,count=0,a,b,next,j;
    printf("enter the number of elements:");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    for(i=0;i<n;i++)
    {
        next=-1;
        for(j=i+1;j<n;j++)
        {
            if(*(arr+i)<*(arr+j))
            {
                next=*(arr+j);
                break;
            }
        }
        printf("%d %d \n",*(arr+i),next);
    }
    return 0;
    
}
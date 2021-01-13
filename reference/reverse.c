#include<stdio.h>
void main(){
    int n;
    printf("Enter the number of elements in an array");
    scanf("%d",&n);

    int a[n],b[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(int c=n-1,d=0;c>=0;c--,d++){
        b[d]=a[c];
    }
    printf("The reverse is :-");
    for(int c=0;c<n;c++)
    printf("%d  ",b[c]);


}
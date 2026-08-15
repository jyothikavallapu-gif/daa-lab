#include<stdio.h>
int main()
{
    int n,k,temp;
    printf("enter the no.of elements in the array:\n");
    scanf("%d",&n);
    int a[100];
    printf("enterthe elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the value of k:\n");
    scanf("%d",&k);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
            
        }
    }
    printf("the %dth smallest element in the array is %d\n",k,a[k-1]);
    return 0;

}
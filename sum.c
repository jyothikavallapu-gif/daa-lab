#include<stdio.h>
int main()
{
    int x,n;
    printf("enter the value:\n");
    scanf("%d",&x);
    printf("enter the n value:\n");
    scanf("%d",&n);
    int sum=0,term=1;
    for(int i=0;i<=n;i++)
    {
        sum=sum+term;
        term=term*x;
    }
    printf("the sum is: %d\n",sum);
    return 0;

}
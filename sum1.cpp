#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int r,n;
    cout<<"enter r value:\n";
    cin>>r;
    cout<<"enter n value:\n";
    cin>>n;
    int sum= (pow(r,n+1)-1)/(r-1);
    cout<<"sum is:"<<sum<<endl;
    return 0;
}
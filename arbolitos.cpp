#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b,n;
    cin>>a>>b;
    n=a-b+1;
    if((((a+n)*(a-n+1))/2)%2==0)
        cout<<"Si se pudo";
    else
        cout<<"No";
}

#include<bits/stdc++.h>
#define INI cin.tie(0)->sync_with_stdio();
#define fore(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
void solve()
{
    int n;cin>>n;
    vector<int>vec(n);
    fore(i,0,n-1)cin>>vec[i];
    int bus;cin>>bus;
    int peque=-1,grande=n;
    while(grande-peque>1)
    {
        int mid=(peque+grande)/2;
        if(vec[mid]>=bus)
            grande=mid;
        else
            peque=mid;
    }
    if(grande<n&&vec[grande]==bus)
         cout<<"Si";
    else
        cout<<"Nel";
}
main()
{
    INI solve();
}


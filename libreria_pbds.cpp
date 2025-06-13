#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INI cin.tie(0)->sync_with_stdio(0);
#define query int n;cin>>n;while(n--)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define forei(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
void solve()
{
    ordered_set a;
    int n,c;cin>>n;
    fore(i,1,n)
    {
        cin>>c;
        a.insert(c);
    }
    for(auto elem:a)
        cout<<elem<<" ";
    cout<<endl;
    cout<<(a.order_of_key(3));
}
signed main()
{
    INI solve();
}

#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>nodos,vector<bool>&vec,int a)
{
    vec[a]=true;
    for(int v:nodos[a])
        if(!vec[v])
            dfs(nodos,vec,v);
}
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nodos(n);
    while(m--)
    {
        int a,b;cin>>a>>b;
        nodos[a].emplace_back(b),nodos[b].emplace_back(a);
    }
    vector<bool>vec(n,0);
    int cont=0;
    for(int i=0;i<n;i++)
    {
        if(!vec[i])
        {
            dfs(nodos,vec,i);
            cont++;
        }
    }
    cout<<cont;
//    for(int i=0;i<n;i++)
//    {
//        cout<<i<<":";
//        for(int v:nodos[i])
//            cout<<v<<" ";
//        cout<<endl;
//    }
}

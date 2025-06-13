#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>>nodos,vector<bool>&vec,int a)
{
    vec[a]=true;
    queue<int>p;
    p.emplace(a);
    while(!p.empty())
    {
        int u=p.front();
        p.pop();
        for(int v:nodos[u])
            if(!vec[v])
            {
                vec[v]=true,p.emplace(v);
            }
    }
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
            bfs(nodos,vec,i);
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

#include<bits/stdc++.h>
#define INI cin.tie(0)->sync_with_stdio(0);
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
struct Segment_tree{
    vector<int>arbol;
    int n;
    void construir(vector<int>& vec,int nodo,int inicio,int fin)
    {
            if(inicio==fin)
                arbol[nodo]=vec[inicio];
            else
            {
                int medio=(inicio+fin)/2;
                construir(vec,2*nodo+1,inicio,medio);
                construir(vec,2*nodo+2,medio+1,fin);
                arbol[nodo]=arbol[2*nodo+1]+arbol[2*nodo+2];
            }
    }
    int query(int nodo,int inicio,int fin,int l,int r)
    {
        if(r<inicio || l>fin) return 0;
        if(l<=inicio && fin<=r) return arbol[nodo];
        int medio =(inicio+fin)/2;
        int left=query(2*nodo+1,inicio,medio,l,r);
        int right=query(2*nodo+2,medio+1,fin,l,r);
        return left+right;
    }
    void update(int nodo,int inicio,int fin,int idx,int valor)
    {
        if(inicio==fin) arbol[nodo]=valor;
        else
        {
            int medio=(inicio+fin)/2;
            if(idx<=medio) update(2*nodo+1,inicio,medio,idx,valor);
            else update(2*nodo+2,medio+1,fin,idx,valor);
            arbol[nodo]=arbol[2*nodo+1]+arbol[2*nodo+2];
        }
    }
    Segment_tree(vector<int>& vec)
    {
        n=vec.size();
        arbol.assign(4*n,0);
        construir(vec,0,0,n-1);
    }
     int query(int l,int r){return query(0,0,n-1,l,r);}
     void update(int idx,int valor){update(0,0,n-1,idx,valor);}
};
void solve()
{
    int c;cin>>c;
    vector<int> vec(c);
    for(int i=0;i<c;cin>>vec[i++]);
    Segment_tree arbol1(vec);
    int a,b;cin>>a>>b;
    cout<<arbol1.query(a,b)<<endl;
}
signed main()
{
    solve();
}

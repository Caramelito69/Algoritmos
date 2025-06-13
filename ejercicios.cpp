#include<bits/stdc++.h>
using namespace std;
void run()
{
    int a;cin>>a;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=a;j++)

        {
            if(i==1 or i==a or j==1 or j==a or i==j or j==a-i+1 )
           {
                cout<<"* ";
           }
           else
          {
           cout<<"  ";
          }
        }
        cout<<'\n';
    }
}
void run1()
{
     int a;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
    for(int j=a;j>=i;j--)
    {
        cout<<char(i+64)<<" ";
    }
    cout<<'\n';
}}
void run2()
{
  int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
                cout<<"  ";
        }
        for(int j=1;j<=i*2-1;j++)
        {
            cout<<char(i+64)<<" ";
        }
        cout<<'\n';
    }
}
void run3()
{
        int n;
    cin>>n;
    int c=n*2-1;
    for(int i=1;i<=n;i++,c=c-2)
    {
        for(int j=i;j>1;j--)
        {
                cout<<"  ";
        }
        for(int k=c;k>=1;k--)
        {
            cout<<"* ";
        }
        cout<<'\n';
    }
}
int main()
{
    run3();
}

#include<bits/stdc++.h>
#define INI cin.tie(0)->sync_with_stdio();
#define fore(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
bool primo(int n)
{
    if (n<=1)
        return false;
    if (n == 2)
        return true;
    if (n%2== 0)
        return false;
    int limite = static_cast<int>(sqrt(n))+1;
    for (int i = 3; i < limite; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    cout<<primo(8);
}


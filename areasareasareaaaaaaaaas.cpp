#include <bits/stdc++.h>
using namespace std;
long long A, B, C;
long long integral(long long x2, long long x1){
    return (x1-x2)*(2*A*(x1*x1+x1*x2+x2*x2)+3*B*(x1+x2)+6*C);
}
long long simplicaficar(long long a,long long b)
{
    if(a%b==0)
        cout<<a/b<<"/1";
    else if(a%2==0)
        cout<<a/2<<"/3";
    else if(a%3==0)
        cout<<a/3<<"/2";
    else cout<<a<<"/"<<6;
}
int main(){
    int c;cin>>c;while(c--)
    {
        long long L, R;
        cin >> A >> B >> C >> L >> R;
        long long ans = 0;
        long long determinante = B*B - 4*A*C;
        if(determinante >= 0){
            long long x1 = (-B - sqrt(determinante)) / (2*A);
            long long x2 = (-B + sqrt(determinante)) / (2*A);
            if(L > x1) x1 = L;
            if(R < x2) x2 = R;

            if(x1==x2){
                ans = abs(integral(L, x1)) + abs(integral(x1, R));
            }
            else if(C < 0){
                ans = abs(integral(L, x1)) + abs(integral(x1, x2)) + abs(integral(x2, R));
            }
            else{
                ans = abs(integral(L, R));
            }
            simplicaficar(ans, 6);
            cout << endl;
        }
        else{
            ans = abs(integral(L, R));
            simplicaficar(ans, 6);
            cout << endl;
        }
    }
}

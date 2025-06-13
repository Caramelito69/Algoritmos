#include <bits/stdc++.h>
using namespace std;
int A, B, C;
int integral(int a, int b){
    return (2*A*b*b*b + 3*B*b*b + 6*C*b)-(2*A*a*a*a + 3*B*a*a + 6*C*a);
}
int simplicaficar(int a,int b)
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
        int L, R;
        cin >> A >> B >> C >> L >> R;
        int ans = 0;
        int determinante = B*B - 4*A*C;
        if(determinante >= 0){
            int x1 = (-B - sqrt(determinante)) / (2*A);
            int x2 = (-B + sqrt(determinante)) / (2*A);
            cout << x1 << ' ' << x2 << '\n';

            if(L < x1 && R > x2){
                ans = abs(integral(L, x1)) + abs(integral(x1, x2)) + abs(integral(x2, R));
                cout << "caso 1\n";
            }
            else if(L < x1){
                ans = abs(integral(L, x1)) + abs(integral(x1, R));
                cout << "caso 2\n";
            }
            else if(R > x2){
                ans = abs(integral(L, x2)) + abs(integral(x2, R));
                cout << "caso 3\n";
            }
            else{
                ans = abs(integral(L, R));
                cout << "caso 4\n";
            }
            simplicaficar(ans, 6);
            cout<<endl;
        }
        else{
            ans = abs(integral(L, R));
            simplicaficar(ans, 6);
            cout << endl;
        }
    }


}

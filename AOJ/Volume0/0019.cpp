#include <iostream>

using namespace std;

typedef long long ll;

ll f(ll x){
    if(x == 1) return 1;
    return x*f(x-1);
}

int main(){
    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}

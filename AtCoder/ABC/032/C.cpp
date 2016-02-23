#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
typedef long long ll;

int main()
{    
    ll N, K;
    cin >> N >> K;
    vector<ll> s(N);
    bool isZero = false;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        if (s[i] == 0) {
            isZero = true;
        }
    }
    
    auto f = [=](){
        if (isZero) {
            cout << N << endl;
            return;
        }
        
        int l = 0, r = 0;
        ll prod = 1;
        int max_length = 0;
        for (; l < N; l++) {
            if (l > r) {
                r = l;
            }
            while (r < N && prod <= K) {
                prod *= s[r];
                r++;
            }
            int len = r - l - (prod <= K ? 0 : 1); 
            max_length = std::max(max_length, len);
            prod /= s[l];
            prod = std::max(prod, 1LL);
        }
        cout << max_length << endl;
    };
    f();
    return 0;
}


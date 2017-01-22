#include <iostream>

using namespace std;

int main()
{
    string n;
    cin >> n;
    
    using ll = long long;
    ll num = 0, p = 0;
    for (int i = (int)n.size() - 1; i >= 0; p++) {
        if (n[i] == 'u') {
            i -= 4;
            num |= (1LL << p);
        } else {
            i -= 3;
        }
    }

    num <<= 1;
    if (num == 0) --p;
    for (int i = p; i >= 0; i--) {
        if (num >> i & 1) {
            cout << "hamu";
        } else {
            cout << "ham";
        }
    }
    cout << endl;
    return 0;
}

#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    string s;
    cin >> s;
    
    int N = s.size();
    ll res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            string t = s;
            swap(t[i], t[j]);
            res = max(res, stoll(t));
        }
    }
    cout << res << endl;
    return 0;
}


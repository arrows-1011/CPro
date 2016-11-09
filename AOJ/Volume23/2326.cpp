#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
constexpr int  MAX_N = (1 << 17);

class BIT {
  public:
    ll bit[MAX_N + 1], n;
  
    BIT()
    {
        n = MAX_N + 1;
        for (int i = 0; i < n; i++) {
            bit[i] = 0;
        }
    }

    ll sum(int i, int P)
    {
        int s = 0;
        while (i > 0) {
            s = (s + bit[i]) % P;
            i -= i & -i;
        }
        return s;
    }
  
    void add(int i, int x, int P)
    {
        while (i <= n) {
            bit[i] = (bit[i] + x) % P;
            i += i & -i;
        }
    }
};

int main()
{
    int A, B, P;
    while (cin >> A >> B >> P, A > 0) {
        vector<string> str_num;
        for (int i = A; i <= B; i++) {
            str_num.emplace_back(to_string(i));
        }

        sort(str_num.begin(), str_num.end());                
        
        BIT b;
        ll res = 0;
        for (const auto& s : str_num) {
            int v = stoi(s) - A + 1;
            res = (res + b.sum(v, P) + 1) % P;
            b.add(v, b.sum(v, P) + 1, P);
        }
        cout << res << endl;
    }        
    return 0;
}

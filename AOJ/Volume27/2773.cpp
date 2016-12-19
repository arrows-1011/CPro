#include <iostream>
#include <vector>

using namespace std;

vector<int> divisor(int x)
{
    vector<int> res;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            res.emplace_back(i);
        }            
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    auto d = divisor(N);
    for (auto& c : d) {
        bool poss = 1;
        for (int i = c; i < N; i += c) {
            bool ok = 1;
            for (int j = 0; j < c; j++) {
                if (S[i + j] != S[i + j - c]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) {
                poss = 0;
                break;
            }
        }
        if (poss) {
            cout << N / c << endl;
            break;
        }
    }    
    return 0;
}

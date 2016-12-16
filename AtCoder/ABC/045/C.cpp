#include <iostream>

using namespace std;

using ll = long long;

ll calc(const string& S, int bit)
{
    int N = S.size();
    string t;
    for (int i = 0; i < N; i++) {
        t += S[i];
        if (i < N - 1 && bit >> i & 1) {
            t += "+";
        }
    }

    ll sum = 0;
    string num;
    for (auto& ch : t) {
        if (ch == '+') {
            sum += stoll(num);
            num.clear();
        } else {
            num += ch;
        }
    }

    if (!num.empty()) {
        sum += stoll(num);
    }
    
    return sum;
}

int main()
{
    string S;
    cin >> S;

    ll sum = 0, N = S.size() - 1;
    for (int i = 0; i < (1 << N); i++) {
        sum += calc(S, i);
    }
    cout << sum << endl;
    return 0;
}

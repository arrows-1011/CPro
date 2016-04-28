#include <bits/stdc++.h>

using namespace std;

int to_num(char c)
{
    if (isdigit(c)) {
        return c - '0';
    } else if (isupper(c)) {
        return c - 'A' + 10;
    } else {
        return c - 'a' + 36;
    }
}

int change(int p, string m)
{
    int res = 0;
    reverse(m.begin(), m.end());
    for (int i = 0; i < (int)m.size(); i++) {
        res += to_num(m[i]) * pow(p, i);
    }
    return res;
}

int main()
{
    int N, p, x = 0;
    string m;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p >> m;
        x ^= change(p, m);
    }
    cout << (x != 0 ? "win" : "lose") << endl;
    return 0;
}

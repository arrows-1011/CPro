#include <bits/stdc++.h>
  
using namespace std;
  
bool check(vector<int> &s, int N)
{
    int p = 0;
    for (int i = 0; i < N; i++) {
        p += s[i];
        if (p < 0) {
            return 0;
        }
    }
    return (p == 0);
}
  
int main()
{
    int N;
    string str;
    cin >> N;
    vector<int> s(N);
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str == "A") {
            s[i] = +1;
        } else {
            s[i] = -1;
        }
    }
    cout << (check(s, N) ? "YES" : "NO") << endl;
    return 0;
}

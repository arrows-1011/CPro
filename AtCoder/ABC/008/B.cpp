#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> mp;
    string S;
    for (int i = 0; i < N; i++) {
        cin >> S;
        mp[S]++;
    }
    int max = -1;
    string name;
    for (auto &x : mp) {
        if (x.second > max) {
            max = x.second;
            name = x.first;
        }
    }
    cout << name << endl;
    return 0;
}

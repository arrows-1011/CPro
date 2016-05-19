#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> mp = {
        {"Monday",    5},
        {"Tuesday",   4},
        {"Wednesday", 3},
        {"Thursday",  2},
        {"Friday",    1},
        {"Saturday",  0},
        {"Sunday",    0},        
    };
    string day;
    cin >> day;
    cout << mp[day] << endl;
    return 0;
}

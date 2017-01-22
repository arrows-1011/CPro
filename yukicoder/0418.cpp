#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (c == 'n') ++cnt;
    }
    cout << cnt << endl;
    return 0;
}

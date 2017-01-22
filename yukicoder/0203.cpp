#include <iostream>

using namespace std;

int main()
{
    string s, t;
    cin >> s; t += s;
    cin >> s; t += s;

    int res = 0, sum = 0;
    for (int i = 0; i < 14; i++) {
        if (t[i] == 'o') {
            sum++;
        } else {
            sum = 0;
        }
        res = max(res, sum);
    }
    cout << res << endl;
    return 0;
}

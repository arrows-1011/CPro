#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int c[3] = {};
    for (char ch : s) {
        if (ch == 't') {
            c[0]++;
        } else if (ch == 'r') {
            c[1]++;
        } else if (ch == 'e') {
            c[2]++;
        }
    }
    cout << min(c[0], min(c[1], c[2] / 2)) << endl;
    return 0;
}

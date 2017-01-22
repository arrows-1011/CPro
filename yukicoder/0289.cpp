#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    for (char ch : s) {
        if ('0' <= ch && ch <= '9') {
            sum += ch - '0';
        }
    }
    cout << sum << endl;
    return 0;
}

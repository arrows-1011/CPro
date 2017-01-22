#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 0;
    for (; ; i++) {
        if (s[i] == 'w') {
            break;
        }
    }
    cout << min(i - 1, (int)s.size() - i) << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        if (s[i] == '>') {
            cout << "<";
        } else {
            cout << ">";
        }
    }
    cout << endl;
    return 0;
}

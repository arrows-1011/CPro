#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (char c : s) {
        if (islower(c)) {
            cout << (char)toupper(c);
        } else {
            cout << (char)tolower(c);
        }
    }
    cout << endl;
    return 0;
}

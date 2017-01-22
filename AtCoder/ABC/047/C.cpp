#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int res = 0;
    char c = s[0];
    for (int i = 1; i < (int)s.size(); i++) {
        if (c != s[i]) ++res;
        c = s[i];
    }
    cout << res << endl;
    return 0;
}

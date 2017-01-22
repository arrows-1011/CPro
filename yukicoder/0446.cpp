#include <iostream>

using namespace std;

bool check(string& s)
{
    if (s.size() > 1 && s[0] == '0') {
        return false;
    }
    for (char ch : s) {
        if (!('0' <= ch && ch <= '9')) {
            return false;
        }
    }    
    return (stoi(s) <= 12345);
}

int main()
{
    string A, B;
    cin >> A >> B;
    cout << (check(A) && check(B) ? "OK" : "NG") << endl;
    return 0;
}

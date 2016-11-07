#include <iostream>

using namespace std;

bool solve(const string& s, const string& t, const string& target)
{
    int N = target.size();
    int a = 0, b = 0, p = 0;    
    for (int i = 0; i < N; i++, p ^= 1) {
        char c = target[i];
        bool found = 0;
        if (p == 0) {
            while (a < N) {
                if (s[a++] == c) {
                    found = 1;
                    break;
                }
            }
        } else {
            while (b < N) {
                if (t[b++] == c) {
                    found = 1;
                    break;
                }
            }
        }
        if (!found) return 0;           
    }
    return 1;
}

int main()
{
    string s, t;
    cin >> s >> t;
    bool res = solve(s, t, s) | solve(t, s, s);
    cout << (res ? "Yes" : "No") << endl;
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

bool check(string& s)
{
    const int size[] = {7, 5, 6, 5};
    const string dic[] = {"remaerd", "maerd", "resare", "esare"};
    int N = s.size();
    if (N < 5) return false;

    reverse(s.begin(), s.end());
    
    for (int i = 0; i < N; ) {
        bool ok = 0;
        for (int j = 0; j < 4; j++) {
            if (N - i - size[j] < 0) continue;
            bool match = 1;
            for (int k = 0; k < size[j]; k++) {
                if (s[i + k] != dic[j][k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                i += size[j];
                ok = 1;
                break;
            }
        }
        if (!ok) return false;
    }

    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << (check(s) ? "YES" : "NO") << endl;
    return 0;
}

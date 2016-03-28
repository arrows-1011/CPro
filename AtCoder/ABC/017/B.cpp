#include <bits/stdc++.h>

using namespace std;

bool is_choku(string X)
{
    int l = X.size();
    if (l == 0) {
        return 1;
    }

    if (l >= 2) {
        if (X[l-2] == 'c' && X[l-1] == 'h') {
            return is_choku(X.substr(0, l-2));
        }
    }
    if (X[l-1] == 'o' || X[l-1] == 'k' || X[l-1] == 'u') {
        return is_choku(X.substr(0, l-1));
    }
    return 0;
}

int main()
{
    string X;
    cin >> X;
    cout << (is_choku(X) ? "YES" : "NO") << endl;
    return 0;
}

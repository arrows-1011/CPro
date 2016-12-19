#include <iostream>
#include <vector>

using namespace std;

bool valid(const string& s)
{
    int sum = 0;
    for (int i = 0; i < 11; i++) {
        if (i <= 4) {
            sum += (s[i] - '0') * (6 - i);
        } else {
            sum += (s[i] - '0') * (12 - i);
        }
    }
    
    sum %= 11;
    if (sum <= 1) sum = 11;
    return (11 - sum == (s[11] - '0'));
}

void solve(string& s)
{
    int j = -1;
    for (int i = 0; i < 12; i++) {
        if (s[i] == '?') {
            j = i;
            break;
        }
    }

    vector<int> res;
    for (int i = 0; i <= 9; i++) {
        s[j] = (char)('0' + i);

        if (valid(s)) {
            res.emplace_back(i);
        }
    }

    if (res.size() >= 2) {
        cout << "MULTIPLE" << endl;
    } else {
        cout << res[0] << endl;
    }
}

int main()
{
    string s;
    cin >> s;
    solve(s);
    return 0;
}

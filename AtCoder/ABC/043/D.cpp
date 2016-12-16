#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s.size() == 2) {
        if (s[0] == s[1]) {
            cout << 1 << " " << 2 << endl;
        } else {
            cout << -1 << " " << -1 << endl;
        }
        return 0;
    }
    
    int sp = -1;
    for (int i = 0; i < (int)s.size() - 2; i++) {
        map<char, int> cnt;
        for (int j = 0; j < 3; j++) {
            if (++cnt[s[i + j]] == 2) {
                sp = i;
                goto end;
            }
        }
    }
    end:;
    if (sp == -1) {
        cout << -1 << " " << -1 << endl;
    } else {
        cout << sp + 1 << " " << sp + 3 << endl; 
    }        
    return 0;
}

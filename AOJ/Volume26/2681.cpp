#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> p(N), d(N), revp(N), revd(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        
        int len = s.size();
        for (int j = 0; j < len; j++) {
            if (s[j] == '(') {
                p[i] += 1;
            } else {
                p[i] -= 1;
                d[i] = min(d[i], p[i]);
            }
        }
        
        for (int j = len - 1; j >= 0; j--) {
            if (s[j] == ')') {
                revp[i] += 1;
            } else {
                revp[i] -= 1;
                revd[i] = min(revd[i], revp[i]);
            }
        }
    }

    vector<bool> used(N);
    
    int ld = 0;    
    bool update = 1;
    
    while (update) {
        update = 0;
        
        int pmax = -1, idx = -1;
        for (int i = 0; i < N; i++) {
            if (used[i]) continue;
            if (ld + d[i] >= 0 && p[i] > pmax) {
                pmax = p[i];
                idx = i;
            }
        }

        if (idx != -1) {
            ld += p[idx];
            used[idx] = 1;
            update = 1;
        }       
    }

    int rd = 0;
    update = 1;
    
    while (update) {
        update = 0;
        
        int revpmax = -1, idx = -1;
        for (int i = 0; i < N; i++) {
            if (used[i]) continue;
            if (rd + revd[i] >= 0 && revp[i] > revpmax) {
                revpmax = revp[i];
                idx = i;                
            }
        }

        if (idx != -1) {
            rd += revp[idx];
            used[idx] = 1;
            update = 1;
        }
    }

    bool poss = (ld - rd == 0);
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            poss = 0;
            break;
        }
    }
    
    cout << (poss ? "Yes" : "No") << endl;
    return 0;
}

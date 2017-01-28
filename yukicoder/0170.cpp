#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    set<string> used;
    used.insert(s);

    queue<string> que;
    que.push(s);

    int N = s.size(), cnt = 0;
    
    while (!que.empty()) {
        string n = que.front(); que.pop();

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                swap(n[i], n[j]);
                if (used.count(n) == 0) {
                    used.insert(n);
                    cnt++;
                    que.push(n);
                }                    
                swap(n[i], n[j]);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

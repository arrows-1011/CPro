#include <iostream>
#include <queue>

using namespace std;

int main()
{
    string s[3];
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }

    queue<int> q[3];
    for (int i = 0; i < 3; i++) {
        for (auto& ch : s[i]) {
            q[i].push(ch - 'a');
        }
    }

    int cur = 0;
    while (!q[cur].empty()) {
        int c = cur;
        cur = q[cur].front();
        q[c].pop();
    }
    cout << (char)(cur + 'A') << endl;
    return 0;
}

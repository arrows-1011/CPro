#include <iostream>
#include <deque>

using namespace std;

int main()
{
    string s;
    cin >> s;
    deque<char> dq;
    for (auto& ch : s) {
        if (ch == 'B') {
            if (!dq.empty()) {
                dq.pop_back();
            }
        } else {
            dq.push_back(ch);
        }
    }

    while (!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << endl;
    
    return 0;
}

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N, L;
    cin >> N;
    
    map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        cin >> L;
        cnt[L]++;
    }
    
    int mx = 0, num = -1;
    for (auto& c : cnt) {
        if (c.second >= mx) {
            mx = c.second;
            num = c.first;
        }
    }
    cout << num << endl;
    return 0;
}

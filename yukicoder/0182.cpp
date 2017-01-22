#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    map<int, int> cnt;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    int res = 0;
    for (auto& c : cnt) {
        if (c.second == 1) res++;
    }
    cout << res << endl;
    return 0;
}

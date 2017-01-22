#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int C;
        cin >> C;
        pq.push(C);
    }
    
    int res = 0;
    while (M > 0 && !pq.empty()) {
        int t = pq.top(); pq.pop();
        if (t == 1) res++;
        else {
            pq.push(t - 1);
        }
        M--;
    }
    cout << res << endl;
    return 0;
}

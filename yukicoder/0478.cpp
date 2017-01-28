#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    vector<int> res;
    for (int i = 0; i < K; i++) {
        res.emplace_back(1e9);
    }
    
    int p = 3, q = 1;
    for (int i = K; i < N; i++) {
        if ((i - K) % 2 == 0) {
            res.emplace_back(p);
            p += 1;
        } else {
            res.emplace_back(q);
            q += 1;
        }
    }
       
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
  
using namespace std;
  
int main()
{
    int N, M, T, a;
    cin >> N >> M >> T;
    vector<bool> used(T+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> a; 
        for (int j = a; j >= max(a-M, 0); j--) {
            used[j] = 1;
        }
        for (int j = a; j < min(a+M, T); j++) {
            used[j] = 1;
        }
    }
    cout << count(used.begin(), used.end()-1, 0) << endl;
    return 0;
}

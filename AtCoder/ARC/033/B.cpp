#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, x;
    cin >> N >> M;
    set<int> a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> x;
        a.insert(x);
        c.insert(x);
    }
    for (int i = 0; i < M; i++) {
        cin >> x;
        b.insert(x);
        c.insert(x);
    }
   
    double cm = 0;
    for (auto &v: a) {
        if (b.count(v) > 0) {
            cm += 1;
        } 
    }
    
    printf("%.10f\n", cm / c.size());
    return 0;
}

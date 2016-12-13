#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

constexpr int MAX = 300000;

int main()
{
    int N, a, b;
    vector<int> v(MAX, 0);
    cin >> N;
    while (N--) {
        scanf("%d %d", &a, &b);
        v[a + b]++;
    }
    
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] > 1) {
            v[i + 1] += v[i] / 2;
            v[i] = v[i] & 1;
        }
        if (v[i] == 1) {
            printf("%d %d\n", i, 0);
        }
    }
    return 0;
}

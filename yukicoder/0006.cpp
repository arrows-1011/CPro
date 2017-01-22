#include <iostream>
#include <vector>

using namespace std;

int h(int x)
{
    if (x < 10) {
        return x;
    }

    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return h(sum);
}

int solve(vector<pair<int, int>>& p)
{
    vector<bool> u(10);
    int s = 0, res = 0, num = -1;
    for (int t = 0; t < (int)p.size(); t++) {
        int n = p[t].first;
        if (u[n]) {
            for (; s < t; s++) {
                if (p[s].first == n) {
                    s++;
                    break;
                }
                u[p[s].first] = 0;
            }
        } else {
            u[n] = 1;
        }
                
        if (t - s + 1 >= res) {
            res = t - s + 1;
            num = p[s].second;
        }
    }
    return num;
}

int main()
{
    constexpr int MAX = 252521;
    vector<bool> prime(MAX, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < MAX; i++) {
        if (!prime[i]) continue;
        for (int j = i * 2; j < MAX; j += i) {
            prime[j] = 0;
        }
    }

    int K, N;
    cin >> K >> N;
    vector<pair<int, int>> p;
    for (int i = K; i <= N; i++) {
        if (prime[i]) p.emplace_back(h(i), i);
    }

    cout << solve(p) << endl;
    return 0;
}

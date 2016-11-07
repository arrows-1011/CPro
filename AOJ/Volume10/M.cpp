#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
    int point;
    string name;

    P() {}
    P(int point, string name) : point{point}, name{name} {}

    bool operator < (const P& p) const {
        if (point != p.point) {
            return point > p.point;            
        }
        return name < p.name;
    }
};

bool c(int X, int K, int L, const vector<P>& info, const vector<int>& p)
{
    int sum = 0;
    int rnk = K - X;
    for (int i = 0; i < X; i++) {
        if (p[i] <= rnk) {
            rnk = min(rnk + 1, K);
            continue;
        }

        if (info[p[i]].name < info[rnk].name) {        
            sum += info[rnk].point - info[p[i]].point;
        } else {
            sum += info[rnk].point - info[p[i]].point + 1;
        }
        if (sum > L) return 0;
    }
    return (sum <= L);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, K, L;
    while (cin >> N >> M >> K >> L, N > 0) {
        string name;
        int point;
        vector<P> info;
        for (int i = 0; i < N; i++) {
            cin >> name >> point;
            info.emplace_back(point, name);
        }

        sort(info.begin(), info.end());
        
        map<string, int> num;
        for (int i = 0; i < N; i++) {
            num[info[i].name] = i;
        }
        
        vector<int> p(M);
        string fav;
        for (int i = 0; i < M; i++) {
            cin >> fav;
            p[i] = num[fav];
        }

        sort(p.begin(), p.end());

        int l = 0, r = min(K, M);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (c(mid, K, L, info, p)) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if (c(r, K, L, info, p)) {
            cout << r << endl;
        } else {
            cout << l << endl;
        }
    }        
    return 0;
}

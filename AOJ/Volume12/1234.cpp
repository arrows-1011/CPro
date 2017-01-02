#include <bits/stdc++.h>

using namespace std;

struct Data {
    int p, gd, gs, id;
    
    Data() { p = gd = gs = id = -1; }
    
    Data(int p, int gd, int gs, int id) :
        p{p}, gd{gd}, gs{gs}, id{id} {}

    bool operator == (const Data& d) const {
        return (p == d.p && gd == d.gd && gs == d.gs);
    }
    
    bool operator != (const Data& d) const {
        return !(*this == d);
    }
        
    bool operator < (const Data& d) const {
        if (p != d.p) {
            return p < d.p;            
        } else if (gd != d.gd) {
            return gd < d.gd;
        } 
        return gs < d.gs;
    }
};

auto f(int x) -> double
{
    return (x <= 1 ? 1 : f(x - 1) * x);
}

auto get_result(int S, const vector<vector<int>>& results) -> vector<Data>
{
    vector<int> point(4), goal_diff(4), goal(4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((S >> i & 1) || (S >> j & 1) || i == j) continue;
            
            int p1 = results[i][j], p2 = results[j][i];
            point[i] += (p1 > p2 ? 3 : p1 < p2 ? 0 : 1);
            goal[i] += p1;
            goal_diff[i] += p1 - p2;
        }
    }
    
    vector<Data> d(4);
    for (int i = 0; i < 4; i++) {
        if (S >> i & 1) continue;
        d[i] = {point[i], goal_diff[i], goal[i], i};
    }
    sort(d.rbegin(), d.rend());
    return d;
}

auto win_p(int mt, const vector<vector<int>>& results) -> double
{        
    auto r = get_result(0, results);
    if ((r[0].id == mt && r[0] != r[2]) ||
        (r[1].id == mt && r[1] != r[2])) {
        return 1;
    }

    if ((r[2].id == mt && r[2] != r[1]) ||
        (r[3].id == mt && r[3] != r[1])) {
        return 0;                
    }
    
    if (r[0] == r[3]) return 2.0 / 4;

    int S = (1 << 4) - 1, size = -1;
    if (r[0] != r[1]) {
        for (int i = 3; i >= 1; i--) {
            if (r[i] == r[1]) {
                for (int j = 1; j <= i; j++) {
                    S &= ~(1 << r[j].id);
                }
                size = i;
                break;
            }
        }

        r = get_result(S, results);
        if (r[0] == r[size - 1]) return 1.0 / size;
        
        if (r[0].id == mt && r[0] != r[1]) return 1;
        if (r[0] != r[1]) return 0;

        S = (1 << 4) - 1;
        S &= ~(1 << r[0].id);
        S &= ~(1 << r[1].id);
        r = get_result(S, results);        
        
        if (r[0].id == mt && r[0] != r[1]) {
            return 1;
        }

        return (r[0] == r[1] ? 1.0 / 2 : 0);
    } else {
        for (int i = 0; i <= 2; i++) {
            S &= ~(1 << r[i].id);
        }       
        
        r = get_result(S, results);
        if ((r[0].id == mt && r[0] != r[2]) ||
            (r[1].id == mt && r[1] != r[2])) {
            return 1;
        }
        
        if (r[0] == r[2]) return 2.0 / 3;
        if (r[2].id == mt) return 0;

        S = (1 << 4) - 1;
        S &= ~(1 << r[0].id);
        S &= ~(1 << r[1].id);
        r = get_result(S, results);
                
        return (r[0] == r[1] ? 1.0 / 2 : 1);        
    }
}

int main()
{
    int Tc;
    cin >> Tc;
    while (Tc--) {
        int mt = -1;
        vector<string> v(5);
        
        for (int i = 0; i < 5; i++) {
            cin >> v[i];            
        }
        for (int i = 0, j = 6; i < 4; i++, j += 5) {
            if (v[0][j - 1] == '*') mt = i;
        }

        vector<vector<int>> results(4, vector<int>(4));
        vector<pair<int, int>> np;
        int s[] = {11, 16, 21};
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1, k = s[i]; j < 4; j++, k += 5) {
                if (isdigit(v[i + 1][k])) {
                    results[i][j] = v[i + 1][k] - '0';
                    results[j][i] = v[i + 1][k + 2] - '0';
                } else {
                    np.emplace_back(i, j);
                }
            }
        }
        
        auto poss = [](int p) -> double {        
            return f(8) / f(p) / f(8 - p) * pow(0.25, p) * pow(0.75, 8 - p);
        };
        
        vector<double> p(9);
        for (int i = 0; i <= 8; i++) {
            p[i] = poss(i);
        }

        double res = 0;
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                for (int k = 0; k <= 8; k++) {
                    for (int l = 0; l <= 8; l++) {
                        int tp[] = {i, j, k, l};
                        for (int m = 0; m < 2; m++) {
                            int a, b;
                            tie(a, b) = np[m];
                            results[a][b] = tp[a];
                            results[b][a] = tp[b];
                        }
                        
                        double mp = p[i] * p[j] * p[k] * p[l];
                        res += mp * win_p(mt, results);
                    }
                }
            }
        }
        printf("%.10f\n", res);
    }        
    return 0;
}

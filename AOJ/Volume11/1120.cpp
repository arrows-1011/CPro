#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Pile;
typedef vector<Pile> Piles;

struct P { int p, h; P(int p, int h) : p(p), h(h) {} };

P get_pos(Piles &piles, int id)
{
    for (int i = 0; i < (int)piles.size(); i++) {
        for (int j = 0; j < (int)piles[i].size(); j++) {
            if (piles[i][j] == id) return P(i, j);
        }
    }
    return P(-1, -1);
}

void move(Piles &piles, int pos)
{
    int id = piles[pos].back();
    piles[pos].pop_back();
    piles.push_back(Pile(1, id));
}

int main()
{
    int M, a, b;
    while (cin >> M, M) {
        Piles piles(M);
        for (int i = 0; i < M; i++) {
            piles[i] = Pile(1, i+1);
        }
        while (cin >> a >> b, (a | b)) {
            auto p1 = get_pos(piles, a), p2 = get_pos(piles, b);
            if (b == 0 && p1.h == 0) continue;
            if (p1.p == p2.p && p1.h >= p2.h) continue;
            
            while (piles[p1.p].back() != a) {
                move(piles, p1.p);
            }
            piles[p1.p].pop_back();
            if (b == 0) {
                piles.push_back(Pile(1, a));
            } else {
                p2 = get_pos(piles, b);
                piles[p2.p].push_back(a);
            }
        }
        vector<int> res;
        for (auto &pile: piles) {
            if (pile.size() > 0) {
                res.push_back(pile.size());
            }

        }
        sort(res.begin(), res.end());
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i] << endl;
        }
        cout << "end" << endl;
    }    
    return 0;
}

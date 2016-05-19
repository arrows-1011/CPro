#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;

    Point(){}
    Point(ll x, ll y) : x(x), y(y) {}
};

typedef vector<Point> Polygon;

bool is_integer_area(const Polygon &p)
{
    ll N = p.size();
    ll res = 0;
    for (ll i = 1; i < N+1; i++) {
	res += (p[i%N].x - p[i-1].x) * (p[i%N].y + p[i-1].y);
    }
    if (abs(res) > 0 && abs(res) % 2 == 0) return 1;
    return 0;
}

int main()
{
    ll N;
    cin >> N;
    vector<Point> p(N);
    for (ll i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }
    
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = i+1; j < N; j++) {
            for (ll k = j+1; k < N; k++) {
                Polygon pg;
                pg.push_back(p[i]);
                pg.push_back(p[j]);
                pg.push_back(p[k]);
                if (is_integer_area(pg)) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

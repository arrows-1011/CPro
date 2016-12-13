#include <iostream>
#include <map>
#include <vector>

using namespace std;

using pii = pair<int, int>;

map<pii, int> mp;

bool check(vector<int>& h, vector<int>& w, int a)
{
    if (a == 1) {
	if (mp[pii(h[0], w[0])] == 4) {
	    swap(h[0], h[1]);
            swap(w[0], w[1]);
	}
	if (h[1] == h[0] && h[1] == w[0]) return true;
	if (w[1] == h[0] && w[1] == w[0]) return true;
    } else {
	map<int, int> mp2;
	for (int i = 0; i < 3; i++) {
	    if (h[i] == w[i]) return false;
	    mp2[h[i]]++;
            mp2[w[i]]++;
	}
	return (mp2.size() == 3);
    }
    return false;
}

int main()
{
    int h, w;
    vector<int> nh, nw;
    map<int, int> mp2;
    for (int i = 0; i < 6; i++) {
	cin >> h >> w;
	mp2[h]++; mp2[w]++;
	if (h > w) swap(h, w);
	if (++mp[pii(h, w)] == 1) {
	    nh.emplace_back(h);
            nw.emplace_back(w);
	}
    }
    int a = 0, b = 0, c = 0;
    for(auto& it : mp) {
	if (it.second == 2) a++;
	if (it.second == 4) b++;
	if (it.second == 6) c++;
    }
    if (a == 3 || (a == 1 && b == 1)){
	cout << (check(nh, nw, a) ? "yes" : "no") << endl;
    } else if (c == 1 && mp2[nh[0]] == 12) {
	cout << "yes" << endl;
    } else {
	cout << "no" << endl;
    }
    return 0;
}

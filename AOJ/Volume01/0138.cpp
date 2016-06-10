#include <bits/stdc++.h>

using namespace std;

typedef pair<double, int> p;
 
int main()
{
    vector<p> v, th;
    int n = 3, num;
    double data;
    
    while (n--) {
        v.clear();
        for (int i = 0; i < 8; i++) {
            cin >> num >> data;
            v.push_back(p(data, num));
        }
        sort(v.begin(), v.end());
        printf("%d %.2f\n", v[0].second, v[0].first);
        printf("%d %.2f\n", v[1].second, v[1].first);
        th.push_back(v[2]);
    }
    sort(th.begin(), th.end());
    printf("%d %.2f\n", th[0].second, th[0].first);
    printf("%d %.2f\n", th[1].second, th[1].first);
    return 0;
}

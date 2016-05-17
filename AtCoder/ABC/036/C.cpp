#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    set<int> st;
    vector<int> a(N), b;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    for (auto &x: st) {
        b.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        cout << lower_bound(b.begin(), b.end(), a[i]) - b.begin() << endl;
    }    
    return 0;
}

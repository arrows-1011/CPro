#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    set<int> st;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        st.insert(v[i]);
    }

    if ((int)st.size() != N) {
        cout << "NO" << endl;
        return 0;
    }
    
    sort(v.begin(), v.end());
    int d = v[1] - v[0];
    bool poss = 1;
    for (int i = 2; i < N; i++) {
        if (v[i] - v[i - 1] != d) {
            poss = 0;
            break;
        }
    }
    cout << (poss ? "YES" : "NO") << endl;
    return 0;
}

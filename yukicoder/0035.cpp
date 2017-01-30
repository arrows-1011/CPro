#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int ok = 0, ng = 0;
    for (int i = 0; i < N; i++) {
        int T;
        string S;
        cin >> T >> S;
        int t = 12 * T / 1000;
        int s = S.size();

        ok += min(t, s);
        ng += s - min(t, s);
    }
    
    cout << ok << " " << ng << endl;
    return 0;
}

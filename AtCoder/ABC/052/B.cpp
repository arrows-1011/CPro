#include <iostream>

using namespace std;

int main()
{
    int N;
    string s;
    cin >> N >> s;
    int x = 0, res = 0;
    for (char c : s) {
        x += (c == 'I' ? +1 : -1);
        
        res = max(res, x);
    }
    cout << res << endl;
    return 0;
}

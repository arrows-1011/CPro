#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    int i = 0, cnt[2] = {};

    while (i < N && S[i] == '<') {
        ++i;
        ++cnt[0];
    }
    
    i = N - 1;
    while (i >= 0 && S[i] == '>') {
        --i;
        ++cnt[1];
    }
    cout << N - min(cnt[0], cnt[1]) << endl;
    return 0;
}

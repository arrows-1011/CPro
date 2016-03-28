#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N; N--;
    N = (N + 1) % 12;
    cout << N+1 << endl;
    return 0;
}

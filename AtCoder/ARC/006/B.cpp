#include <bits/stdc++.h>

using namespace std;

#define MAX 25

int main()
{
    int N, L;
    cin >> N >> L;
    cin.ignore();

    int a[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            a[i][j] = j;
        }
    }
    
    string s;
    for (int i = 0; i < L; i++) {
        getline(cin, s);
        for (int j = 0; j < 2*N-1; j++) {
            if (s[j] == '-') {
                swap(a[i][j/2], a[i][j/2+1]);
            }
        }
    }

    getline(cin, s);
    int p = s.find('o') / 2, l = L-1;

    while (l >= 0) {
        p = a[l][p];
        l--;
    }
    cout << p + 1 << endl;
    return 0;
}

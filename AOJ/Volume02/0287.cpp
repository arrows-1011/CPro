#include <bits/stdc++.h>

using namespace std;

int main()
{
    const string unit[] = {"", "Man", "Oku", "Cho", "Kei", "Gai",
                           "Jo", "Jou", "Ko", "Kan", "Sei", "Sai", "Gok",
                           "Ggs", "Asg", "Nyt", "Fks", "Mts"};

    int M, N;
    while (cin >> M >> N, M) {
        int v[18] = {};
        v[0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 18; j++) {
                v[j] *= M;
            }
            for (int j = 0; j < 18; j++) {
                int carry = v[j] / 10000;
                if (carry > 0) {
                    v[j+1] += carry;
                    v[j] -= 10000 * carry;
                }
            }
        }
        for (int i = 17; i >= 0; i--) {
            if (v[i] > 0) {
                cout << v[i] << unit[i];
            }
        }
        cout << endl;
    }       
    return 0;
}

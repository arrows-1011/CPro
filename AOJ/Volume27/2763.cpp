#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
using ull = unsigned long long;

const ull b = 1000000007ULL;

vector<ull> rolling_hash(char* S, int N, vector<ull>& p)
{
    vector<ull> h(N + 1);
    for (int i = 0; i < N; i++) {
        h[i + 1] = h[i] * b + S[i];
        p[i + 1] = p[i] * b;
    }
    return h;
}

int main()
{
    char S[MAX];
    scanf("%s", S);
    
    int N = strlen(S);
    vector<ull> p(N + 1);
    p[0] = 1;
    
    auto h = rolling_hash(S, N, p);    
    
    int mini = MAX;
    for (int i = 0; i < N; i++) {
        int A = i + 1;
        int B = (N - 3 * A) / 2;

        if (B <= 0) break;
        if ((N - 3 * A) % 2 != 0) continue;

        auto A1 = h[A] - h[0] * p[A];
        auto B1 = h[A + B] - h[A] * p[B];
        auto A2 = h[A * 2 + B] - h[A + B] * p[A];
        auto B2 = h[2 * (A + B)] - h[A * 2 + B] * p[B];
        auto A3 = h[N] - h[2 * (A + B)] * p[A];

        if (A1 == A2 && A2 == A3 && B1 == B2) {
            mini = min(mini, A + B);
        }
    }    
    
    if (mini == MAX) {
        printf("mitomerarenaiWA\n");
    } else {
        printf("Love ");
        for (int i = 0; i < mini; i++) {
            printf("%c", S[i]);
        }
        printf("!\n");
    }        
    return 0;
}

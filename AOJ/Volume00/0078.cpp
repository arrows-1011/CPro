#include <bits/stdc++.h>

using namespace std;

#define MAX 15
 
int main()
{
    int Mag[MAX][MAX], N;
     
    while (cin >> N, N) {
        memset(Mag, 0, sizeof(Mag));
         
        int dx = N/2+1, dy = N/2, cnt = N*N, num = 1;
        Mag[dx++][dy++] = num++;
        while (num < cnt+1) {
            if (dx >= N) {
                dx = 0;
            } else if(dy >= N) {
                dy = 0;
            } else if(dy < 0) {
                dy = N-1;
            } else if(Mag[dx][dy]) {
                dx++;
                dy--;
            } else {
                Mag[dx++][dy++] = num++;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%4d", Mag[i][j]);
            }
            puts("");
        }
    }
    return 0;
}

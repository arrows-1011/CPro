#include <bits/stdc++.h>

using namespace std;

#define MAX 1010
#define MAX_P 12
typedef vector<char> Vec;
typedef vector<Vec> Mat;

int dp[MAX][1<<MAX_P];

int get_dir(char ch)
{
    if (ch == 'L') return 0;
    if (ch == 'U') return 1;
    if (ch == 'R') return 2;
    return 3;
}

int main()
{
    int HPi, HPm;
    while (cin >> HPi >> HPm, HPi) {
        int H, W;
        cin >> H >> W;
        Mat a(H, Vec(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> a[i][j];
            }
        }
        int T, d, dmg[26] = {}, S;
        char ch;
        cin >> T;        
        for (int i = 0; i < T; i++) {
            cin >> ch >> d;
            dmg[ch-'A'] = d;
        }
        cin >> S;
        
        char dir;
        int dist, x = 0, y = 0;
        vector<int> vec;
        const int dx[] = {-1, 0, 1, 0};
        const int dy[] = {0, -1, 0, 1};
        
        for (int i = 0; i < S; i++) {
            cin >> dir >> dist;
            int d = get_dir(dir);
            for (int j = 0; j < dist; j++) {
                x += dx[d]; y += dy[d];
                vec.push_back(dmg[a[y][x]-'A']);
            }
        }

        int P;
        cin >> P;
        vector<int> p(P);
        for (int i = 0; i < P; i++) {
            cin >> p[i];
        }
        
        memset(dp, -1, sizeof(dp));
        dp[0][0] = HPi;
        
        int N = vec.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < (1<<P); j++) {
                if (dp[i][j] <= 0) continue;
                if (dp[i][j] - vec[i] > 0) {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] - vec[i]);
                }
                for (int k = 0; k < P; k++) {
                    if (j >> k & 1) continue;
                    dp[i][j|(1<<k)] = max(dp[i][j|(1<<k)], min(dp[i][j] + p[k], HPm));
                }
            }
        }
        bool reachable = 0;
        for (int i = 0; i < (1<<P); i++) {
            if (dp[N][i] > 0) {
                reachable = 1;
                break;
            }
        }
        cout << (reachable ? "YES" : "NO") << endl;
    }
    return 0;
}

/*
  初期のHP, 最大のHPが与えられる。
  RxCのマス。マスは英語大文字[A-Z]のいずれかで表される。
  [A-Z]のうちT個にはトラップがあり、それぞれ文字iのところに行くとdiのダメージを受ける。
  S回の移動がある。それぞれ、進む向きと距離が与えられる。
  P個のポーションがある。それぞれpiだけHPが回復する。これはマスに入る前(移動前)に使用する(複数の種類を組み合わせて使用することが可能(ただし、各ポーションは1回しか使えない))。(最大HPが上限)
  HPが0以下になるとGAME OVER
  S回の移動を終えたときにどのようにしてもGAME OVERになる場合はNO, そうでなければYES.
*/

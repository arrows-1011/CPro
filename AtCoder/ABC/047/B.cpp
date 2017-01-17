#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int W, H, N;
    cin >> W >> H >> N;
    vector<vector<bool>> F(H, vector<bool>(W, 1));
    for (int i = 0; i < N; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < x; j++) {
                    F[i][j] = 0;
                }
            }
        } else if (a == 2) {
            for (int i = 0; i < H; i++) {
                for (int j = x; j < W; j++) {
                    F[i][j] = 0;
                }
            }
        } else if (a == 3) {
            for (int i = 0; i < W; i++) {
                for (int j = 0; j < y; j++) {
                    F[j][i] = 0;
                }
            }
        } else {
            for (int i = 0; i < W; i++) {
                for (int j = y; j < H; j++) {
                    F[j][i] = 0;
                }
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            sum += F[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}

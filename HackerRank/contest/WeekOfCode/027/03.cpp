#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, Q, angle;
    cin >> N >> Q;
    
    using Vec = vector<int>;
    using Mat = vector<Vec>;
    Mat mat(N, Vec(N));   

    using ll = long long;
    
    auto get = [](ll x) -> int {
        if (x == 1) return 1;
        if (x == 2) return 0;
        if (x == 3) return 1;
        
        x -= 4;
        x %= 7;
        
        const int res[] = {0, 0, 1, 1, 1, 0, 1};
        return res[x];
    };
    
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            mat[i][j] = get((i + 1) * (j + 1) * (i + 1) * (j + 1));
        }        
    }

    auto rotation = [N](Mat& mat) -> Mat {
        Mat m = mat;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mat[j][N - i - 1] = m[i][j];
            }
        }
        return mat;
    };
    
    vector<Mat> mats(4);
    mats[0] = mat;
    
    for (int i = 1; i <= 3; i++) {
        mats[i] = rotation(mat);        
    }
    
    int c[4][4] = {{}};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int cnt = 0;
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    if (mats[i][k][l] != mats[j][k][l]) {
                        cnt++;
                    }
                }                    
            }
            c[i][j] = cnt;
        }
    }
        
    while (Q--) {
        cin >> angle;        
        angle /= 90;
        cout << c[0][(angle % 4)] << endl;
    }
    
    return 0;
}

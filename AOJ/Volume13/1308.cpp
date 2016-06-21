#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;
typedef vector<int> vec;
typedef vector<vec> mat;

bool gauss_jordan(const mat &A, const vec &b)
{
    int n = A.size();
    mat B(n, vec(n+1));
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    B[i][j] = A[i][j];
	}
    }
    
    for (int i = 0; i < n; i++) {
	B[i][n] = b[i];
    }
    
    for (int i = 0; i < n; i++) {
	int pivot = i;
	for (int j = i; j < n; j++) {
	    if (B[j][i] > B[pivot][i]) {
		pivot = j;
	    }
	}
        
	swap(B[i], B[pivot]);              
        
	for (int j = 0; j < n; j++) {
	    if (i != j && B[j][i] == 1) {
		for (int k = i; k <= n; k++) {
		    B[j][k] = (B[j][k] + B[i][k]) % 2;
		}
	    }
	}
    }

    for (int i = 0; i < n; i++) {
        bool non_zero = 0;
        for (int j = 0; j < n; j++) {
            if (B[i][j] != 0) non_zero = 1;
        }
        if (!non_zero && B[i][n] == 1) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int W, H, D;
    while (cin >> W >> H >> D, W) {
        mat a(H, vec(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> a[i][j];
            }
        }
        
        mat A(H*W, vec(H*W, 0));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int n = i * W + j;
                A[n][n] = 1;
                for (int k = 0; k < H; k++) {
                    for (int l = 0; l < W; l++) {
                        int MD = abs(i - k) + abs(j - l);
                        int m = k * W + l;
                        if (D == MD) {
                            A[n][m] = 1;
                        }
                    }
                }
            }
        }

        vec b(H*W);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (a[i][j] == 1) b[i*W+j] = 1;
            }
        }
        cout << (gauss_jordan(A, b) ? 1 : 0) << endl;
    }
    return 0;
}

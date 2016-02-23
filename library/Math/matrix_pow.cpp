#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;

const int M = 10000;

mat mul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < (int)A.size(); i++) {
	for (int k = 0; k < (int)B.size(); k++) {
	    for (int j = 0; j < (int)B[0].size(); j++) {
		C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % M;
	    }
	}
    }
    return C;
}

mat pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < (int)A.size(); i++) {
	B[i][i] = 1;
    }
    while (n > 0) {
	if (n & 1) {
            B = mul(B, A);
        }
	A = mul(A, A);
	n >>= 1;
    }
    return B;
}

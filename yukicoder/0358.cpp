#include <iostream>

using namespace std;

bool is_kadomatsu(int* A)
{
    if (A[0] == A[1] ||
        A[0] == A[2] ||
        A[1] == A[2]) return 0;

    if (A[0] < A[1] && A[1] > A[2]) {
        return 1;
    }

    if (A[0] > A[1] && A[1] < A[2]) {
        return 1;
    }
    
    return 0;
}

int main()
{
    int A[3];
    cin >> A[0] >> A[1] >> A[2];
    if (is_kadomatsu(A)) {
        cout << "INF" << endl;
    } else {
        int cnt = 0;
        for (int p = 1; p <= max(A[0], max(A[1], A[2])); p++) {
            int B[] = {A[0] % p, A[1] % p, A[2] % p};
            if (is_kadomatsu(B)) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }        
    return 0;
}

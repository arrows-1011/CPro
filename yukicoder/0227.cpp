#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> A(5);
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    if (A[0] == A[3] || A[0] == A[4] || A[1] == A[4]) {
        cout << "NO HAND" << endl;
    } else if ((A[0] == A[2] && A[3] == A[4]) || (A[0] == A[1] && A[2] == A[4])) {
        cout << "FULL HOUSE" << endl;        
    } else if (A[0] == A[2] || A[1] == A[3] || A[2] == A[4]) {
        cout << "THREE CARD" << endl;
    } else if ((A[0] == A[1] && (A[2] == A[3] || A[3] == A[4])) ||
               (A[1] == A[2] && A[3] == A[4])) {
        cout << "TWO PAIR" << endl;
    } else if (A[0] == A[1] || A[1] == A[2] || A[2] == A[3] || A[3] == A[4]) {
        cout << "ONE PAIR" << endl;
    } else {
        cout << "NO HAND" << endl;
    }
    return 0;
}

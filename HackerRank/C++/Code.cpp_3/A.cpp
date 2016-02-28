#include <iostream>

using namespace std;

int main()
{
    int N, Q, K;
    cin >> N >> Q;
    int **arr = new int *[N];
    for (int i = 0 ; i < N ; i++) {
        cin >> K;
        arr[i] = new int[K];
        for (int j = 0 ; j < K ; j++) {
            cin >> arr[i][j];
        }
    }
    int a, b;
    for (int i = 0 ; i < Q ; i++) {
        cin >> a >> b;
        cout << arr[a][b] << endl;
    }
    delete[] arr;
    return 0;
}

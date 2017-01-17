#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> T(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        sum += T[i];
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int P, X;
        cin >> P >> X; P--;
        cout << sum - (T[P] - X) << endl;
    }        
    return 0;
}

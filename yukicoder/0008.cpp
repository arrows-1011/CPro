#include <iostream>

using namespace std;

int main()
{
    int P;
    cin >> P;
    for (int i = 0; i < P; i++) {
        int N, K;
        cin >> N >> K;
        cout << (N % (K + 1) != 1 ? "Win" : "Lose") << endl;
    }        
    return 0;
}

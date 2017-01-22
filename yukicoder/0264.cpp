#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    if (N == K) {
        cout << "Drew" << endl;
    } else {
        if ((N == 0 && K == 1) ||
            (N == 1 && K == 2) ||
            (N == 2 && K == 0)) {
            cout << "Won" << endl;
        } else {
            cout << "Lost" << endl;
        }
    }        
    return 0;
}

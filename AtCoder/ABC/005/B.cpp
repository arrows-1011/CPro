#include <iostream>

using namespace std;

int main()
{
    int N, T, min = 114514;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T;
        if (T < min) {
            min = T;
        }
    }
    cout << min << endl;
    return 0;
}

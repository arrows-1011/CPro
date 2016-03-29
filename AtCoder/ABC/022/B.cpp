#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000

int main()
{
    int N, A, cnt = 0;
    vector<int> flower(MAX+1, 0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (++flower[A] > 1) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}

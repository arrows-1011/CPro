#include <iostream>

using namespace std;

int main()
{
    int K, S, res = 0;
    cin >> K >> S;
    for (int X = 0; X <= K; X++) {
        for (int Y = 0; Y <= K; Y++) {
            int Z = S - (X + Y);
            if (0 <= Z && Z <= K) {
                ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}

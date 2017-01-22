#include <iostream>

using namespace std;

int main()
{
    int W, H;
    char ch;
    char c[] = {'W', 'B'};
    cin >> W >> H >> ch;
    int p = (ch == 'B');
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << c[p];
            p ^= 1;
        }
        if (W % 2 == 0) p ^= 1;
        cout << endl;
    }        
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int g;
    cin >> g;
    while (g--) {
        int n;
        cin >> n;
        
        int x = 0, p;
        for (int i = 0; i < n; i++) {
            cin >> p;
            if (p & 1) {
                x ^= (p + 1);
            } else {
                x ^= (p - 1);
            }
        }        

        if (x != 0) {
            cout << "W" << endl;
        } else {
            cout << "L" << endl;
        }
    }
        
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<bool> used(11);
    for (int i = 0; i < 9; i++) {
        int B;
        cin >> B;
        used[B] = 1;
    }

    for (int i = 1; i <= 10; i++) {
        if (!used[i]) {
            cout << i << endl;
            break;
        }
    }    
    return 0;
}

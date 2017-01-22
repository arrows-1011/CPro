#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    for (int i = 0; i <= 30; i++) {
        if (N <= (1 << i)) {
            cout << i << endl;
            break;
        }
    }        
    return 0;
}

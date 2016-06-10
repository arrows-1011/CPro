#include <iostream>

using namespace std;
 
int main()
{
    int s, sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> s;
        sum += s;
    }
    cout << sum << endl;
    return 0;
}

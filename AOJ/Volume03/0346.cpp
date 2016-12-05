#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int e[12];
    for (int i = 0; i < 12; i++) {
        cin >> e[i];
    }
    sort(e, e + 12);
    if (e[0] == e[1] && e[1] == e[2] && e[2] == e[3] &&
        e[4] == e[5] && e[5] == e[6] && e[6] == e[7] &&
        e[8] == e[9] && e[9] == e[10] && e[10] == e[11]) {
        cout << "yes" << endl;            
    } else {
        cout << "no" << endl;
    }
    return 0;
}

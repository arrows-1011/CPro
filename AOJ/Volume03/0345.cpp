#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int e[4];
    for (int i = 0; i < 4; i++) {
        cin >> e[i];
    }
    sort(e, e + 4);
    cout << (e[0] == e[1] && e[2] == e[3] ? "yes" : "no") << endl; 
    return 0;
}


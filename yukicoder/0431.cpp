#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> D(3);
    int S;
    cin >> D[0] >> D[1] >> D[2] >> S;
    if (S == 1) {
        cout << "SURVIVED" << endl;
    } else {
        cout << (accumulate(D.begin(), D.end(), 0) >= 2 ?
                 "DEAD" : "SURVIVED") << endl;        
    }       
    return 0;
}

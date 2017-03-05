#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    
    A = (A == 1 ? 14 : A);
    B = (B == 1 ? 14 : B);
    
    if (A > B) {
        cout << "Alice" << endl;
    } else if (A < B) {
        cout << "Bob" << endl;
    } else {
        cout << "Draw" << endl;
    }        
    return 0;
}

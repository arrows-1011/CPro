#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N;
    cin >> N;
    if(N < 60) cout << "Bad" << endl;
    else if(N < 90) cout << "Good" << endl;
    else if(N < 100) cout << "Great" << endl;
    else cout << "Perfect" << endl;
    return 0;
}

#include <iostream>

using namespace std;

typedef long long ll;

int main(){
 
    ll N;
    ll sum = 0;
 
    cin >> N;
    for (ll j = 1; j*j <= N; j++) {     
        if (N % j == 0) { 
            sum += j;
            if (j*j != N) sum += N/j;            
        }
    }
       
    sum -= N;
 
    if( N < sum ) cout << "Abundant" << endl;
    else if( N > sum ) cout << "Deficient" << endl;
    else cout << "Perfect" << endl;
    return 0;
 
}

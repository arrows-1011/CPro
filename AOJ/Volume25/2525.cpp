#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long double ld;
typedef long long ll;
  
int main(){
    ld M,Rd,Rr,Cd,Cr;
  
    cin >> M >> Rd >> Rr >> Cd >> Cr;
  
    ld D,R;
  
    D = ceil(Cd*100/Rd); R = ceil(Cr*100/Rr);
  
    if(M - (D + R) >= 0) printf("%lld\n" ,(ll)(M-(D+R)));
    else cout << "-1" << endl;
  
    return 0;
}

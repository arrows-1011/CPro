#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int h,m;
 
    cin >> h >> m;
    h = 18 - h;
    if(m) m = 60-m, h--;
    cout << h*60+m << endl;
 
    return 0;
}

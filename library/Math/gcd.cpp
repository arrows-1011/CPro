/*

  ユークリッドの互除法
  O(log min(a,b))で最大公約数を求める。

  拡張ユークリッドの互除法
  最大公約数を求めるのに加えて、ax+by = gcd(x,y)
  となるa,bを1つ求める。

*/

#include <iostream>
#include <algorithm>
using namespace std;

//ユークリッドの互除法
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

//拡張ユークリッドの互除法
int extgcd(int a,int b,int &x,int &y){
    int g = a;
    x = 1; y = 0;

    if(b != 0){
	g = extgcd(b, a % b, y ,x);
	y -= (a / b) * x;
    }
    return g;
}

int main(){
    int a,b,x,y;

    cin >> a >> b;
    cout << gcd(a,b) << endl;
    cout << __gcd(a,b) << endl;
    cout << extgcd(a,b,x,y) << endl;
    cout << x << " " << y << endl;

    return 0;
}

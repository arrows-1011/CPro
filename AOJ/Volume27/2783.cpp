#include <iostream>

using namespace std;

using ll = long long;

ll c(ll x)
{
    return x * (x + 1) / 2;
}

int main()
{
    int N;
    cin >> N;
    
    int L = 1, R = N;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (c(mid) > N) {
            R = mid;
        } else {
            L = mid;
        }
    }
    
    int K = (c(L) == N ? L : R);

    string res = string(K, ')') + string(K, '(');
    N = c(K) - N;    
    for (int p = K; N > 0; N--, p--) {
        swap(res[p - 1], res[p]);
    }
    
    cout << res << endl;
    return 0;
}

/*
   N
   1 )(
   2 )()(
   3 ))((
   4 )())((
   5 ))()((
   6 )))(((
   7 )()))(((
   8 ))())(((
   9 )))()(((
  10 ))))((((
  11 )())))((((
  12 ))()))((((
  13 )))())((((
  14 ))))()((((
  15 )))))(((((
  16 )()))))(((((
  17 ))())))(((((
  18 )))()))(((((
  19 ))))())(((((
  20 )))))()(((((
  21 ))))))((((((
   
*/

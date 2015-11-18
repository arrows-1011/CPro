/*
  素因数分解する
  O(√n)
 */

#include <bits/stdc++.h>

using namespace std;

map<int,int> prime_factor(int n){
    map<int,int> res;
    for(int i = 2 ; i*i <= n ; i++){
	while(n % i == 0){
	    ++res[i];
	    n /= i;
	}
    }
    if(n != 1) res[n] = 1;
    return res;
}

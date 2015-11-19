#include <bits/stdc++.h>

using namespace std;

#define MAX_P 100

int fact[MAX_P]; // n! mod p のテーブル O(p)

int mod_fact(int n,int p,int &e){
    e = 0;
    if(n == 0) return 1;
    int res = mod_fact(n/p,p,e);
    e += n/p;
    if(n / p % 2 != 0) return res * (p-fact[n%p])%p;
    return res * fact[n%p] % p;
}

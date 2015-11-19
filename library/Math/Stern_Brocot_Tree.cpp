/*
  既約有理数 a/b (a <= N, b <= N)
  を表示する。
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
vector<pii> v;

void stern_brocot(int N,int pl = 0,int ql = 1,int pr = 1,int qr = 0){
    int pm = pl + pr, qm = ql + qr;
    if(pm > N || qm > N) return;
    v.push_back(pii(pm,qm));         // a/bのlist
    stern_brocot(N,pl,ql,pm,qm);
    stern_brocot(N,pm,qm,pr,qr);
}

int main(){
    stern_brocot(5);
    sort(v.begin(),v.end());
    for(int i = 0 ; i < (int)v.size() ; i++){
	cout << v[i].first << "/" << v[i].second << endl;
    }
    return 0;
}

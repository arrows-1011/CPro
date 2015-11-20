#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 15010
typedef pair<int,int> pii;
typedef pair<pii,int> P;
 
bool check(int a,int b,int c){
    if(a >= b+c || b >= a+c || c >= a+b) return false;
    return true;
}
 
int main(){
    vector<int> prime;
    bool p[MAX];
    fill(p,p+MAX,true);
    p[0] = p[1] = false;
    for(int i = 2 ; i < MAX ; i++){
	if(!p[i]) continue;
	prime.push_back(i);
	for(int j = 2*i ; j < MAX ; j += i){
	    p[j] = false;
	}
    }
    int T;
    while(cin >> T, T){
	int cnt = 0;
	set<P> st;
	int size = prime.size();
	for(int i = 0 ; i < size ; i++){
	    if(prime[i] > T) continue;
	    for(int j = i ; j < size ; j++){
		if(prime[i]+prime[j] > T) continue;
		int k = T-prime[i]-prime[j];
		if(k < 0 || k >= MAX || !p[k]) continue;
		int a[3] = {prime[i],prime[j],k};
		sort(a,a+3);
		if(st.count(P(pii(a[0],a[1]),a[2]))) continue;
		st.insert(P(pii(a[0],a[1]),a[2]));
		if(check(a[0],a[1],a[2])){
		    cnt++;
		}
	    }
	}
	cout << cnt << endl;
    }
    return 0;
}

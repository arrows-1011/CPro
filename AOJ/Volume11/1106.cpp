#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10000
typedef pair<int,int> pii;
int a,b,c;
 
bool input(){
    cin >> a >> b >> c;
    return a;
}
 
int main(){
    while(input()){
	bool found = false;
	vector<pii> pr,qs;
	for(int p = 1 ; p <= a ; p++){
	    int r = a/p;
	    if(a % p != 0 || p < r) continue;
	    pr.push_back(pii(p,r));
	}
	int cc = c < 0 ? -c : c;
	for(int q = -cc ; q <= cc ; q++){
	    if(q == 0) continue;
	    int s = 0;
	    if(c < 0){
		if(q < 0 && abs(c) % abs(q) == 0){
		    if(abs(c) % abs(q) == 0){
			s = abs(c)/abs(q);
		    }
		}else{
		    if(abs(c) % q == 0){
			s = abs(c)/q;
			s = -s;
		    }
		}
	    }else{
		if(q < 0){
		    if(c % abs(q) == 0){
			s = c/abs(q);
			s = -s;
		    }
		}else{
		    if(c % q == 0){
			s = c/q;
		    }
		}
	    }
	    if(s == 0) continue;
	    qs.push_back(pii(q,s));
	}
	if(c == 0){
	    for(int i = -MAX ; i <= MAX ; i++){
		qs.push_back(pii(0,i));
		qs.push_back(pii(i,0));
	    }
	}
	for(int i = 0 ; i < (int)pr.size() ; i++){
	    for(int j = 0 ; j < (int)qs.size() ; j++){
		int p = pr[i].first,r = pr[i].second;
		int q = qs[j].first,s = qs[j].second;
		if(p == r && q < s) continue;
		if(p*s+q*r == b){
		    cout << p << " " << q << " " << r << " " << s << endl;
		    found = true;
		    goto END;
		}
	    }
	}
	if(!found){
	    cout << "Impossible" << endl;
	}
    END:;
    }
    return 0;
}

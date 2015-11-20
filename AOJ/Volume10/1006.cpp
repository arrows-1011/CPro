#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 2401
 
int makeTime(int a, int b){
    int ah, bh, am, bm;
    am = a % 100; a /= 100;
    ah = a;
 
    bm = b % 100; b /= 100;
    bh = b;
  
    int diff_h = bh - ah;
    int diff_m = bm - am;
    if(diff_m < 0){
	diff_m += 60;
	diff_h--;
    }
    return diff_h*60 + diff_m;
}
 
int main(){
    int N, P, Q, K, p, q;
 
    while(cin >> N >> P >> Q, (N | P | Q)){
	bool watch[MAX];
	memset(watch, false, sizeof(watch));
	for(int i = 0 ; i < N ; i++){
	    cin >> K;
	    vector<int> vec; 
	    vec.push_back(P);
	    for(int j = 0 ; j < K ; j++){
		cin >> p >> q;
		vec.push_back(p);
		vec.push_back(q);
	    }
	    vec.push_back(Q);
	    for(int j = 0 ; j < (int)vec.size() ; j+=2){
		for(int k = vec[j] ; k <= vec[j+1] ; k++){
		    watch[k] = true;
		}
	    }
	}
	int max = 0, cnt = P-1, prev = P, pos;
	for(int i = P ; i <= Q ; i++){
	    if(i % 100 >= 60){ 
		cnt++; 
		continue;
	    }
	    if(watch[i]){
		cnt++;
		pos = i;
	    }else{
		while(!watch[i] || i % 100 >= 60) i++;
		max = std::max(max, makeTime(prev,cnt));
		prev = i;       
		cnt = i;
	    }
	}
 
	max = std::max(max, makeTime(prev, cnt));
	cout << max << endl;
    }
 
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int cards = 13;
 
bool flg;
 
void rec(vector<int> a,int sum,vector<int> &v){
    if(sum == 0){
	flg = true;
	return;
    }
    for(int i = 1 ; i <= 13 ; i++){
	if(a[i] && sum % i == 0){
	    v.push_back(i);
	    a[i]--;
	    rec(a,sum-i,v);
	    if(flg) return;
	    v.pop_back();
	    a[i]++;
	}
    }
}
 
int main(){
    int n;
 
    while(cin >> n ,n){
	vector<int> a(cards+1,0),v;
	int m,sum = 0;
 
	for(int i = 0 ; i < n ; i++){
	    cin >> m;
 
	    sum += m;
	    a[m]++;
	}
 
	flg = false;
	rec(a,sum,v);
 
	if(flg){
	    int len = (int)v.size();
	    reverse(v.begin(),v.end());
	    for(int i = 0 ; i < len ; i++){
		if(!i) cout << v[i];
		else cout << " " << v[i];
	    }
	    cout << endl;
	}
	else cout << "No" << endl;
    }
    return 0;
}

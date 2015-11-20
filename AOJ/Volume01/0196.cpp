#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,char> P;
typedef pair<int,P> PP;
 
bool compare(PP a,PP b){
    return a.first > b.first;
}
 
int main(){
    int n,res[10];
    char ch;
 
    while(cin >> n ,n){
	vector<PP> v;
	for(int i = 0 ; i < n ; i++){
	    int sum = 0 , f = 0;
	    cin >> ch;
	    for(int j = 0 ; j < n-1 ; j++){
		cin >> res[j];
		if(res[j]==0) sum += 5;
		else if(res[j]==2) sum++;
		else f++;
	    }  
	    v.push_back(PP(sum,P(f,ch))); 
	}
	sort(v.begin(),v.end(),compare);
	for(int i = 0 ; i < n ; i++){
	    cout << v[i].second.second << endl;
	}
    }
    return 0;
}

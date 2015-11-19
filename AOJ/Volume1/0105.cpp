#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;
 
typedef pair<string,int> P;
 
int main(){
    string str;
    int page,cnt=0;
    vector<P> v;
 
    while(cin >> str >> page){
	v.push_back(P(str,page));
	cnt++;
    }
 
    sort(v.begin(),v.end());
    for(int i = 0 ; i < cnt; i++){
	if(i == 0){
	    cout << v[i].first << endl;
	    cout << v[i].second;
	    continue;
	}
 
	if(v[i].first == v[i-1].first && v[i].second!=v[i-1].second){
	    cout << ' ' << v[i].second;
	    continue;
	}
	else cout << endl;
 
	cout << v[i].first << endl;
	cout << v[i].second;
    }
    puts("");
    return 0;
}

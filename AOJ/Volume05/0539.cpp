#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){
    int d,n,m;
 
    while(cin >> d ,d){
	vector<int> cu,sh;
	int c,s;
	sh.push_back(0);
 
	cin >> n >> m;
	for(int i = 1 ; i < n ; i++){
	    cin >> s;
	    sh.push_back(s);
	}
	sh.push_back(d);
	for(int i = 0 ; i < m ; i++){
	    cin >> c;
	    cu.push_back(c);
	} 
	int sum = 0;  
	sort(sh.begin(),sh.end());
	sort(cu.begin(),cu.end());
	int pos = 1;
	for(int i = 0 ; i < m ; ){
	    if(sh[pos] >= cu[i]){
		sum += min(sh[pos]-cu[i],cu[i]-sh[pos-1]);
		i++;
	    }
	    else ++pos;
	}
	cout << sum << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s;
    cin >> s;
    vector<string> v;
    for(int i = 0 ; i < 5 ; i++){
	for(int j = 0 ; j < 5 ; j++){
	    string ss; ss += s[i]; ss += s[j];
	    v.push_back(ss);
	}
    }
    int N;
    cin >> N; N--;
    sort(v.begin(),v.end());
    cout << v[N] << endl;
    return 0;
}

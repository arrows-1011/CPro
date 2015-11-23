#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int a[6] = {0};
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++){
	a[s[i]-'A']++;
    }
    for(int i = 0 ; i < 6 ; i++){
	if(i > 0) cout << " ";
	cout << a[i];
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 110
 
int main(){
    int N;
    string str[MAX_N];
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> str[i];
	reverse(str[i].begin(),str[i].end());
    }
    sort(str,str+N);
    for(int i = 0 ; i < N ; i++){
	reverse(str[i].begin(),str[i].end());
	cout << str[i] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,x[4]={0};
    char ch;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> ch;
	x[ch-'1']++;
    }
    cout << *max_element(x,x+4) << " " << *min_element(x,x+4) << endl;
    return 0;
}

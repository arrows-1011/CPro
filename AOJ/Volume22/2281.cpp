#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int,int> P;
string str;
 
void change(int a,int b,int diff){
    char ach  = str[a],bch = str[b];
    int anum,bnum;
 
    anum = ach - 'a';
    bnum = bch - 'a';
    anum += diff;
    bnum += diff;
 
    if(anum >= 26) anum %= 26;
    if(bnum >= 26) bnum %= 26;
    str[a] = bnum + 'a';
    str[b] = anum + 'a';
}
 
int main(){
    int n;
    while(cin >> n,n){
	vector<P> v;
	str.clear();
	int a,b;
	cin >> str;
	for(int i = 0 ; i < n ; i++){
	    cin >> a >> b;
	    v.push_back(P(a,b));
	}
	for(int i = n-1 ; i >= 0 ; i--){   
	    change(v[i].first-1,v[i].second-1,v[i].second-v[i].first);
	}
	cout << str << endl;
    }
    return 0;
}

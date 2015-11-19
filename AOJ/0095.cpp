#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int n,num,w;
    pair<int,int> p[20];  
 
    cin >> n;
    for(int i = 0 ; i < n ; i++){
	cin >> num >> w;
	p[i] = make_pair(-w,num);
    }
    sort(p,p+n);
    cout << p[0].second << ' ' << (-1)*p[0].first << endl;
    return 0;
}

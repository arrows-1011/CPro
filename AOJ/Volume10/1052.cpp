#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> P;
 
int main(){
    int n;     
    while(cin >> n,n){
        vector<P> v;
        int t,b;
        for(int i = 0 ; i < n ; i++){
            cin >> t >> b;
            v.push_back(P(b,t));
        }
        sort(v.begin(),v.end());
         
        bool flg = false;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += v[i].second;
            if(sum > v[i].first){
                flg = true;
                break;
            }
        }
        if(flg) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}

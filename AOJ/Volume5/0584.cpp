#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)
 
int change(string s1){
    int num;
    string str = s1;
    stringstream s(str);
    s >> num;
    return num;
}
 
int main(){
    int n,a;
    vector<int> v,tmp;
     
    cin >> n;
    rep(i,n){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
 
    if(n >= 4) n = 4;
    rep(i,n){
        tmp.push_back(v[i]);
    }
     
    vector<string> vec;
    for(int i = 0 ; i < tmp.size() ; i++){
        for(int j = 0 ; j < tmp.size() ; j++){
            if(i == j) continue;
            stringstream s;
            s << tmp[i];
            s << tmp[j];
            vec.push_back(s.str());
        }
    }
     
    vector<int> ans;
    for(int i = 0 ; i < vec.size() ; i++){
        ans.push_back(change(vec[i]));
    }
    sort(ans.begin(),ans.end());
     
    cout << ans[2] << endl;
    return 0;
}

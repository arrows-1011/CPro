#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;
 
typedef pair<int,string> P;
 
bool compare(P a,P b){
    return a.first > b.first;
}
 
int main(){
    int n,a,b,c,t = 0;
    string str;
     
    while(cin >> n,n){
        if(t) puts("");
        t++;
        vector<P> v;
        for(int i = 0 ; i < n ; i++){
            cin >> str >> a >> b >> c;
            int p = a*3+c;
            v.push_back(P(p,str));
        }
        stable_sort(v.begin(),v.end(),compare);
         
        for(int i = 0 ; i < n ; i++){
            cout << v[i].second << "," << v[i].first << endl;
        }
    }
    return 0;
}

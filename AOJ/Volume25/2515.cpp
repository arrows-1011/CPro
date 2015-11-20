#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
 
typedef pair<string,int> P;
 
int main(){
    int n,t,sh,sm,gh,gm,dt;
    string name;
    vector<P> v;
     
    cin >> n >> t;
    scanf("%d:%d" ,&sh ,&sm);
    cin >> name;
    scanf("%d:%d" ,&gh ,&gm);
    cin >> name;
     
    int tt = gh*60+gm;
    for(int i = 0 ; i < n-1 ; i++){
        scanf("%d:%d" ,&sh ,&sm);
        cin >> name;
        dt = 60*sh+sm - tt;
         
        if(dt >= t){
            v.push_back(P(name,dt));
        }
        scanf("%d:%d" ,&gh ,&gm);
        cin >> name;
        tt = gh*60+gm;
    }
     
    cout << v.size() << endl;
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}

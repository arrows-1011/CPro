#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
 
typedef pair<int,int> P;
 
int main(){
    int num,solve;
    vector<P> v;
     
    while(true){
        scanf("%d,%d" ,&num, &solve);
        if(!num&&!solve) break;
        v.push_back(P(-solve,num));
    }
    sort(v.begin(),v.end());
     
    int select;
    while(cin >> select){
        int cnt = 1;
        for(int i = 0 ; i < v.size() ; i++){
            if(i&&v[i].first != v[i-1].first) cnt++;
            if(v[i].second == select) break;
        }
        cout << cnt << endl;
    }    
    return 0;
}

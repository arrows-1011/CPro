#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)
 
int main(){
    int n,K;
     
    while(cin >> n >> K , n + K){
        map<string,int> m;
        string str[11],in;
        rep(i,n){
            cin >> str[i];
        }
        int cnt = 0;
        if(K == 2){
            rep(i,n){
                rep(j,n){
                    if(i == j) continue;
                    in = str[i]+str[j];
                    if(!m[in]){
                        m[in]++;
                        cnt++;
                    }
                }
            }
        }
        else if(K == 3){
            rep(i,n){
                rep(j,n){
                    if(i == j) continue;
                    rep(k,n){
                        if(i == k ||j == k) continue;
                        in = str[i]+str[j]+str[k];
                        if(!m[in]){
                            m[in]++;
                            cnt++;
                        }
                    }
                }
            }
        }
        else{
            rep(i,n){
		rep(j,n){
		    if(i == j) continue;
                    rep(k,n){
                        if(i == k || j == k) continue;
                        rep(l,n){
                            if(i == l || j == l || k == l) continue;
                            in = str[i]+str[j]+str[k]+str[l];
                            if(!m[in]){
                                m[in]++;
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N;
    while(cin >> N){
        int cnt[7] = {0};
        string in;
        vector<int> a(N),b(N);
        for(int i = 0 ; i < N ; i++){
            cin >> in;
            a[i] = in[0]-'0';
            b[i] = in[1]-'0';
            cnt[a[i]]++;
            cnt[b[i]]++;
        }
        if(N == 1){
            cout << "Yes" << endl;
            continue;
        }
        bool check = false;
        for(int i = 0 ; i < N ; i++){
            if(a[i] == b[i]){
                if(cnt[a[i]] == 2){
                    check = true;
                    break;
                }
            }
        }
        if(check){
            cout << "No" << endl;
            continue;
        }
        int odd = 0,even = 0;
        for(int i = 0 ; i < 7 ; i++){
            if(cnt[i]&1) odd++;
            else even++;
        }
        cout << ((even == 7 || odd == 2) ? "Yes" : "No") << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> Vec;
 
int N, maxi;
vector<string> v;
Vec num,l;
set<Vec> st;
 
int solve(int k, int idx, int sum, int S, int p){
    if(k == maxi){
        if(p != 0 || st.count(num)) return 0;
        st.insert(num);
        return 1;
    }
    int res = 0;
    if(idx == N-1){
        int val = (int)(v[idx][k]-'A');
        int ns = (sum + p) % 10;
        int np = (sum + p) / 10;
        if(num[val] != -1){
            if(l[idx] > 0 && k == l[idx] && num[val] == 0){
                return 0;
            }
            if(ns == num[val]){
                res = solve(k+1, 0, 0, S, np);
            }
        }else{
            for(int i = 0 ; i < 10 ; i++){
                if(S >> i & 1) continue;
                num[val] = i;
                if(ns == i && !(l[idx] > 0 && k == l[idx] && i == 0)){
                    res += solve(k+1, 0, 0, S|(1<<i), np);
                }
                num[val] = -1;
            }
        }
    }else{
        if(v[idx][k] == '*'){
            res = solve(k, idx+1, sum, S, p);
        }else{
            int val = (int)(v[idx][k]-'A');
            if(num[val] != -1){
                if(l[idx] > 0 && k == l[idx] && num[val] == 0){
                    return 0;
                }
                res += solve(k, idx+1, sum+num[val], S, p);
            }else{
                for(int i = 0 ; i < 10 ; i++){
                    if(S >> i & 1) continue;
                    num[val] = i;
                    if(!(l[idx] > 0 && k == l[idx] && i == 0)){
                        res += solve(k, idx+1, sum+i, S|(1<<i), p);
                    }
                    num[val] = -1;
                }
            }
        }
    }
    return res;
}
 
int main(){
    while(cin >> N, N){
        v.resize(N); l.resize(N);
        maxi = 0;
        Vec len(N);
        for(int i = 0 ; i < N ; i++){
            cin >> v[i];
            l[i] = len[i] = v[i].size();
            l[i]--;
            maxi = max(maxi, len[i]);
            reverse(v[i].begin(),v[i].end());
        }
        if(len[N-1] < maxi){
            cout << 0 << endl;
            continue;
        }
        for(int i = 0 ; i < N ; i++){
            while(len[i] != maxi){
                v[i] += '*';
                len[i]++;
            }
        }
        num.resize(26, -1); st.clear();
        cout << solve(0, 0, 0, 0, 0) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 12
typedef vector<int> Vec;
 
int N,M;
 
bool rec(int idxT,int idxS,Vec &T,Vec &S){
    if(idxT == N && idxS == M) return 1;
    if(idxT == N || idxS == M) return 0;
    bool res = false;
    if(idxT+1 <= N && T[idxT] == S[idxS]){
        res |= rec(idxT+1,idxS+1,T,S);
    }
    if(idxT+2 <= N && (T[idxT]+1)%MOD == S[idxS]){
        res |= rec(idxT+2,idxS+1,T,S);
    }
    if(idxT-1 >= 0 && (T[idxT]-1+MOD)%MOD == S[idxS]){
        res |= rec(idxT-1,idxS+1,T,S);
    }
    return res;
}
 
int main(){
    int Tc;
    map<string,int> mp = {
        {"A",0},{"A#",1},
        {"B",2},
        {"C",3},{"C#",4},
        {"D",5},{"D#",6},
        {"E",7},
        {"F",8},{"F#",9},
        {"G",10},{"G#",11},
    };
    string in;
    cin >> Tc;
    while(Tc--){
        cin >> N >> M;
        Vec T(N);
        for(int i = 0 ; i < N ; i++){
            cin >> in;
            T[i] = mp[in];
        }
        reverse(T.begin(),T.end());
        Vec S(M);
        for(int i = 0 ; i < M ; i++){
            cin >> in;
            S[i] = mp[in];
        }
        reverse(S.begin(),S.end());
        bool can = rec(0,0,T,S) | rec(1,0,T,S);
        cout << (can ? "Yes" : "No") << endl;
    }
    return 0;
}

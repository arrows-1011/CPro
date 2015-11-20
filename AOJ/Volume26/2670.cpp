#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (1<<29)
 
struct State{
    int s,t;
    State(){}
    State(int s,int t) : s(s),t(t) {}
};
 
int getMin(int h,int m){
    return h*60+m;
}
 
bool check(State &s1,State &s2){
    return (s2.s <= s1.s && s1.t <= s2.t);
}
 
int main(){
    int V,N,M,h1,m1,h2,m2,K;
    cin >> V;
    vector<State> v(V);
    vector<int> cnt(V, 0),cnt2(V, 0);
    for(int i = 0 ; i < V ; i++){
        scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
        v[i] = State(getMin(h1,m1),getMin(h2,m2));
    }
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> K;
        for(int j = 0 ; j < K ; j++){
            scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
            State s = State(getMin(h1,m1),getMin(h2,m2));
            for(int k = 0 ; k < V ; k++){
                if(check(v[k],s)) cnt[k]++;
            }
        }
    }
    cin >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> K;
        for(int j = 0 ; j < K ; j++){
            scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
            State s = State(getMin(h1,m1),getMin(h2,m2));
            for(int k = 0 ; k < V ; k++){
                if(check(v[k],s)) cnt2[k]++;
            }
        }
    }
    int res = 0;
    for(int i = 0 ; i < V ; i++){
        res += min(cnt[i], cnt2[i]);
    }
    cout << res << endl;
    return 0;
}

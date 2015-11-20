#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAX = 1e5;
typedef long long ll;
typedef pair<char,int> P;
 
vector<int> tr[MAX+1];
int par[MAX+1],n,q;
int mark[MAX+1];
 
void init(){
    for(int i = 0 ; i < MAX ; i++){
        par[i] = i;
    }
}
 
int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}
 
void unite(int x,int y){
    x = find(x); y = find(y);
    if(x == y) return;
     
    par[y] = x;
}
 
bool same(int x,int y){
    return find(x) == find(y);
}
 
int tmp[MAX+1];
void rec(int x,int y,int z){
    int t = z;
    tmp[x] = y;
    if(mark[x]){
        t = x;
    }
    unite(t,x);
     
    for(int i = 0 ; i < tr[x].size() ; i++){
        rec(tr[x][i],x,t);
    }
}
 
int main(){
    int p,num;
    char m;
    while(cin >> n >> q , n + q){
        ll sum = 0;
        stack<P> st;
        init();
        fill(mark,mark+MAX,0);
        fill(tmp,tmp+MAX,0);
        mark[0] = 1;
        for(int i = 0 ; i < MAX ; i++){
            tr[i].clear();
        }
        for(int i = 1 ; i < n ; i++){
            cin >> p; --p;
            tr[p].push_back(i);
        }
        for(int i = 0 ; i < q ; i++){
            cin >> m >> num; --num;
            st.push(P(m,num));
             
            if(m == 'M'){
                ++mark[num];
            }
        }
        rec(0,0,0);
        while(q--){
            P p = st.top(); st.pop();
            if(p.first == 'Q'){
                sum += find(p.second)+1;
            }
            else{
                --mark[p.second];
                if(!mark[p.second]) {
                    unite(tmp[p.second],p.second);
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}

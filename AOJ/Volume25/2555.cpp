#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define MAX 114

vector<int> G[MAX];
int col[MAX];
bool found;

void dfs(int v)
{
    col[v] = 0;
    for(int i = 0 ; i < (int)G[v].size() ; i++){
        int to = G[v][i];
        if(col[to] == -1){
            dfs(to);
        }else if(col[to] == 0){
            found = true;            
            return;
        }
    }
    col[v] = 1;
}
    
int main()
{
    int M, N;
    cin >> M >> N;
    
    auto canGraph = [=](){
        int l[MAX][MAX], u[MAX][MAX];
        for(int i = 0 ; i < MAX ; i++){
            for(int j = 0 ; j < MAX ; j++){
                l[i][j] = -1;
                u[i][j] = 101;
            }
        }
        int K, s, t;
        string c;
        bool poss = 1;
        for(int i = 0 ; i < M ; i++){
            cin >> K;
            for(int j = 0 ; j < K ; j++){
                cin >> s >> c >> t;
                --s;
                if(c == ">="){
                    l[i][s] = max(l[i][s], t);
                }else{
                    u[i][s] = min(u[i][s], t);
                }
            }
            for(int j = 0 ; j < N ; j++){
                if(l[i][j] > u[i][j]){
                    poss = 0;
                    break;
                }
            }
        }

        if(!poss) return false;

        auto isConnect = [=](int from, int to){
            for(int i = 0 ; i < N ; i++){
                if(u[from][i] <= l[to][i]){
                    return true;
                }
            }
            return false;
        };
        
        for(int from = 0 ; from < M ; from++){
            for(int to = 0 ; to < M ; to++){
                if(from == to) continue;
                if(isConnect(from, to)){
                    G[from].push_back(to);
                }
            }
        }
        found = false;
        memset(col, -1, sizeof(col));
        for(int i = 0 ; i < M ; i++){
            if(col[i] == -1){
                dfs(i);
            }
        }                                       
        return !found;
    };
    
    cout << (canGraph() ? "Yes" : "No") << endl;
    return 0;
}


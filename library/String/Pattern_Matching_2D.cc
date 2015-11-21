/*
  fieldが検索対象
  patternが検索パターン
  
  field中にpatternがいくつ存在するかを計算する.
  O(N*M)
 */

#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000
#define MAX_T 10
typedef unsigned long long ull;
 
int N,M,P,Q;
char field[MAX][MAX],pattern[MAX][MAX];
 
ull hash[MAX][MAX],tmp[MAX][MAX];
 
void compute_hash(char a[MAX][MAX],int n,int m){
    const ull B1 = 9973;
    const ull B2 = 100000007;
   
    ull t1 = 1;
    for(int j = 0 ; j < Q ; j++) t1 *= B1;
   
    for(int i = 0 ; i < n ; i++){
        ull e = 0;
        for(int j = 0 ; j < Q ; j++) e = e * B1 + a[i][j];
        for(int j = 0 ; j + Q <= m ; j++){
            tmp[i][j] = e;
            if(j + Q < m) e = e * B1 - t1 * a[i][j] + a[i][j+Q]; 
        }
    }
   
    ull t2 = 1;
    for(int i = 0 ; i < P ; i++) t2 *= B2;
   
    for(int j = 0 ; j + Q <= m ; j++){
        ull e = 0;
        for(int i = 0 ; i < P ; i++) e = e * B2 + tmp[i][j];
     
        for(int i = 0 ; i + P <= n ; i++){
            hash[i][j] = e;
            if(i + P < n) e = e * B2 - t2 * tmp[i][j] + tmp[i+P][j];
        }
    }
}
 
int solve(){
    int cnt = 0;
    compute_hash(pattern, P, Q);
    ull res = hash[0][0];
    compute_hash(field, N, M);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(res == hash[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}


/*
  パターンT個のうち何個が、検索対象のグリッドに
  一度以上出現しているかを答える.
  
int T;
char patterns[MAX_T][MAX][MAX];

int solve(int x){
    multiset<ull> unseen;
    for(int k = 0 ; k < T ; k++){
	compute_hash(patterns[k], P, Q);
	unseen.insert(hash[0][0]);
    }
    compute_hash(field, N, M);
    for(int i = 0 ; i + P <= N ; i++){
	for(int j = 0 ; j + Q <= M ; j++){
	    unseen.erase(hash[i][j]);
	}
    }
    int ans = T - unseen.size();
    return ans;
}
*/

int main(){
    while(cin >> P >> Q >> N >> M){
        for(int i = 0 ; i < P ; i++){
            for(int j = 0 ; j < Q ; j++){
                cin >> pattern[i][j];
            }
        }
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                cin >> field[i][j];
            }
        }
        cout << solve() << endl;
    }
    return 0;
}

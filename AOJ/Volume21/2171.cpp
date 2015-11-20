#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 125
#define INF 1e9
const double EPS = 1e-8;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<double> vec;
typedef vector<vec> mat;
 
vec gauss_jordan(const mat &A,const vec &b){
    int n = A.size();
    mat B(n,vec(n+1));
    for(int i = 0 ; i < n ; i++){
	for(int j = 0 ; j < n ; j++){
	    B[i][j] = A[i][j];
	}
    }
    for(int i = 0 ; i < n ; i++){
	B[i][n] = b[i];
    }
    for(int i = 0 ; i < n ; i++){
	int pivot = i;
	for(int j = i ; j < n ; j++){
	    if(abs(B[j][i]) > abs(B[pivot][i])){
		pivot = j;
	    }
	}
	swap(B[i],B[pivot]);
	if(abs(B[i][i]) < EPS) return vec();
	for(int j = i+1 ; j <= n ; j++){
	    B[i][j] /= B[i][i];
	}
	for(int j = 0 ; j < n ; j++){
	    if(i != j){
		for(int k = i+1 ; k <= n ; k++){
		    B[j][k] -= B[j][i]*B[i][k];
		}
	    }
	}
    }
    vec x(n);
    for(int i = 0 ; i < n ; i++){
	x[i] = B[i][n];
    }
    return x;
}
 
struct Edge{
    int to,dist;
    Edge(int to,int dist) :
	to(to),dist(dist) {}
};
 
void solve(vi &sign,vii &road,vii &d,int S,int T,int N){
    mat A(N,vec(N,0));
    vec b(N,0);
    for(int i = 0 ; i < N ; i++){
	if(i == T){
	    A[i][i] = 1; b[i] = 0;
	    continue;
	}
	double sum = 0;
	int cnt = 0;
	if(sign[i] == 0){
	    for(int j = 0 ; j < N ; j++){
		if(road[i][j] != INF){
		    A[i][j] = -1;
		    sum += road[i][j];
		    cnt++;
		}
	    }
	}else{
	    int mini = INF;
	    for(int j = 0 ; j < N ; j++){
		if(road[i][j] != INF){
		    mini = min(mini,road[i][j]+d[j][T]);
		}
	    }
	    for(int j = 0 ; j < N ; j++){
		if(mini == road[i][j]+d[j][T] && road[i][j] != INF){
		    cnt++;
		    A[i][j] = -1;
		    sum += road[i][j];
		}
	    }
	}
	A[i][i] = cnt;
	b[i] = sum;
    }
    vec res = gauss_jordan(A,b);
    printf("%.10f\n",res[S]);
}
 
int main(){
    int N,S,T;
    while(cin >> N >> S >> T, N){
	S--; T--;
	vi sign(N);
	vii d(N,vi(N)),road(N,vi(N));
	for(int i = 0 ; i < N ; i++){
	    cin >> sign[i];
	}
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		cin >> d[i][j];
		if(d[i][j] == 0){
		    d[i][j] = INF;
		}
	    }
	    d[i][i] = 0;
	}
	road = d;
	for(int k = 0 ; k < N ; k++){
	    road[k][k] = INF;
	    for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
		    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		}
	    }
	}
	if(d[S][T] == INF){
	    cout << "impossible" << endl;
	}else{
	    solve(sign,road,d,S,T,N);
	}
    }
    return 0;
}

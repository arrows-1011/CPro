#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 300
#define INF 1e9
const double EPS = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;
typedef pair<double,int> P;
 
struct edge{
    int to,cap,rev;
    double cost;
    edge(int to,int cap,int rev,double cost) :
	to(to),cap(cap),rev(rev),cost(cost) {}
};
 
int V;
vector<edge> G[MAX_V];
double dist[MAX_V],h[MAX_V];;
int prevv[MAX_V],preve[MAX_V];
 
void add_edge(int from,int to,int cap,double cost){
    G[from].push_back(edge(to,cap,G[to].size(),cost));
    G[to].push_back(edge(from,0,G[from].size()-1,-cost));
}
 
double min_cost_flow(int s,int t,int f){
    double res = 0;
    fill(h,h+V,0);
    while(f > 0){
	priority_queue<P,vector<P>,greater<P> > Q;
	fill(dist,dist+V,INF);
	dist[s] = 0;
	Q.push(P(0,s));
	while(!Q.empty()){
	    P p = Q.top(); Q.pop();
	    int v = p.second;
	    if(dist[v] < p.first) continue;
	    for(int i = 0 ; i < (int)G[v].size() ; i++){
		edge &e = G[v][i];
		if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to] + EPS){
		    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
		    prevv[e.to] = v;
		    preve[e.to] = i;
		    Q.push(P(dist[e.to],e.to));
		}
	    }
	}
	if(dist[t] == INF){
	    return -1;
	}
	for(int v = 0 ; v < V ; v++){
	    h[v] += dist[v];
	}
	int d = f;
	for(int v = t ; v != s ; v = prevv[v]){
	    d = min(d,G[prevv[v]][preve[v]].cap);
	}
	f -= d;
	res += d*h[t];
	for(int v = t ; v != s ; v = prevv[v]){
	    edge &e = G[prevv[v]][preve[v]];
	    e.cap -= d;
	    G[v][e.rev].cap += d;
	}
    }
    return res;
}
 
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
 
void init(){
    for(int i = 0 ; i < MAX_V ; i++){
	G[i].clear();
    }
}
 
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
	int N,s,t,F;
	init();
	cin >> N >> s >> t >> F;
	mat a(N,vec(N)); vec c(N);
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		cin >> a[i][j];
	    }
	    cin >> c[i];
	}
	vec res = gauss_jordan(a,c);
	for(int i = 0 ; i < N ; i++){
	    int M,d[N],f;
	    cin >> M;
	    for(int j = 0 ; j < M ; j++){
		cin >> d[j];
	    }
	    for(int j = 0 ; j < M ; j++){
		cin >> f;
		add_edge(i,d[j],f,abs(res[i]-res[d[j]]));
	    }
	}
	V = N;
	double ans = min_cost_flow(s,t,F);
	if(ans == -1){
	    printf("impossible\n");
	}else{
	    printf("%.6f\n",ans);
	}
    }
    return 0;
}

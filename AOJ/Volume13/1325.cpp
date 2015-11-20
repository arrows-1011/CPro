#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> P;
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
 
int main(){
    int Tc,M,N;
 
    cin >> Tc;
    while(Tc--){
	vector<P> vec;
	for(int i = 0 ; i < 4 ; i++){
	    vec.push_back(P(dx[i],dy[i]));
	}
	cin >> M >> N;
	vec.push_back(P(M,N));
	vec.push_back(P(-N,M));
	vec.push_back(P(-M,-N));
	vec.push_back(P(N,-M));
	int cnt = 0;
 
	for(int m = 0 ; m <= 50 ; m++){
	    for(int n = 0 ; n <= 50 ; n++){
		if(m == n && m == 0) continue;
		int X = m*m + n*n;
		if(!((m*M+n*N) % X == 0 && (m*N-n*M)%X == 0)) continue;
		int Y = (m*M+n*N)/X;
		int Z = (m*N-n*M)/X;
		if((M*M+N*N)/X == Y*Y+Z*Z){
		    bool ok = true;
		    for(int i = 0 ; i < 8 ; i++){
			if(vec[i].first == m && vec[i].second == n){
			    ok = false;
			    break;
			}
		    }
		    if(ok) cnt++;
		}
	    }
	}
    
	if(cnt == 0) cout << "P" << endl;
	else cout << "C" << endl;
    }
 
    return 0;
}

#include <iostream>
#include <vector>
 
using namespace std;
 
#define MAX 100
typedef pair<int,int> P;
 
int main(){
    int a, b, c, N;
 
    while(cin >> a >> b >> c, a){
	cin >> N;
	int x, y, z, r;
	bool I[MAX], J[MAX], K[MAX];
 
	for(int i = 0 ; i < MAX ; i++){
	    I[i] = J[i] = K[i] = false;
	}
 
	vector<P> A[MAX], B[MAX], C[MAX];
	for(int i = 0 ; i < N ; i++){
	    cin >> x >> y >> z >> r; 
	    x--, y = y-a-1, z = z-a-b-1;
 
	    if(r == 1){
		I[x] = J[y] = K[z] = true;
	    }
	    A[x].push_back(P(y,z));
	    B[y].push_back(P(x,z));
	    C[z].push_back(P(x,y));
	}
 
	for(int i = 0 ; i < a ; i++){
	    if(I[i]){
		cout << 1 << endl;
	    }else{
		bool flg = false;
		for(int j = 0 ; j < A[i].size() ; j++){
		    if(J[A[i][j].first] && K[A[i][j].second]){
			flg = true;
			break;
		    }
		}
		cout << (flg?0:2) << endl;
	    }
	}
 
	for(int i = 0 ; i < b ; i++){
	    if(J[i]){
		cout << 1 << endl;
	    }else{
		bool flg = false;
		for(int j = 0 ; j < B[i].size() ; j++){
		    if(I[B[i][j].first] && K[B[i][j].second]){
			flg = true;
			break;
		    }
		}
		cout << (flg?0:2) << endl;
	    }
	}
	for(int i = 0 ; i < c ; i++){
	    if(K[i]){
		cout << 1 << endl;
	    }else{
		bool flg = false;
		for(int j = 0 ; j < C[i].size() ; j++){
		    if(I[C[i][j].first] && J[C[i][j].second]){
			flg = true;
			break;
		    }
		}
		cout << (flg?0:2) << endl;
	    }
	}
    }
    return 0;
}

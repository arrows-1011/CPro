#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100
 
char A[MAX][MAX],B[MAX][MAX];
 
void compress(int &h,int &w){
    int a = w,b = h;
    bool use[MAX],use2[MAX];
    vector<string> res;
 
    fill(use,use+h,true);
    fill(use2,use2+w,true);
 
    for(int i = 0 ; i < h ; i++){
	int cnt = 0;
	for(int j = 0 ; j < w ; j++){
	    if(A[i][j] != '.'){
		break;
	    }
	    cnt++;
	}
	if(cnt == w){ use[i] = false; a--; }
    }
 
    for(int i = 0 ; i < w ; i++){
	int cnt = 0;
	for(int j = 0 ; j < h ; j++){
	    if(A[j][i] != '.'){
		break;
	    }
	    cnt++;
	}
	if(cnt == h){ use2[i] = false; b--; }
    }
    for(int i = 0 ; i < h ; i++){
	if(!use[i]) continue;
	string s;
	for(int j = 0 ; j < w ; j++){
	    if(!use2[j]) continue;
	    s += A[i][j];
	}
	if(s.size() > 0){
	    res.push_back(s);
	}
    }
    h = res.size(); w = res[0].size();
    for(int i = 0 ; i < h ; i++){
	for(int j = 0 ; j < w ; j++){
	    A[i][j] = res[i][j];
	}
    }
}
 
void rotate(int &h,int &w){
    char tmp[MAX][MAX];
    for(int i = 0 ; i < h ; i++){
	for(int j = 0 ; j < w ; j++){
	    tmp[i][j] = A[i][j];
	}
    }
    for(int i = 0 ; i < h ; i++){
	for(int j = 0 ; j < w ; j++){
	    A[w-j-1][i] = tmp[i][j];
	}
    }
    int nh = w,nw = h;
    h = nh; w = nw;
}
 
int getPoint(int H,int W){
    int res = 0;
    for(int i = 0 ; i < H ; i++){
	int cnt = 0;
	for(int j = 0 ; j < W ; j++,cnt++){
	    if(B[i][j] != '#') break;
	}
	if(cnt == W){ res++; }
    }
    return res;
}
 
int getMaxScore(int h,int w,int H,int W){
    int maxPoint = -1;
    char C[MAX][MAX];
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    for(int k = 0 ; k < 4 ; k++){
		rotate(h,w);
		for(int l = 0 ; l < H ; l++){
		    for(int m = 0 ; m < W ; m++){
			C[l][m] = B[l][m];
		    }
		}
		bool ok = true;
		if(i+h > H || j+w > W) continue;
		for(int l = i ; l < i+h ; l++){
		    for(int m = j ; m < j+w ; m++){
			if(A[l-i][m-j] == '#' && B[l][m] == '#'){
			    ok = false; break;
			}
			if(A[l-i][m-j] == '#' && B[l][m] == '.'){
			    B[l][m] = A[l-i][m-j];
			}
		    }
		    if(!ok) break;
		}
		if(ok){
		    maxPoint = max(maxPoint,getPoint(H,W));
		}
		for(int l = 0 ; l < H ; l++){
		    for(int m = 0 ; m < W ; m++){
			B[l][m] = C[l][m];
		    }
		}
	    }
	}
    }
    return maxPoint;
}
 
int main(){
    int Tc,h,w,H,W;
    cin >> Tc;
    while(Tc--){
	cin >> h >> w;
	for(int i = 0 ; i < h ; i++){
	    for(int j = 0 ; j < w ; j++){
		cin >> A[i][j];
	    }
	}
	cin >> H >> W;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> B[i][j];
	    }
	}
	compress(h,w);
	cout << getMaxScore(h,w,H,W) << endl;
    }
    return 0;
}

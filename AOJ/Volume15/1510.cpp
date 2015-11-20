#include <bits/stdc++.h>
 
using namespace std;
 
bool field[5][5][5];
 
inline bool inField(int x,int y,int z){
    if(0 > x || x >= 5) return false;
    if(0 > y || y >= 5) return false;
    if(0 > z || z >= 5) return false;
    return true;
}
 
int getNum(int x,int y,int z,bool f){
    int res = 0;
    for(int zz = z-1 ; zz <= z+1 ; zz++){
	for(int yy = y-1 ; yy <= y+1 ; yy++){
	    for(int xx = x-1 ; xx <= x+1 ; xx++){
		if(xx == x && yy == y && zz == z) continue;
		if(!inField(xx,yy,zz)) continue;
		if(field[yy][xx][zz] == f){
		    res++;
		}
	    }
	}
    }
    return res;
}
 
int main(){
    int N,Tc = 0;
    bool space = false;
    while(cin >> N, N > 0){
	if(space) cout << endl;
	else space = true;
	for(int z = 0 ; z < 5 ; z++){
	    string str;
	    for(int y = 0 ; y < 5 ; y++){
		cin >> str;
		for(int x = 0 ; x < 5 ; x++){
		    field[y][x][z] = str[x]-'0';
		}
	    }
	}
	int M[2],a[27],b[27];
	cin >> M[0];
	for(int i = 0 ; i < M[0] ; i++){
	    cin >> a[i];
	}
	cin >> M[1];
	for(int i = 0 ; i < M[1] ; i++){
	    cin >> b[i];
	}
	while(N--){
	    bool next[5][5][5];
	    for(int z = 0 ; z < 5 ; z++){
		for(int y = 0 ; y < 5 ; y++){
		    for(int x = 0 ; x < 5 ; x++){
			int num;
			bool f = field[y][x][z];
			if(f){
			    num = getNum(x,y,z,true);
			    bool ok = false;
			    for(int i = 0 ; i < M[1] ; i++){
				if(num == b[i]){
				    ok = true;
				    break;
				}
			    }
			    if(!ok){
				f = !f;
			    }
			}else{
			    num = getNum(x,y,z,true);
			    bool ok = false;
			    for(int i = 0 ; i < M[0] ; i++){
				if(num == a[i]){
				    ok = true;
				    break;
				}
			    }
			    if(ok){
				f = !f;
			    }
			}
			next[y][x][z] = f;
		    }
		}
	    }
	    for(int z = 0 ; z < 5 ; z++){
		for(int y = 0 ; y < 5 ; y++){
		    for(int x = 0 ; x < 5 ; x++){
			field[y][x][z] = next[y][x][z];
		    }
		}
	    }
	}
	cout << "Case " << ++Tc << ":" << endl;
	for(int z = 0 ; z < 5 ; z++){
	    for(int y = 0 ; y < 5 ; y++){
		for(int x = 0 ; x < 5 ; x++){
		    cout << field[y][x][z];
		}
		cout << endl;
	    }
	    if(z != 4){
		cout << endl;
	    }
	}
    }
    return 0;
}

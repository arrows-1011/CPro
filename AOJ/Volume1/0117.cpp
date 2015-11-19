#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 21
#define INF 9999999
 
int main(){
    int mm[MAX][MAX],n,m,a,b,c,d,x1,x2,y1,y2;
     
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            mm[i][j] = INF;
	}
    }
     
    while(m--){
        scanf("%d,%d,%d,%d" ,&a ,&b , &c ,&d);
        mm[a][b] = c;
        mm[b][a] = d;
    }
     
    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                mm[i][j] = min(mm[i][j],mm[i][k]+mm[k][j]);
	    }
	}
    }
    scanf("%d,%d,%d,%d" ,&x1 ,&x2 ,&y1 ,&y2);
    cout << y1 - y2 - mm[x1][x2] - mm[x2][x1] << endl;
    return 0;
}

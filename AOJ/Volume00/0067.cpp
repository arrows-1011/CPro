#include <stdio.h>
 
void dfs(int x,int y,int mp[14][14]){
    if(mp[x][y] == 0) return;
    mp[x][y] = 0;
    if(mp[x-1][y] == 1) dfs(x-1,y,mp);
    if(mp[x][y-1] == 1) dfs(x,y-1,mp);
    if(mp[x+1][y] == 1) dfs(x+1,y,mp);
    if(mp[x][y+1] == 1) dfs(x,y+1,mp);
   
}
 
int main(){
    int cnt,mp[14][14] = {{}};

    while(1){ 
	cnt = 0;
	for(int i = 1 ; i < 13 ; i++){
	    for(int j = 1 ; j < 13 ; j++){
		if(scanf("%1d",&mp[i][j]) == EOF) return 0;
	    }
	}
 
	for(int i = 1 ; i < 13 ; i++){   
	    for(int j = 1 ; j < 13 ; j++){
		if(mp[i][j] == 1){
		    cnt++;
		    dfs(i,j,mp);
		}      
	    }
	}  
	printf("%d\n" ,cnt);
    }
    return 0;
}

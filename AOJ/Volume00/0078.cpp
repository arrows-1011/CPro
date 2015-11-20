#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 15
 
int main(){
    int Mag[MAX][MAX],n;
     
    while(cin >> n,n){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                Mag[i][j] = 0;
	    }
	}
         
        int dx = n/2+1, dy = n/2, cnt = n*n, num = 1;
        Mag[dx++][dy++] = num++;
        while(num < cnt+1){
            if(dx >= n) dx = 0;
            else if(dy >= n) dy = 0;
            else if(dy < 0) dy = n-1;
            else if(Mag[dx][dy]){
                dx++;
                dy--;
            }
            else{
                Mag[dx++][dy++] = num++;
            }
        }
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                printf("%4d" ,Mag[i][j]);
            }
            puts("");
        }
    }
    return 0;
}

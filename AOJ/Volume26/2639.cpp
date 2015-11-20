#include <bits/stdc++.h>
 
using namespace std;
 
int getArriveTime(int a,int b,int c){
    bool visited[60][60][2];
    memset(visited,false,sizeof(visited));
    int d = 0,st = 1,e = 0;
    for(int i = 0 ; ; i++,d++){
	if(i >= 60){ i %= 60; e++; }
	if(c == i && st) return c+e*60;
	if(visited[i][d][st]) return -1;
	visited[i][d][st] = true;
	if(d >= a && st == 1){ d = 0; st = 0; }
	if(d >= b && st == 0){ d = 0; st = 1; }
    }
    return -1;
}
 
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int res = getArriveTime(a,b,c);
    cout << (res >= 0 ? res : -1) << endl;
    return 0;
}

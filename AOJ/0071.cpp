#include <iostream>
#include <string>

using namespace std;
 
char bomb[8][8];
 
void printData(int i){
    cout << "Data " << i+1 << ':' << endl;
}
 
void dfs(int x,int y){
    bomb[y][x] = '0';
 
    for(int i = x-3 ; i <= x+3 ; i++){
	if((0 <= i && i <= 7)&&bomb[y][i]=='1') dfs(i,y);
    }
    for(int j = y-3 ; j <= y+3 ; j++){
	if((0 <= j && j <= 7)&&bomb[j][x]=='1') dfs(x,j);
    }
}
 
int main(){
    int n,x,y;
    string str;
   
    cin >> n;
    for(int i = 0 ; i < n ; i++){
	string tmp = "";
	for(int j = 0 ; j < 8 ; j++){
	    cin >> str;
	    tmp += str;
	}
 
	int t = 0;
	for(int j = 0 ; j < 8 ; j++)
	    for(int k = 0 ; k < 8 ; k++)
		bomb[j][k] = tmp[t++];
 
	cin >> x >> y;
 
	printData(i);
	dfs(x-1,y-1);
 
	for(int j = 0 ; j < 8 ; j++){
	    for(int k = 0 ; k < 8 ; k++){
		cout << bomb[j][k];
	    }
	    cout << endl;
	}
    }
    return 0;
}

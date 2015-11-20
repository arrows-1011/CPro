#include <iostream>
#include <cctype>
 
using namespace std;
 
#define MAX 1050
 
char S[MAX][MAX];
int K[MAX];
 
void print(int N){
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < K[i] ; j++){
	    if(S[i][j] == '.'){
		cout << " ";
	    }else{
		cout << S[i][j];
	    }
	}
	cout << endl;
    }
}
 
int main(){
    int N;
    string str;
 
    while(cin >> N,N){
	for(int i = 0 ; i < N ; i++){
	    cin >> str; K[i] = str.size();
	    for(int j = 0 ; j < K[i] ; j++){
		S[i][j] = str[j];
	    }
	}
 
	for(int i = 1 ; i < N ; i++){
	    for(int j = 0 ; j < K[i]-1 ; j++){
		if(islower(S[i][j+1])){
		    S[i][j] = '+';
		    break;
		}
	    }
	}
	for(int i = 1 ; i < N ; i++){
	    for(int j = 0 ; j < K[i] ; j++){
		if(S[i][j] == '+'){
		    for(int k = i-1 ; k > 0 ; k--){
			if(S[k][j] != '.') break;
			S[k][j] = '|';
		    }
		}
	    }
	}
	print(N);
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 101
 
int arr[MAX], W;
 
void ins(int id, int w){
    for(int i = 0 ; i < W-w+1 ; i++){
	if(arr[i] == -1){
	    bool flg = true;
	    for(int j = i ; j < i+w ; j++){
		if(arr[j] != -1){
		    flg = false;
		    break;
		}
	    }
 
	    if(flg){
		cout << i << endl;
		for(int j = i ; j < i+w ; j++){
		    arr[j] = id;
		}
		return;
	    }
	}
    }
 
    cout << "impossible" << endl;
}
 
void del(int id){
    for(int i = 0 ; i < W ; i++){
	if(arr[i] == id){
	    while(arr[i] == id){
		arr[i++] = -1;
	    }
	    return;
	}
    }
}
 
int main(){
    int Q, id, w;
    char ch;
 
    while(cin >> W >> Q ,(W | Q)){
	memset(arr,-1,sizeof(arr));
	for(int i = 0 ; i < Q ; i++){
	    cin >> ch;
 
	    if(ch == 's'){
		cin >> id >> w;
		ins(id, w);
	    }else{
		cin >> id;
		del(id);
	    }
	}
	cout << "END" << endl;
    }
    return 0;
}

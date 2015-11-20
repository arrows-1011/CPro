#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int arr[4][13], rank[9], card[5], cnt[13];
string str[5];
 
int getMark(char ch){
    if(ch == 'S'){
	return 0;
    }else if(ch == 'C'){
	return 1;
    }else if(ch == 'H'){
	return 2;
    }
    return 3;
}
 
int getNum(char ch){
    if('2' <= ch && ch <= '9'){
	return (ch-'0')-1;
    }else if(ch == 'A'){
	return 0;
    }else if(ch == 'T'){
	return 9;
    }else if(ch == 'J'){
	return 10;
    }else if(ch == 'Q'){
	return 11;
    }
    return 12;
}
 
int judge(){
    bool same_mark = true;
    char ch = str[0][1];
    for(int i = 1 ; i < 5 ; i++){
	if(ch != str[i][1]){
	    same_mark = false;
	    break;
	}
    }
 
    if(same_mark){
	if(card[0] == 1 && card[1] == 10 && card[2] == 11 &&
	   card[3] == 12 && card[4] == 13){
	    return rank[8];
	}else{
	    bool check = true;
	    for(int i = 1 ; i < 5 ; i++){
		if(card[i] - card[i-1] != 1){
		    check = false;
		    break;
		}
	    }
	    if(check){
		return rank[7];
	    }else{
		return rank[4];
	    }
	}
    }
 
    sort(cnt, cnt+13, greater<int>());
    if(cnt[0] == 4){
	return rank[6];
    }else if(cnt[0] == 3){
	if(cnt[1] == 2){
	    return rank[5];
	}else{
	    return rank[2];
	}
    }else if(cnt[0] == 2){
	if(cnt[1] == 2){
	    return rank[1];
	}else{
	    return rank[0];
	} 
    }else{
	bool check = true;
	for(int i = 1 ; i < 5 ; i++){
	    if(card[i] - card[i-1] != 1){
		check = false;
		break;
	    }
	}
	if(check){
	    return rank[3];
	}
	if(card[0] == 1 && card[1] == 10 && card[2] == 11 &&
	   card[3] == 12 && card[4] == 13){
	    return rank[3];
	}
    }
 
    return 0;
}
 
int main(){
    int N;
    bool space = false;
 
    while(cin >> N){
	if(space){
	    cout << endl;
	}else{
	    space = true;
	}
 
	for(int i = 0 ; i < 4 ; i++){
	    for(int j = 0 ; j < 13 ; j++){
		cin >> arr[i][j];
	    }
	}
	for(int i = 0 ; i < 9 ; i++){
	    cin >> rank[i];
	}
 
	while(N--){
	    int point = 0, m,n;
	    memset(cnt, 0, sizeof(cnt));
	    for(int i = 0 ; i < 5 ; i++){
		cin >> str[i];
		m = getMark(str[i][1]);
		n = getNum(str[i][0]);
		point += arr[m][n];
		card[i] = n+1;
		cnt[n]++;
	    }
	    sort(card, card+5);
	    cout << point*judge() << endl;
	}
    }
    return 0;
}

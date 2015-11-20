#include <bits/stdc++.h>
 
using namespace std;
 
int getRank(char rank){
    if(isdigit(rank)) return rank-'0';
    if(rank == 'T') return 10; 
    if(rank == 'J') return 11; 
    if(rank == 'Q') return 12; 
    if(rank == 'K') return 13; 
    if(rank == 'A') return 14; 
    return -1;
}
 
int getSuit(char suit){
    if(suit == 'C') return 0; 
    if(suit == 'H') return 1; 
    if(suit == 'D') return 2; 
    if(suit == 'S') return 3; 
    return -1;
}
 
int main(){
    char T;
    while(cin >> T, T != '#'){
	string Card;
	int Trump = getSuit(T);
	int rank[4][13],suit[4][13];
	for(int i = 0 ; i < 4 ; i++){
	    for(int j = 0 ; j < 13 ; j++){
		cin >> Card;
		rank[i][j] = getRank(Card[0]);
		suit[i][j] = getSuit(Card[1]);
	    }
	}
	int dealer = 0;
	int team[2] = {0};
	for(int turn = 0 ; turn < 13 ; turn++){
	    int winner = dealer;
	    int s = suit[dealer][turn];
	    int r = rank[dealer][turn];
	    if(s == Trump){ r += 13; }
	    for(int i = 1 ; i < 4 ; i++){
		int player = (dealer+i) % 4;
		int ns = suit[player][turn];
		int nr = rank[player][turn];
		if(ns == Trump){ nr += 13; }
		if(ns != s && ns != Trump){
		    continue;
		}
		if(r < nr){
		    r = nr;
		    winner = player;
		}
	    }
	    team[winner%2]++;
	    dealer = winner;
	}
	for(int i = 0 ; i < 2 ; i++){
	    team[i] -= 6;
	}
	if(team[0] < team[1]){
	    cout << "EW " << team[1] << endl;
	}else{
	    cout << "NS " << team[0] << endl;
	}
    }
    return 0;
}

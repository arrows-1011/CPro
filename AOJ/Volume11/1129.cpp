#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){
    int n,r,p,c;
 
    while(cin >> n >> r , n + r){
	vector<int> cards;
 
	for(int i = n ; i >= 1 ; i--){
	    cards.push_back(i);
	}
 
	while(r--){
	    cin >> p >> c;
	    vector<int> tmp;
	    for(int i = p-1 ; i < p+c-1 ; i++){
		tmp.push_back(cards[i]);
		cards[i] = -1;
	    }
    
	    for(int i = 0 ; i < cards.size() ; i++){
		if(cards[i] != -1) tmp.push_back(cards[i]);
	    }
 
	    for(int i = 0 ; i < n ; i++){
		cards[i] = tmp[i];
	    }
	}
	cout << cards[0] << endl;
    }
    return 0;
}

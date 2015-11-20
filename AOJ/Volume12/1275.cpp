#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
    int N,K,M;
    while(cin >> N >> K >> M, (N | K | M)){
	vector<int> vec;
	for(int i = 0 ; i < N ; i++){
	    vec.push_back(i+1);
	}
	vec.erase(vec.begin()+M-1);
	int cur = (K + M - 2) % vec.size();
	while(true){
	    if(vec.size() == 1) break;
	    vec.erase(vec.begin()+cur);
	    cur = (cur + K - 1) % vec.size();
	}
	cout << vec[0] << endl;
    }
    return 0;
}

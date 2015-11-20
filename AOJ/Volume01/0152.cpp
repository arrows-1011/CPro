#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
 
using namespace std;
 
typedef pair<int,int> P;
 
vector<int> Point(string s){
    stringstream ss(s);
    int num;
    vector<int> v;
 
    while(ss >> num){
	v.push_back(num);
    }
    return v;
}
 
int getScore(string s){
    vector<int> a;
    a = Point(s);
    int len = (int)a.size();
    int score = 0 , sum = 0;
    int p = 0,n = 0;
 
    for(int i = 0 ; i < len ; i++){
	if(p >= 9){
	    p++;
	    score += a[i];
	}else{
	    if(a[i] == 10 && n == 0){
		score += a[i] + a[i+1] + a[i+2];
		p++;
	    }else{
		n++;
		sum += a[i];
		if(n == 2){
		    n = 0;
		    score += sum;
		    if(sum == 10){
			score += a[i+1];
		    }
		    p++;
		    sum = 0;
		}
	    }
	}
    }
 
    return -score;
}
 
int main(){
    int m;
    while(cin >> m ,m){
	vector<P> v;
	string pin;
	for(int i = 0 ; i < m ; i++){
	    int score,num;
	    cin >> num;
 
	    getline(cin,pin);
	    score = getScore(pin);
   
	    v.push_back(P(score,num));
	}
	sort(v.begin(),v.end());
	for(int i = 0 ; i < m ; i++){
	    cout << v[i].second << " " << -v[i].first << endl;
	}
    }
    return 0;
}

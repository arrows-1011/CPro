#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
struct P{
    int year,base;
    string name;
   
    bool operator < (const P &a)const{
	if(year != a.year){
	    return year < a.year;
	}
	else{
	    return base < a.base;
	}
    }
 
    P(int y = 0,int b = 0,string s = "") : year(y),base(b),name(s){}
 
};
 
int main(){
    int N,Q,b,y;
    string str;
 
 
    while(cin >> N >> Q){
	vector<P> v;
 
	for(int i = 0 ; i < N ; i++){
	    cin >> str >> b >> y;
	    v.push_back(P(y,b,str));
	}
 
	sort(v.begin(),v.end());
 
	int in;
 
	for(int i = 0 ; i < Q ; i++){
	    bool found = false;
 
	    cin >> in;
	    for(int j = 0 ; j < N ; j++){
		if(in <= v[j].year){ 
		    if(v[j].year-v[j].base < in){
			cout << v[j].name << " " << in-(v[j].year-v[j].base) << endl;
			found = true;
			break;
		    }
		}
	    }
	    if(!found) cout << "Unknown" << endl;
	}
    }
    return 0;
}

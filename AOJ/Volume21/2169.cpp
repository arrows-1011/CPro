#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
 
using namespace std;
 
class Octahedra{
public:
    vector<int> x;
 
    Octahedra(){
	x.resize(8);
    }
   
    void rollLR(){
	int tmp = x[0];
	x[0] = x[3];
	x[3] = x[4];
	x[4] = x[1];
	x[1] = tmp;
 
	tmp = x[7];
	x[7] = x[6];
	x[6] = x[5];
	x[5] = x[2];
	x[2] = tmp;
    }
 
    void rollTF(){
	swap(x[0],x[7]);
	swap(x[1],x[2]);
	swap(x[4],x[5]);
	swap(x[3],x[6]);
    }
 
    void rollR(){
	int tmp = x[0];
	x[0] = x[7];
	x[7] = x[2];
	x[2] = x[1];
	x[1] = tmp;
     
	tmp = x[3];
	x[3] = x[6];
	x[6] = x[5];
	x[5] = x[4];
	x[4] = tmp;
    }
 
    bool equal(const Octahedra &o){
	for(int i = 0 ; i < 8 ; i++){
	    if(x[i] != o.x[i]) return false;
	}
	return true;
    }
 
    bool operator == (const Octahedra &o){
	for(int i = 0 ; i < 2 ; i++){
	    for(int j = 0 ; j < 4 ; j++){
		if(equal(o)) return true;
		rollLR();
	    }
	    rollTF();
	}
	for(int i = 0 ; i < 4 ; i++){
	    for(int j = 0 ; j < 4 ; j++){
		if(equal(o)) return true;
		rollLR();
	    }
	    rollR();
	}
	rollLR();
	for(int i = 0 ; i < 4 ; i++){
	    for(int j = 0 ; j < 4 ; j++){
		if(equal(o)) return true;
		rollLR();
	    }
	    rollR();
	}
	return false;
    }
 
    bool operator < (const Octahedra &o)const{
	for(int i = 0 ; i < 8 ; i++){
	    if(x[i] != o.x[i]){
		return x[i] < o.x[i];
	    }
	}
    }
};
 
int main(){
    map<string,int> mp;
    string s;
    while(cin >> s){
	Octahedra o;
	mp.clear(); mp[s] = 0;
	o.x[0] = 0;
	int idx = 1;
	set<Octahedra> st;
	for(int i = 0 ; i < 7 ; i++){
	    cin >> s;
	    if(mp.find(s) == mp.end()){
		mp[s] = idx++;
	    }
	    o.x[i+1] = mp[s];
	}
	sort(o.x.begin(),o.x.end());
	set<Octahedra>::iterator it;
	do{
	    bool found = false;
	    for(it = st.begin() ; it != st.end() ; ++it){
		Octahedra a = *it;
		if(a == o){
		    found = true;
		    break;
		}
	    }
	    if(!found){
		st.insert(o);
	    }
	}while(next_permutation(o.x.begin(),o.x.end()));
	cout << st.size() << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct State{
    int h, w;
 
    State(){}
    State(int h, int w) : h(h), w(w) {}
   
    int area(){
	return h*w;
    }
    int perimeter(){
	return 2*(h+w);
    }
};
 
int main(){
    int N, W, D;
 
    while(cin >> N >> W >> D, (N | W | D)){
	int p, s;
	vector<State> cakes;
	cakes.push_back(State(W,D));
	for(int i = 0 ; i < N ; i++){
	    cin >> p >> s; p--;
	    State cake = cakes[p], a, b;
	    cakes.erase(cakes.begin()+p);
	    int pos = s % (cake.perimeter()/2);
 
	    if(pos < cake.h){
		a = State(pos,cake.w);
		b = State(cake.h-pos,cake.w);
	    }else{
		pos -= cake.h;
		a = State(cake.h,pos);
		b = State(cake.h,cake.w-pos);
	    }     
	    if(a.area() < b.area()){
		cakes.push_back(a);
		cakes.push_back(b);
	    }else{
		cakes.push_back(b);
		cakes.push_back(a);
	    }
	}
	vector<int> area;
	int len = cakes.size();
	for(int i = 0 ; i < len ; i++){
	    area.push_back(cakes[i].area());
	}
	sort(area.begin(), area.end());
	for(int i = 0 ; i < len ; i++){
	    if(i != len-1) cout << area[i] << " ";
	    else cout << area[i] << endl;
	}
    }
    return 0;
}

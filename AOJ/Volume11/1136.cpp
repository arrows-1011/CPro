#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 51
 
struct Point{
    int x,y;
    double dist(const Point &p){
	return abs(x-p.x)+abs(y-p.y);
    }
};
 
int N,m[MAX];
vector<Point> lines[MAX];
 
int getDir(Point &p1,Point &p2){
    if(p1.x == p2.x){
	return (p1.y < p2.y ? 0 : 2);
    }
    return (p1.x < p2.x ? 3 : 1);
}
 
bool equals(vector<Point> &l1,vector<Point> &l2){
    int s1 = l1.size(), s2 = l2.size();
    if(s1 != s2) return false;
    bool flg = false;
    int d1,d2,diff;
    for(int i = 0 ; i < s1-1 ; i++){
	if(l1[i].dist(l1[i+1]) != l2[i].dist(l2[i+1])){
	    flg = true; break;
	}
	d1 = getDir(l1[i],l1[i+1]);
	d2 = getDir(l2[i],l2[i+1]);
	if(i > 0){
	    if(diff != (d1-d2+4)%4){
		flg = true; break;
	    }
	}else{
	    diff = (d1-d2+4)%4;
	}
    }
    if(!flg) return true;
    flg = false;
    for(int i = s1-1 ; i > 0 ; i--){
	if(l1[s1-i-1].dist(l1[s1-i]) != l2[i].dist(l2[i-1])){
	    flg = true; break;
	}
	d1 = getDir(l1[s1-i-1],l1[s1-i]);
	d2 = getDir(l2[i],l2[i-1]);
	if(i != s1-1){
	    if(diff != (d1-d2+4)%4){
		flg = true;
		break;
	    }
	}else{
	    diff = (d1-d2+4)%4;
	}
    }
    return !flg;
}
 
int main(){
    while(cin >> N,N){
	for(int i = 0 ; i <= N ; i++){
	    cin >> m[i]; lines[i].clear();
	    for(int j = 0 ; j < m[i] ; j++){
		int x,y;
		cin >> x >> y;
		lines[i].push_back((Point){x,y});
	    }
	}
	for(int i = 1 ; i <= N ; i++){
	    if(equals(lines[0],lines[i])){
		cout << i << endl;
	    }
	}
	cout << "+++++" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 200
 
struct Point{
    int x, y;
 
    bool operator < (const Point p)const{
	if(x != p.x){
	    return x < p.x;
	}else{
	    return y < p.y;
	}
    }
};
 
int n, m;
Point star[MAX], pict[MAX*5];
 
Point search(){
    Point res;
    vector<Point> v;
 
    for(int i = 0 ; i < m ; i++){
	for(int j = 0 ; j < n ; j++){
	    Point P;
	    P.x = pict[j].x - star[i].x;
	    P.y = pict[j].y - star[i].y;
	    v.push_back(P);
	}
    }
    sort(v.begin(),v.end());
 
    int cnt = 1;
    Point p = v[0];
    for(int i = 1 ; i < (int)v.size() ; i++){
	if(cnt == m){
	    res = p;
	    break;
	}
 
	if(p.x != v[i].x || p.y != v[i].y){
	    p = v[i];
	    cnt = 1;
	}else{
	    cnt++;
	}
    }
 
    return res;
}
 
int main(){
    while(cin >> m, m){
	for(int i = 0 ; i < m ; i++){
	    cin >> star[i].x >> star[i].y;
	}
 
	cin >> n;
	for(int i = 0 ; i < n ; i++){
	    cin >> pict[i].x >> pict[i].y;
	}
 
	Point p = search();
	cout << p.x << " " << p.y << endl;
    }
    return 0;
}

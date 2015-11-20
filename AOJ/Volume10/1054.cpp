#include <iostream>
#include <vector>
 
using namespace std;
 
#define MAX 110
 
struct Page{
    int sx,sy,tx,ty;
    string next;
    Page(int sx,int sy,int tx,int ty,string next)
	: sx(sx),sy(sy),tx(tx),ty(ty),next(next) {}
};
 
vector<Page> vec[MAX];
 
void init(){
    for(int i = 0 ; i < MAX ; i++){
	vec[i].clear();
    }
}
 
int main(){
    int N,W,H,b,sx,sy,tx,ty;
    string str[MAX],s;
 
    while(cin >> N,N){
	int p = 0;
	cin >> W >> H;
	init();
	for(int i = 0 ; i < N ; i++){
	    cin >> str[i] >> b;
	    for(int j = 0 ; j < b ; j++){
		cin >> sx >> sy >> tx >> ty >> s;
		vec[i].push_back(Page(sx,sy,tx,ty,s));
	    }
	}
	int m,w,h,now = 0;
	vector<int> now_page;
	now_page.push_back(now);
	string next;
	cin >> m;
	for(int I = 0 ; I < m ; I++){
	    cin >> s;
	    if(s == "click"){
		bool found = false;
		cin >> w >> h;
		for(int i = 0 ; i < vec[now_page[p]].size() ; i++){
		    sx = vec[now_page[p]][i].sx, sy = vec[now_page[p]][i].sy;
		    tx = vec[now_page[p]][i].tx, ty = vec[now_page[p]][i].ty;
		    next = vec[now_page[p]][i].next;
		    if(sx <= w && w <= tx && sy <= h && h <= ty){
			for(int j = 0 ; j < N ; j++){
			    if(str[j] == next){
				now = j;
				found = true;
				break;
			    }
			}
		    }
		    if(found){
			p++;
			while(p < now_page.size()){
			    now_page.pop_back();
			}
			now_page.push_back(now);
			break;
		    }
		}
	    }else if(s == "show"){
		cout << str[now_page[p]] << endl;
	    }else if(s == "back"){
		if(p > 0) p--;
	    }else{
		if(p+1 < now_page.size()) p++;
	    }
	}
    }
    return 0;
}

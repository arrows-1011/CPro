#include <cstdio>
#include <set>
#include <vector>
 
using namespace std;
 
int main(){
    int n;
 
    while(scanf("%d" ,&n) ,n){
	int MAX = (n-1) / 2;
	int cnt[MAX];
	fill(cnt,cnt+MAX,0);
 
	set<int> s;
	for(int i = 1 ; i < n ; i++){
	    int num = i * i % n;
	    if(!s.count(num)){
		s.insert(num);
	    }
	}
 
	set<int>::iterator it;
	vector<int> v;
	for(it = s.begin() ; it != s.end() ; it++){
	    v.push_back(*it);
	}
	int len = (int)v.size();
	for(int i = 0 ; i < len ; i++){
	    for(int j = 0 ; j < len ; j++){
		if(i == j) continue;
		int diff = v[i] - v[j];
 
		if(diff < 0){
		    diff += n;
		}
		if(diff > MAX){
		    diff -= n;
		}
 
		cnt[diff-1]++;
	    }
	}
	for(int i = 0 ; i < MAX ; i++){
	    printf("%d\n" ,cnt[i]*2);
	}
    }
    return 0;
}

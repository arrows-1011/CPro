#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100000
 
int main(){
    int N, K, in;
 
    while(scanf("%d%d" ,&N ,&K), (N | K)){
	bool found = false, used[MAX+2];
	vector<int> vec;
	int start = MAX;
 
	memset(used,false,sizeof(used));
 
	for(int i = 0 ; i < K ; i++){
	    scanf("%d" ,&in);
      
	    if(in){
		start = min(start, in);
		used[in] = true;
		vec.push_back(in);
	    }else{
		found = true;
	    }
	}
 
	int res = 1;
	if(found){
	    start--;
	    int cnt = 0, pos, p = 0;
	    for(int i = start ; i <= N+1 ; i++){
		if(used[i]){
		    cnt++;
		}else{
		    p++;
		    if(p == 1){
			pos = i + 1;
			if(i != 0 || i != N+1){
			    cnt++;
			}
		    }
		    if(i == 0) continue;
		    if(p == 2){
			res = max(res,cnt);
			p = 1;
			cnt = i - pos + 1;
			pos = i + 1;
		    }
		}
 
	    }
	}else{
	    sort(vec.begin(),vec.end());
	    int cnt = 0;
	    for(int i = 1 ; i < K ; i++){
		if(vec[i] - vec[i-1] == 1){
		    cnt++;
		    res = max(res,cnt);
		}else{
		    cnt = 1;
		}
	    }
	}
	printf("%d\n" ,res);
    }
    return 0;
}

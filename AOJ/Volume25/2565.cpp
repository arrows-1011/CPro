#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1002
#define INF 1e9+1
 
int main(){
    int N,arr[MAX];
    string str;
    while(cin >> N, N){
	bool x[MAX] = {false};
	arr[0] = INT_MAX;
	arr[N+1] = (N % 2 ? INT_MAX : INT_MIN);  
	bool can = true;
	for(int i = 1 ; i <= N ; i++){
	    cin >> str;
	    if(str[0] == 'x'){
		x[i] = true;
		arr[i] = INT_MAX;
	    }else{
		stringstream ss(str);
		int x; ss >> x;
		arr[i] = x;
	    }
	    if(i > 0){
		if(x[i-1] && x[i]){
		    can = false;
		}
	    }
	}
	if(!can){
	    cout << "none" << endl;
	    continue;
	}else if(count(x+1,x+N+1,true) == 0){
	    bool check = false;
	    for(int i = 1 ; i <= N ; i++){
		if(i % 2){
		    if(!(arr[i-1] > arr[i] && arr[i+1] > arr[i])){
			check = true;
			break;
		    }
		}else{
		    if(!(arr[i-1] < arr[i] && arr[i+1] < arr[i])){
			check = true;
			break;
		    }
		}
	    }
	    cout << (check ? "none" : "ambiguous") << endl;
	    continue;
	}
	for(int i = 1 ; i <= N ; i++){
	    if(x[i]) continue;
	    if(i % 2){
		if(!x[i-1] && !x[i]){
		    if(!(arr[i-1] > arr[i])){
			can = false;
			break;
		    }
		}
		if(!x[i] && !x[i+1]){
		    if(!(arr[i+1] > arr[i])){
			can = false;
			break;
		    }
		}
	    }else{
		if(!x[i-1] && !x[i]){
		    if(!(arr[i-1] < arr[i])){
			can = false;
			break;
		    }
		}
		if(!x[i] && !x[i+1]){
		    if(!(arr[i+1] < arr[i])){
			can = false;
			break;
		    }
		}
	    }
	}
	if(!can){
	    cout << "none" << endl;
	    continue;
	}
	bool found = false;
	int l = -1e9-2,r = 1e9+2, m,ans;
	while(r - l >= 0){
	    m = (l + r) / 2;
	    bool small = false, large = false;
	    for(int i = 1 ; i <= N ; i++){
		int bv = (x[i-1] ? m : arr[i-1]);
		int cv = (x[i] ? m : arr[i]);
		int nv = (x[i+1] ? m : arr[i+1]);
		if(!x[i]) continue;
		if(i % 2){
		    if(!(bv > cv && nv > cv)){
			small = true;
			break;
		    }
		}else{
		    if(!(bv < cv && nv < cv)){
			large = true;
			break;
		    }
		}
	    }
	    if(!small && !large){
		found = true;
		break;
	    }else if(small){
		r = m-1;
	    }else{
		l = m+1;
	    }
	}
   
	if(!found){
	    cout << "none" << endl;
	}else{
	    found = false;
	    ans = m;
	    l = -1e9-5, r = ans-1;
	    while(r - l > 0){
		m = (l + r) / 2;
		bool small = false, large = false;
		for(int i = 1 ; i <= N ; i++){
		    int bv = (x[i-1] ? m : arr[i-1]);
		    int cv = (x[i] ? m : arr[i]);
		    int nv = (x[i+1] ? m : arr[i+1]);
		    if(!x[i]) continue;
		    if(i % 2){
			if(!(bv > cv && nv > cv)){
			    small = true;
			    break;
			}
		    }else{
			if(!(bv < cv && nv < cv)){
			    large = true;
			    break;
			}
		    }
		}
		if(!small && !large){
		    found = true;
		    break;
		}else if(small){
		    r = m-1;
		}else{
		    l = m+1;
		}
	    }
	    l = ans+1, r = 1e9+5;
	    while(r - l > 0){
		m = (l + r) / 2;
		bool small = false, large = false;
		for(int i = 1 ; i <= N ; i++){
		    int bv = (x[i-1] ? m : arr[i-1]);
		    int cv = (x[i] ? m : arr[i]);
		    int nv = (x[i+1] ? m : arr[i+1]);
		    if(!x[i]) continue;
		    if(i % 2){
			if(!(bv > cv && nv > cv)){
			    small = true;
			    break;
			}
		    }else{
			if(!(bv < cv && nv < cv)){
			    large = true;
			    break;
			}
		    }
		}
		if(!small && !large){
		    found = true;
		    break;
		}else if(small){
		    r = m-1;
		}else{
		    l = m+1;
		}
	    }
	    if(found){
		cout << "ambiguous" << endl;
	    }else{
		cout << ans << endl;
	    }
	}
    }
    return 0;
}

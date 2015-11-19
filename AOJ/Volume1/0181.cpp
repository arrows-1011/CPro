#include <iostream>
 
using namespace std;
 
#define MAX 100
 
int book[MAX],m,n;
 
bool check(int limit){
    int cnt = 0, sum = 0;
 
    for(int i = 0 ; i < n ; i++){
	if(book[i] > limit){
	    return false;
	}
 
	sum += book[i];
	if(sum == limit){
	    sum = 0;
	    cnt++;
	}else if(sum > limit){
	    sum = book[i];
	    cnt++;
	}
    }
 
    if(sum > 0){
	cnt++;
    }
 
    return cnt <= m;
}
 
int main(){
    while(cin >> m >> n, (m|n)){
	for(int i = 0 ; i < n ; i++){
	    cin >> book[i];
	}
 
	int lb = 0, ub = 1500000;
	while(ub - lb > 0){
	    int mid = (lb + ub) / 2;
 
	    if(check(mid)){
		ub = mid;
	    }else{
		lb = mid + 1;
	    }
	}
	cout << ub << endl;
    }
    return 0;
}

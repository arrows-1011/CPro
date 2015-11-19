#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
vector<int> ans;
int arr[13];
int cnt[10];
 
bool judge(int a[]){
    int sum = 0;
    for(int i = 1 ; i <= 9 ; i++){
	sum += a[i];
    }
    if(sum == 0) return true;
    for(int i = 3 ; i <= 9 ; i++){
	if(a[i-2] > 0 && a[i-1] > 0 && a[i] > 0){
	    a[i-2]--; a[i-1]--; a[i]--;
	    if(judge(a)) return true;
	    a[i-2]++; a[i-1]++; a[i]++;
	}
    }
 
    for(int i = 1 ; i <= 9 ; i++){
	if(a[i] >= 3){
	    a[i] -= 3;
	    if(judge(a)) return true;
	    a[i] += 3;
	}
    }
 
    return false;
}
 
void solve(){
    int tmp[10];
    for(int i = 0 ; i < 9 ; i++){
	for(int j = 0 ; j < 10 ; j++){
	    tmp[j] = cnt[j];
	}
	if(cnt[i+1] > 3) continue;
	cnt[i+1]++;
	for(int j = 1 ; j <= 9 ; j++){
	    if(cnt[j] >= 2) cnt[j]-=2;
	    else continue;
	    if(judge(cnt)){
		ans.push_back(i+1);
		break;
	    }
	    cnt[j] += 2;
	}
	for(int j = 0 ; j < 10 ; j++){
	    cnt[j] = tmp[j];
	}
    }
}
 
int main(){
    string str;
    while(cin >> str){
	memset(cnt,0,sizeof(cnt));
	for(int i = 0 ; i < 13 ; i++){
	    arr[i] = str[i]-'0';
	    cnt[arr[i]]++;
	}
	sort(arr, arr+13);
	ans.clear();
	solve();
	int size = ans.size();
	if(!size){
	    cout << 0 << endl;
	}else{
	    for(int i = 0 ; i < size ; i++){
		if(i == 0) cout << ans[i];
		else cout << " " << ans[i];
	    }
	    cout << endl;
	}
    }
 
    return 0;
}

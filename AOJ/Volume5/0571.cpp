#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100000
 
int main(){
    string str;
    int cnt[3];
   
    cin >> str;
 
    int ans = 0, size = str.size();
    const char JOI[3] = {'J','O','I'};
 
    for(int i = 0 ; i < size ; i++){
	if(str[i] == 'J'){
	    memset(cnt,0,sizeof(cnt));
	    for(int j = 0 ; j < 3 ; j++){
		while(i != size && JOI[j] == str[i]){
		    cnt[j]++; i++;
		}
	    } 
	    i--;
	    if(cnt[0] < cnt[1]) continue;
	    if(cnt[1] > cnt[2]) continue;
	    ans = max(ans, *min_element(cnt, cnt + 3));  
	}
 
    }
    cout << ans << endl;
    return 0;
}

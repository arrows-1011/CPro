#include <iostream>

using namespace std;

const int MAX = 100002;
 
int main(){
    int n,ans[MAX],a,b;
 
    fill(ans,ans+MAX,0);
 
    cin >> n;
    while(n--){
	cin >> a >> b;
	ans[a]++; ans[b+1]--;
    }
 
    for(int i = 1 ; i < MAX ; i++)
	ans[i] += ans[i-1];
 
    int fri = 0;
    for(int i = 1 ; i < MAX ; i++){
	if(ans[i]+1 >= i) fri = i-1; 
    }
    cout << fri << endl;
    return 0;
}

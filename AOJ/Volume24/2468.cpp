#include <cstdio>
#include <set>
 
using namespace std;
 
int main(){
    int a[100000],n,m;
 
    scanf("%d %d" ,&n ,&m);
    for(int i = 0 ; i < n ; i++){
	scanf("%d" ,&a[i]);
    }
 
    set<int> st;
    int cnt = 0;
    for(int i = n-1 ; i >= 0 ; i--){
	if(cnt == m) break;
	if(!st.count(a[i])){
	    cnt++;
	    st.insert(a[i]);
	    printf("%d\n" ,a[i]);
	}
    }
    return 0;
}

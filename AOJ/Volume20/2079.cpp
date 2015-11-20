#include <cstdio>
#include <cstring>
 
using namespace std;
 
#define MAX 100000
 
int main(){
    int n;
    char str[MAX+1];
 
    scanf("%d" ,&n);
    while(n--){
	bool ok = true;
	scanf("%s" ,str);
	int len = (int)strlen(str);
	for(int i = 1 ; i < len ; i++){
	    if(str[i] == str[i-1]){
		ok = false;
		break;
	    }
	}
	printf("%s\n" , ok ? "Yes" : "No");
    }
 
    return 0;
}

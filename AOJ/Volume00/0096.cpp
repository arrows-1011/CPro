#include <iostream>

using namespace std;
 
#define MAX 4000
int num[MAX+1],cnt[MAX/2+1];
 
void make(){
    for(int i = 0 ; i <= MAX ; i++) num[i] = 0;
    for(int j = 0 ; j <= MAX/2 ; j++) cnt[j] = 0;
     
    for(int i = 0 ; i <= MAX/4 ; i++){
        for(int j = 0 ; j <= MAX/4 ; j++){
            ++cnt[i+j];
	}
    }
     
    for(int i = 0 ; i <= MAX/2 ; i++){
        for(int j = 0 ; j <= MAX/2 ; j++){
            num[i+j] += cnt[i] * cnt[j];
	}
    }
}
 
int main(){
    int n;
    make(); 
    while(cin >> n){
	cout << num[n] << endl;
    }
    return 0;
}

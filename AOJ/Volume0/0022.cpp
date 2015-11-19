#include <iostream>

using namespace std;

#define MAX 5000
 
int main(){
    int n,a[MAX];     
    while(cin >> n,n){
        for(int i = 0 ; i < n ; i++){
	    cin >> a[i];
	}
        int max = a[0];
        for(int i = 0 ; i < n ; i++){
            int tmp = 0;
            for(int j = i ; j < n ; j++){
                tmp += a[j];
                if(max < tmp) max = tmp;
            }
        }
        cout << max << endl;
    }
    return 0;
}

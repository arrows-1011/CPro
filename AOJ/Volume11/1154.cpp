#include <iostream>
#include <vector>

using namespace std;

#define MAX 300001
 
bool check[MAX];
 
void print(int n){
    cout << n << ": ";
}
 
void init(){
    fill(check,check+MAX,false);
}
 
int main(){
    int n;
     
    while(cin >> n , n != 1){
        vector<int> v;
        init();
        print(n);
         
        for(int i = 2 ; i <= n ; i++){
            if(n%i==0&&(i%7==1||i%7==6)){
		for(int j = 2*i ; j <= n ; j+=i) check[j] = true;
		if(!check[i]) v.push_back(i);
            }
        }
        for(int i = 0 ; i < v.size() ; i++){
            if(!i) cout << v[i];
            else cout << ' ' << v[i];
        }
        cout << endl;
    }
    return 0;
}

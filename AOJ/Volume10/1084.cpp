#include <iostream>
#include <vector>
 
using namespace std;
 
int getPoint(int n,int k,vector<int> &v){
    int res = 0;
    for(int i = 0 ; i < n ; i++){
	if(i+k > n) break;
	int mul = 1;
	for(int j = i ; j < i+k ; j++){
	    mul *= v[j];
	}
	res = max(res,mul);
    }
    return res;
}
 
int main(){
    int n,k;
    while(true){
	cin >> n >> k;
	if(n == 0 && k == 0) break;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
	    cin >> v[i];
	}
	int Cb = getPoint(n,k,v),Ca = 0;
	for(int i = 0 ; i < n ; i++){
	    for(int j = i+1 ; j < n ; j++){
		swap(v[i],v[j]);
		Ca = max(Ca,getPoint(n,k,v));
		swap(v[i],v[j]);
	    }
	}
	if(Ca-Cb < 0){
	    cout << "NO GAME" << endl;
	}else{
	    cout << Ca-Cb << endl;
	}
    }
    return 0;
}

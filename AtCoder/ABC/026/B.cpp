#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N;
    cin >> N;
    vector<double> v(N);
    for(int i = 0 ; i < N ; i++){
	cin >> v[i];
    }
    sort(v.begin(),v.end(),greater<double>());
    double res = 0;
    for(int i = 0 ; i < v.size() ; i++){
	if(i & 1){
	    res -= v[i]*v[i];
	}else{
	    res += v[i]*v[i];
	}
    }
    printf("%.10f\n",res*M_PI);
    return 0;
}

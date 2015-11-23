#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N;
    cin >> N;
    vector<double> x(N),y(N);
    for(int i = 0 ; i < N ; i++){
	cin >> x[i] >> y[i];
    }
    double res = 0;
    for(int i = 0 ; i < N ; i++){
	for(int j = i+1 ; j < N ; j++){
	    res = max(res,sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)));
	}
    }
    printf("%.10f\n",res);
    return 0;
}

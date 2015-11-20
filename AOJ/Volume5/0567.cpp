#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10000
 
int main(){
    int n;
    double a,b,c,d[MAX+1];
     
    cin >> n >> a >> b >> c;
    for(int i = 0 ; i < n ; i++){
        cin >> d[i];
    }
    sort(d,d+n);
     
    int k = 1;
    double max;
    max = (d[n-1]+c)/(a+k*b);
    for(int i = n - 1 ;i > 1; i--){
        double sum = d[i];
        for(int j = i-1 ; j > 0 ; j--){
            if(max < (c+sum+d[j])/(a+(k+1)*b)){
                k++;
                sum += d[j];
                max = (c+sum)/(a+k*b);
            }
            else goto end;
        }
    }
end:
    int ans = (int)max;
    cout << ans << endl;
    return 0;
}

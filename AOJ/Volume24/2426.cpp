#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 5010
typedef pair<int,int> pii;
 
int s[MAX][MAX];
 
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(n),y(n);
    vector<int> X,Y;
    for(int i = 0 ; i < n ; i++){
        cin >> x[i] >> y[i];
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }
    X.push_back(INT_MIN);
    Y.push_back(INT_MIN);
     
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    for(int i = 0 ; i < n ; i++){
        int px = lower_bound(X.begin(),X.end(),x[i]) - X.begin();
        int py = lower_bound(Y.begin(),Y.end(),y[i]) - Y.begin();
        s[px][py]++;
    }
    for(int i = 1 ; i < MAX ; i++){
        for(int j = 1 ; j < MAX ; j++){
            s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    while(m--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = lower_bound(X.begin(),X.end(),x1) - X.begin();
        y1 = lower_bound(Y.begin(),Y.end(),y1) - Y.begin();
        x2 = upper_bound(X.begin(),X.end(),x2) - X.begin() - 1;
        y2 = upper_bound(Y.begin(),Y.end(),y2) - Y.begin() - 1;
        cout << s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1] << endl;
    }
    return 0;
}

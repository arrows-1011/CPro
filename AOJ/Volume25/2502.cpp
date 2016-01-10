#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,M,x;
    cin >> N;
    int s[N],l[N],p[N];
    for(int i = 0 ; i < N ; i++){
        cin >> s[i] >> l[i] >> p[i];
    }
    int dp[500] = {0};
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 500 ; j++){
            for(int k = s[i] ; k <= l[i] ; k++){
                if(j + k >= 500) continue;
                dp[j+k] = max(dp[j+k],dp[j]+p[i]);
            }   
        }
    }
    cin >> M;
    vector<int> res(M);
    bool check = 0;
    for(int i = 0 ; i < M ; i++){
        cin >> x;
        res[i] = dp[x];
        if(res[i] == 0) check = 1;
    }
    if(check){
        cout << -1 << endl;
    }else{
        for(auto v : res){
            cout << v << endl;
        }
    }   
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){
    int n,m,c;
     
    while(cin >> n >> m){
        vector<int> A,B,C;
        for(int i = n-1 ; i >= 0 ; i--){
            A.push_back(i);
        }
         
        bool flg = false;
        while(m--){
            if(flg){
                A.clear();
                for(int i = 0 ; i < C.size() ; i++){
                    A.push_back(C[i]);
                }
                reverse(A.begin(),A.end());
                B.clear();
                C.clear();
            }
             
            int s = A.size()-1;
            for(int i = s ; i >= s-n/2+1 ; i--){
                B.push_back(A[i]);
                A.pop_back();
            }
            reverse(B.begin(),B.end());
             
            int cnt = 0;
            cin >> c;
            while(C.size() != n){
                if(cnt%2==0){
                    int s = A.size()-1;
                    for(int i = s ; i >= s-c+1 ; i--){
                        if(i < 0) break;
                        C.push_back(A[i]);
                        A.pop_back();
                    }
                }
                else{
                    int s = B.size()-1;
                    for(int i = s ; i >= s-c+1 ; i--){
                        if(i < 0) break;
                        C.push_back(B[i]);
                        B.pop_back();
                    }
                }
                cnt++;
            }
             
            flg = true;
        }
        reverse(C.begin(),C.end());
        cout << C[0] << endl;
    }     
    return 0;
}

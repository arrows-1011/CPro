#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
vector<int> I,C,T;
 
bool check(){
    for(int i = 0 ; i < I.size() ; i++){
        for(int j = 0 ; j < C.size() ; j++){
            for(int k = 0 ; k < T.size() ; k++){
                if(I[i] < C[j] && C[j] < T[k]){
                    return true;
                }
            }
        }
    }
    return false;
}
 
int main(){
    string S;
  
    cin >> S;
    for(int i = 0 ; i < S.size() ; i++){
        if(S[i] == 'I' || S[i] == 'i'){
            I.push_back(i);
        }else if(S[i] == 'C' || S[i] == 'c'){
            C.push_back(i);
        }else if(S[i] == 'T' || S[i] == 't'){
            T.push_back(i);
        }
    }
 
    if(!I.size() || !C.size() || !T.size()){
        cout << "NO" << endl;
    }else{
        if(check()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
 
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
 
int T,card[10];
string str;
 
bool check1(int a,int b,int c){
    if(a == b && b == c) return true;
    return false;
}
 
bool check2(int a,int b,int c){
    if(a+2 == b+1 && b+1 == c) return true;
    return false;
}
 
bool check3(int a,int b,int c){
    return check1(a,b,c) || check2(a,b,c);
}
 
bool check4(int card[10]){
    return check3(card[0],card[1],card[2])&&check3(card[3],card[4],card[5])
	&&check3(card[6],card[7],card[8]);
}
 
int judge(){
    sort(card,card+9);
    do{
        if(check4(card)) return 1;
         
    }while(next_permutation(card,card+9));
    return 0;
}
 
int main(){
    cin >> T;
    while(T--){
        for(int i = 0 ; i < 9 ; i++){
            cin >> card[i];
        }
        for(int i = 0 ; i < 9 ; i++){
            cin >> str;
            if(str == "G") card[i] += 10;
            else if(str == "B") card[i] += 20;
        }
        cout << judge() << endl;
    }
 
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
 
int main(){
    string str;
    int n;
     
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int max=0,min=0;
        int tmp_max[8],tmp_min[8];
         
        cin >> str;
        for(int i = 0 ; i < 8 ; i++) tmp_min[i] = str[i] - '0';
         
        sort(tmp_min,tmp_min+8);
         
        for(int i = 0 ; i < 8 ; i++) tmp_max[i] = tmp_min[7-i];
         
        int num = 10000000;
        for(int i = 0 ; i < 8 ; i++){
            max += tmp_max[i] * num;
            min += tmp_min[i] * num;
            num /= 10;
        }    
        cout << max - min << endl;
    }
    return 0;
}

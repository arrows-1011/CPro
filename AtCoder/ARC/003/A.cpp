#include <bits/stdc++.h>
 
using namespace std;
 
int getValue(char x){
    return (x != 'F' ? x-'A' : 4);
}
 
int main(){
    int N,grade[5] = {0};
    char x;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> x;
	grade[getValue(x)]++;
    }
    double total = 0,sum = 0;
    for(int i = 0 ; i < 5 ; i++){
	total += grade[i];
	sum += (4-i)*grade[i];
    }
    printf("%.10f\n",sum/total);
    return 0;
}

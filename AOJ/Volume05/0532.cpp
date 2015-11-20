#include <iostream>

using namespace std;

struct data{
    int fh; int fm; int fs;
    int eh; int em; int es;
    int dh; int dm; int ds;
} n;

int main(){
    for(int i = 0 ; i < 3 ; i++){
	cin >> n.fh >> n.fm >> n.fs >> n.eh >> n.em >> n.es;
        n.dh = n.eh - n.fh;
        n.dm = n.em - n.fm;
        n.ds = n.es - n.fs;
         
        if(n.ds < 0){
            n.ds += 60;
            n.dm--;
        }
        if(n.dm < 0){
            n.dm += 60;
            n.dh--;
        }    
        cout << n.dh << ' ' << n.dm << ' ' << n.ds << endl;
    }
    return 0;
}

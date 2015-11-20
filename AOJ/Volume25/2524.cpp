#include <iostream>
#include <cstdlib>

using namespace std;
 
int cnt;
string l,r;
 
void check(){
    int x = atoi(l.c_str()) ,y = atoi(r.c_str());
    if(l.size() > r.size() || x > y || l[0] == '0' || r[0] == '0') return;  
    if((x + y) % 2 == 0 || (x - y) % 2 == 0) cnt++;
}
 
int main(){
    string a;
 
    cin >> a;
    int size = a.size();
    int z = atoi(a.c_str());
 
    if(z % 2 == 0) cnt++;
 
    for(int i = 1 ; i < size ; i++){
	l = a.substr(0,i);
	r = a.substr(i);
	check();
    }
    cout << cnt << endl;
    return 0;
}

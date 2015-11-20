#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int n;
    string str;
 
    while(cin >> n ,n){
	int field = 0 ,p[11] = {0};
	cin >> str;
	int size = str.size() ,t = 0;
	for(int i = 0 ; i < size ; i++){
	    switch(str[i]){
	    case 'M':
		++p[t++];
		break;
	    case 'S':
		field += ++p[t];
		p[t++] = 0;
		break;
	    case 'L':
		p[t++] += ++field;
		field = 0;
		break;
	    }
	    if(t == n) t = 0;
	}
	sort(p,p+n);
	for(int i = 0 ; i < n ; i++){
	    cout << p[i] << " ";
	}
	cout << field << endl;
    }
    return 0;
}

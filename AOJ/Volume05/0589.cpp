#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int,string> P;
 
int main(){
    int n,num;
    string str;
    map<P,int> m;
     
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> str >> num;
        m[P(str.size(),str)] += num;
    }     
    map<P,int>::iterator it;
    for(it = m.begin() ; it != m.end() ; it++){
        cout << it->first.second << ' ' << it->second << endl;
    }
    return 0;
}

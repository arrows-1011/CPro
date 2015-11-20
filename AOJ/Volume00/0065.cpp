#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
 
int main(){
    string str;
    map<int,int> bm,am;
    int num,day;
    char ch;
     
    while(getline(cin,str)&&str.size() > 0){
        stringstream s1(str);
        s1 >> num >> ch >> day;
        ++bm[num];
    }
    while(getline(cin,str)){
        stringstream s2(str);
        s2 >> num >> ch >> day;
        ++am[num];
    }
    for(map<int,int>::iterator it = bm.begin() ; it != bm.end() ; ++it){
        if(am[(*it).first]){
            cout << (*it).first << " " << (*it).second+am[(*it).first] << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <map>

using namespace std;
 
map<string,int> m;
 
void change(){
    m["11"] = 'a'; m["12"] = 'b'; m["13"] = 'c'; m["14"] = 'd'; m["15"] = 'e';
    m["21"] = 'f'; m["22"] = 'g'; m["23"] = 'h'; m["24"] = 'i'; m["25"] = 'j';
    m["31"] = 'k'; m["32"] = 'l'; m["33"] = 'm'; m["34"] = 'n'; m["35"] = 'o';
    m["41"] = 'p'; m["42"] = 'q'; m["43"] = 'r'; m["44"] = 's'; m["45"] = 't';
    m["51"] = 'u'; m["52"] = 'v'; m["53"] = 'w'; m["54"] = 'x'; m["55"] = 'y';
    m["61"] = 'z'; m["62"] = '.'; m["63"] = '?'; m["64"] = '!'; m["65"] = ' ';
}
 
bool judge(string s){
    if(s.size()%2==1) return false;
     
    for(int i = 0 ; i < s.size(); i++){
        if(i%2==1 && !('1' <= s[i] && s[i] <='5')) return false;
        if(i%2==0 && !('1' <= s[i] && s[i] <= '6')) return false;
    }
    return true;
}
 
int main(){
    string str;
     
    change();
     
    while(cin >> str){
        if(!judge(str)) cout << "NA" << endl;
        else{
            string ans = "";
            for(int i = 0 ; i < str.size() ; i++){
                string k = str.substr(i,2);
                if(i%2==0){
                    ans += m[k];
                }
            }
            cout << ans << endl;
        }
    }
     
    return 0;
}

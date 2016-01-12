#include <iostream>
#include <map>
#include <set>
 
using namespace std;

class Parse
{
  public:
    string::iterator it;
    map<char, set<int>> elements;
 
    Parse(string::iterator it, map<char, set<int>> elements) :
        it(it), elements(elements) {}
     
    set<int> term()
    {
        set<int> a;
        if(*it == '('){
            ++it;
            a = expr();
            ++it;
        }else if(*it == 'c'){
            ++it;
            a = term();
            a = complement(a);
        }else{
            a = elements[*it];
            ++it;
        }
        return a;
    }
     
    set<int> expr()
    {
        set<int> a = term(), b;
        while(*it == 'd' ||
              *it == 'i' ||
              *it == 's' ||
              *it == 'u')
        {
            char ch = *it; ++it;
            b = term();
            switch(ch)
            {
                case 'd':
                    a = difference(a, b);
                    break;
                case 'i':
                    a = intersection(a, b);
                    break;
                case 's':
                    a = sym_difference(a, b);
                    break;
                case 'u':
                    a = union_(a, b);
                    break;
            }
        }
        return a;
    }
 
    set<int> complement(const set<int> a)
    {
        return difference(elements['U'], a);
    }
     
    set<int> difference(const set<int> a, const set<int> b)
    {
        set<int> res;
        for(auto x : elements['U']){
            if(a.count(x) > 0 and b.count(x) == 0){
                res.insert(x);
            }
        }
        return res;
    }
 
    set<int> intersection(const set<int> a, const set<int> b)
    {
        set<int> res;
        for(auto x : elements['U']){
            if(a.count(x) > 0 and b.count(x) > 0){
                res.insert(x);
            }
        }            
        return res;
    }
 
    set<int> sym_difference(const set<int> a, const set<int> b)
    {
        return (union_(difference(a, b), difference(b, a)));
    }
 
    set<int> union_(const set<int> a, const set<int> b)
    {
        set<int> res;
        for(auto x : elements['U']){
            if(a.count(x) > 0 or b.count(x) > 0){
                res.insert(x);
            }
        }            
        return res;
    }
};
 
int main()
{
    char ch;
    int N, x;
    while(cin >> ch >> N)
    {
        map<char, set<int>> elements = {};
        set<int> U = {};
        do{
            if(ch == 'R') break;
            set<int> st;
            for(int i = 0 ; i < N ; i++){
                cin >> x;
                st.insert(x);
                U.insert(x);
            }                    
            elements[ch] = st;
        }while(cin >> ch >> N);
 
        elements['U'] = U;
         
        string str;
        cin >> str;
         
        Parse parse(str.begin(), elements);
        set<int> res = parse.expr();
         
        if(res.size() == 0){
            cout << "NULL" << endl;
        }else{
            bool sp = 0;
            for(auto r : res){
                if(sp) cout << " ";
                sp = 1;
                cout << r;
            }
            cout << endl;
        }
    }
    return 0;
}

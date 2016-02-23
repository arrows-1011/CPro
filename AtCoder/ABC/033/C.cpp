#include <iostream>

using namespace std;

int cnt = 0;

class Calc
{
    string s;
    string::iterator it;
 
  public:
    Calc (const string &str) {
	s = str;
	it = s.begin();
    }
 
    int fact()
    {
        if (*it == '0') {
            ++it;
            return 0;
        } else {
            ++it;
            return 1;
        }
    }
 
    int term()
    {
	int ret = fact();
        
	while (*it == '*') {
            ++it;
            ret *= fact();
	}
        
	return ret;
    }
   
    int exp()
    {
	int ret = term();        
        if (ret != 0) {
            cnt++;
        }
        
	while (*it == '+') {
            ++it;
            int v = term();
            if (v != 0) {
                cnt++;
            }
            ret += v;
	}               
	return ret;
    }
};

void solve(string S)
{
    Calc c(S);
    c.exp();
    cout << cnt << endl;    
}

int main()
{
    string S;
    cin >> S;
    solve(S);
    return 0;
}

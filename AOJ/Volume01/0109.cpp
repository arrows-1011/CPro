#include <bits/stdc++.h>
 
using namespace std;
 
class Calc{
public:
    string s;
    string::iterator it;
   
    Calc(string s) : s(s) {
	it = s.begin();
    }
   
    int fact()
    {
	int res = 0;
	if (*it == '(') {
	    ++it;
	    res = exp();
	    ++it;
	} else {
	    while (isdigit(*it)) {
		res *= 10;
		res += (*it-'0');
		++it;
	    }
	}
	return res;
    }
   
    int term()
    {
	int res = fact();
	while (*it == '*' || *it == '/') {
	    if (*it == '*') {
		++it;
		res *= fact();
	    } else {
		++it;
		res /= fact();
	    }
	}
	return res;
    }
 
    int exp()
    {
	int res = term();
	while (*it == '+' || *it == '-') {
	    if (*it == '+') {
		++it;
		res += term();
	    } else {
		++it;
		res -= term();
	    }
	}
	return res;
    }
};
 
int main()
{
    int N;
    cin >> N;
    while (N--) {
	string s;
	cin >> s;
	s.resize(s.size()-1);
	Calc calc(s);
	cout << calc.exp() << endl;
    }
    return 0;
}

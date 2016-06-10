#include <bits/stdc++.h>

using namespace std;
  
stack<double> s;
  
double calc(string str)
{
    double x = s.top();
    s.pop();
    double y = s.top();
    s.pop();
      
    switch (str[0]) {
        case '+':
            return x + y;
        case '-':
            return y - x;
        case '*':
            return x * y;
    }
    return y / x;
}
  
void solve()
{
    string str, a;
      
    while (getline(cin, str)) {
	stringstream ss(str);
	while (ss >> a) {
	    if (a == "+" || a == "-" || a == "*" || a == "/") {
		s.push(calc(a));
	    }
	    else{
		s.push(atof(a.c_str()));    
	    }
	}
	printf("%.6f\n" ,s.top());
    }
}
 
int main()
{
    solve();
    return 0;
}

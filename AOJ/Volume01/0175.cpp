#include <iostream>
#include <algorithm>

using namespace std;
 
int main()
{
    int n;
    string str;
    while (cin >> n , n != -1) {
	str = "";
	if (!n) cout << '0' << endl;
	else {
	    while (n) {
		str += n % 4 + '0';
		n /= 4;
	    }
	    reverse(str.begin(), str.end());
	    cout << str << endl;
	}
    }
    return 0;
}

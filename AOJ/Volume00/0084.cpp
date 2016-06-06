#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    string str;
     
    getline(cin, str);
     
    int cnt = 0, flg = 0;
    string key = "";
    for (int i = 0; i < (int)str.size(); i++) {
        cnt++;
         
        if (str[i] == ' '|| str[i] == ',' || str[i] == '.') {
            if (3 <= cnt-1 && cnt-1 <= 6) {
                if (!flg) {
                    cout << key;
                    flg = 1;
                } else {
                    cout << ' ' << key;
                }
            }
            cnt = 0;
            key = "";
        } else {
            key += str[i];
        }
    }
    cout << endl;     
    return 0;
}

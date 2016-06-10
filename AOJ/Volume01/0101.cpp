#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    string str;
    int n;
     
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, str);
        for (int j = 0; j < (int)str.size(); j++) {
            string key = str.substr(j, 7), repl;
            if (key == "Hoshino") {
                repl = "Hoshina";
                for (int k = 0; k < 7; k++) {
                    str[j+k] = repl[k];
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}

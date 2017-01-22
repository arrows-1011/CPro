#include <iostream>
 
using namespace std;
 
void find_sound(string& s)
{
    const string pat = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW"; 
    int idx = 0;
    const string sound[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
    for (int i = 0; i < (int)pat.size(); i++) {
        if (pat.substr(i, 20) == s) {            
            cout << sound[idx] << endl;
            return;
        }
        idx += (pat[i] == 'W');
    }
}
 
int main()
{
    string s;
    cin >> s;
    find_sound(s);
    return 0;
}

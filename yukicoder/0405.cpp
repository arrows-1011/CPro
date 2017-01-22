#include <iostream>

using namespace std;

int main()
{
    const string num[] = {
        "I", "II", "III", "IIII", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII",
    };
    
    string s;
    int t;
    cin >> s >> t;
    if (t > 12) {
        t %= 12;
    } else if (t < -12) {
        t = -(-t % 12); 
    }
        
    for (int i = 0; i < 12; i++) {
        if (num[i] == s) {
            cout << num[(i + t + 12) % 12] << endl;
            break;
        }
    }
        
    return 0;
}

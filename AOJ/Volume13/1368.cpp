#include <iostream>
#include <string>

using namespace std;

string i2s(int x)
{
    string s = to_string(x);
    while (s.size() != 4) {
        s = '0' + s;
    }
    return s;
}

int x[10][10];

int get_num(const string& s)
{
    int r = 0;
    for (int i = 0; i < 5; i++) {
        int c = s[i] - '0';
        r = x[r][c];
    }
    return r;
}

bool error(string& s)
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= 9; j++) {
            int v = s[i] - '0';
            if (v == j) continue;
            s[i] = (j + '0');
            if (get_num(s) == 0) {
                return 1;
            }
            s[i] = (v + '0');
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (s[i] == s[i + 1]) continue;
        swap(s[i], s[i + 1]);
        if (get_num(s) == 0) {
            return 1;
        }
        swap(s[i], s[i + 1]);
    }        
    return 0;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> x[i][j];
        }
    }
    
    int cnt = 0;
    for (int i = 0; i <= 9999; i++) {
        auto s = i2s(i);
        int r = 0;
        for (int j = 0; j < 4; j++) {
            int c = s[j] - '0';
            r = x[r][c];
        }              
        s += (r + '0');
        cnt += error(s);
    }
    cout << cnt << endl;
    return 0;
}

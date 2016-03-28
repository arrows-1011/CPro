#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name;
    cin >> name;
    name[0] = toupper(name[0]);
    for (size_t i = 1; i < name.size(); i++) {
        name[i] = tolower(name[i]);
    }
    cout << name << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    if (A == "0" || B == "0") {
        if (A == "0" && B == "0") {
            cout << "E" << endl;
        } else {
            cout << "S" << endl;
        }
    } else {
        if (A == "2" && B == "2") {
            cout << "E" << endl;
        } else if (A == "1" || B == "1") {
            cout << "S" << endl;
        } else {
            cout << "P" << endl;
        }
    }        
    return 0;
}

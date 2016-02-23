#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << (N % 1111 == 0 ? "SAME" : "DIFFERENT") << endl;    
    return 0;
}

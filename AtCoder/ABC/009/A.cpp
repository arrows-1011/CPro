#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << N/2+(N&1) << endl;
    return 0;
}

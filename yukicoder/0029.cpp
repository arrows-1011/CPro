#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> n(11);
    for (int i = 0; i < N; i++) {
        int a;
        for (int j = 0; j < 3; j++) {
            cin >> a;
            n[a] += 1;
        }               
    }
    
    int res = 0;
    for (int i = 0; i <= 10; i++) {
        if (n[i] >= 2) {
            res += n[i] / 2;            
            n[i] = n[i] - n[i] / 2 * 2;
        }        
    }
    
    int sum = 0;
    for (int i = 0; i <= 10; i++) {
        sum += n[i];
    }
    res += sum / 4;
    cout << res << endl;
    return 0;
}

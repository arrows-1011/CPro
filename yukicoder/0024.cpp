#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<bool> num(10, 1);
    for (int i = 0; i < N; i++) {
        vector<int> a(4);
        for (int j = 0; j < 4; j++) {
            cin >> a[j];
        }
        string R;
        cin >> R;
        for (int j = 0; j < 10; j++) {
            bool eq = 0;
            for (int k = 0; k < 4; k++) {
                if (j == a[k]) {
                    eq = 1;
                }
            }
            if (R == "YES" && !eq) {
                num[j] = 0;
            }
            if (R == "NO" && eq) {
                num[j] = 0;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        if (num[i]) {
            cout << i << endl;
        }
    }
    return 0;
}

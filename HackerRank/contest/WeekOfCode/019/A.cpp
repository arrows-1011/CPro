#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int v[6];
    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    int res = 114514;
    for (int a = v[0]; a <= 50; a++) {
        int da = a - v[0];
        for (int b = v[1]; b <= 50; b++) {
            int db = b - v[1];
            for (int c = v[2]; c <= 50; c++) {
                int dc = c - v[2];
                for (int d = v[3]; d <= 50; d++) {
                    int dd = d - v[3];
                    int cost = da + db + dc + dd;
                    if (a + v[4] + d >= 0 &&
                        a + v[5] + b >= 0 &&
                        a + b + c + d >= 0) {                        
                        res = min(res, cost);                                  
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}

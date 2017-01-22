#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> p(3);
    p[N - 1] = 1;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        swap(p[a], p[b]);
    }
    
    int num = -1;
    for (int i = 0; i < 3; i++) {
        if (p[i] == 1) num = i + 1;
    }
    cout << num << endl;
    return 0;
}

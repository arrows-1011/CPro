#include <iostream>
#include <list>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    list<int> lst;
    for (int i = 0; i < N; i++) {
        lst.push_back(i + 1);
    }
    for (int i = 0; i < M; i++) {
        int c, n = 0;
        cin >> c;
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            int num = *it;
            if (++n == c) {
                lst.erase(it);
                lst.push_front(num);
            }
        }
    }
    cout << *lst.begin() << endl;
    return 0;
}

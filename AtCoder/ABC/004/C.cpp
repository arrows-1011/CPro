#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int> arr = {1, 2, 3, 4, 5, 6}, init;
    init = arr;
    int j = -1;
    for (int i = 0, p = 0; ; i++, p++) {    
        swap(arr[p%5+1], arr[p%5+2]);
        if (arr == init) {
            j = i+1;
            break;
        }
    }

    cin >> N; N %= j;
    for (int i = 0, p = 0; i < N; i++, p++) {
        swap(arr[p%5], arr[p%5+1]);
    }

    for (int i = 0; i < 6; i++) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}

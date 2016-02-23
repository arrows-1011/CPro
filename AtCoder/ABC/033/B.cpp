#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    double sum = 0;
    cin >> n;
    vector<string> name(n);
    vector<int> pop(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> name[i] >> pop[i];
        sum += pop[i];
    }
    
    string new_name = "atcoder";
    for (int i = 0 ; i < n ; i++) {
        if (pop[i] > sum/2) {
            new_name = name[i];
            break;
        }
    }
    cout << new_name << endl;
    return 0;
}

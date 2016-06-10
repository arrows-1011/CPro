#include <iostream>

using namespace std;
 
#define MAX 10
 
void res(int);
 
int main()
{
    int n, num;
 
    while (cin >> n, n) {
	int ice[MAX] = {0};
	for (int i = 0; i < n; i++) {
	    cin >> num;
	    ice[num]++;
	}
	for (int i = 0; i < MAX; i++) {
            res(ice[i]);
        }
    }
    return 0;
}
 
void res(int n)
{
    if (n == 0) {
        cout << '-' << endl;
    } else {
	while (n > 0) {
	    cout << '*';
	    n--;
	}
	cout << endl;
    }
}

#include <iostream>

using namespace std;
 
int main(){
    int x,y,z;
 
    cin >> x >> y >> z;
    if((x&&!y&&!z)||(!x&&y&&!z)||(!x&&!y&&!z)) cout << "Close" << endl;
    else cout << "Open" << endl;
    return 0;
}

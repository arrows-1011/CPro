#include <iostream>

using namespace std;

int main()
{
    int RPS[5], R, P, S;
    while (1) {
	R = P = S = 0;
	for (int i = 0; i < 5; i++) {
            cin >> RPS[i];
            if (RPS[0] == 0) break;
            if (RPS[i] == 1) R++;
            else if (RPS[i] == 2) S++;
            else P++;
        }
	if (RPS[0] == 0) break;
        
	if ((R > 0 && S > 0 && P > 0) || R == 5 || S == 5|| P == 5) {
            for (int i = 0; i < 5; i++) {
                cout << "3" << endl;
            }
        } else if (R == 0) {
            for (int i = 0; i < 5; i++) {
                if (RPS[i] == 2) {
                    cout<<"1"<<endl;
                } else {
                    cout<<"2"<<endl;
                }
            }
        } else if (S == 0) {
            for (int i = 0; i < 5; i++) {
                if (RPS[i] == 3) {
                    cout << "1" << endl;
                } else {
                    cout << "2" << endl;
                }
            }
        } else if (P == 0) {
            for (int i = 0; i < 5; i++) {
                if (RPS[i] == 1) {
                    cout << "1" << endl;
                } else {
                    cout << "2" << endl;
                }
            }
        }
    }
    return 0;
}

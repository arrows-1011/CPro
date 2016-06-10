#include <bits/stdc++.h>
 
using namespace std;
 
class Dice {
  private:
    void roll(int a, int b, int c, int d) {
	swap(x[a], x[b]);
	swap(x[b], x[d]);
	swap(x[c], x[d]);
    }
  public:
    char x[6];
    void roll_N(){ roll(0, 1, 4, 5); }
    void roll_E(){ roll(0, 3, 2, 5); }
    void roll_S(){ roll(0, 4, 1, 5); }
    void roll_W(){ roll(0, 2, 3, 5); }
    void rotation(){ roll(1, 2, 3, 4); }
};
 
Dice d[8], e[2][2][2];
 
int diff(char a, char b)
{
    return abs(a-b) == 32;
}
 
bool check(int idx)
{
    bool res = true;
    if (idx == 0) return res;
    if (idx == 1) {
	return diff(e[0][0][0].x[1], e[1][0][0].x[4]);
    }
    if (idx == 2) {
	return diff(e[0][0][0].x[2], e[0][1][0].x[3]);
    }
    if(idx == 3) {
	res &= diff(e[1][0][0].x[2], e[1][1][0].x[3]);
	res &= diff(e[0][1][0].x[1], e[1][1][0].x[4]);
    }
    if (idx == 4) {
	return diff(e[0][0][0].x[5], e[0][0][1].x[0]);
    }
    if (idx == 5) {
	res &= diff(e[1][0][0].x[5], e[1][0][1].x[0]);
	res &= diff(e[0][0][1].x[1], e[1][0][1].x[4]);
    }
    if (idx == 6) {
	res &= diff(e[0][0][1].x[2], e[0][1][1].x[3]);
	res &= diff(e[0][1][0].x[5], e[0][1][1].x[0]);
    }
    if (idx == 7) {
	res &= diff(e[1][0][1].x[2], e[1][1][1].x[3]);
	res &= diff(e[0][1][1].x[1], e[1][1][1].x[4]);
	res &= diff(e[1][1][0].x[5], e[1][1][1].x[0]);
    }
    return res;
}
 
bool rec(int idx, int S)
{
    if (S == (1<<8)-1) return true; 
    for (int i = 0; i < 8; i++) {
	if((S >> i) & 1) continue; 
	for (int j = 0; j < 4; j++) {
	    for (int k = 0; k < 4; k++) {
		d[i].roll_N();
		e[idx%2][(idx%4)>1][idx>3] = d[i];
		if (check(idx) && rec(idx+1,S|(1<<i))) {
		    return true;
		}
	    }
	    for (int k = 0; k < 4; k++) {
		d[i].roll_E();
		e[idx%2][(idx%4)>1][idx>3] = d[i];
		if (check(idx) && rec(idx+1,S|(1<<i))) {
		    return true;
		}
	    }
	    d[i].rotation();
	}
    }
    return false;
}
 
int main()
{
    while (cin >> d[0].x[0],d[0].x[0] != '0') {
	for (int i = 0; i < 8; i++) {
	    for (int j = (i == 0); j < 6; j++) {
		cin >> d[i].x[j];
	    }
	}
	cout << (rec(0, 0) ? "YES" : "NO") << endl;
    }
    return 0;
}

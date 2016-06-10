#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 100
  
struct S {
    int g, t;
    S(int g, int t) : g(g), t(t) {}
};
  
int arr[MAX];
vector<S> seat;
  
int minute(int i)
{
    return 17*(i%2) + 3*(i%3) + 19;
}
  
void make()
{
    int g = 0;
    for (int i = 0; i < 17; i++) {
	seat.push_back(S(-1, -1));
    }
    vector<S> _wait;
    for (int i = 0; i < 570; i++) {
	int size = _wait.size();
  
	if (size) {
	    for (int j = 0; j < size; j++) {
		_wait[j].t++;
	    }
	}
     
	for (int j = 0; j < 17; j++) {
	    if (seat[j].g != -1) {
		seat[j].t--;
		if (seat[j].t == 0) {
		    seat[j].g = seat[j].t = -1;
		}
	    }
	}
   
	if (size) {
	    for (int j = 0; j < size; j++) {
		int n = _wait[j].g;
		int cnt, c;
		bool flg = false;
		if (n % 5 == 1) cnt = c = 5;
		else cnt = c = 2;
		for (int k = 0; k < 17; k++) {
		    if (seat[k].g == -1) cnt--;
		    else cnt = c;
		    if (cnt == 0) {
			for (int l = k-c+1; l <= k; l++) {
			    seat[l].g = n;
			    seat[l].t = minute(n);
			}
			arr[n] = _wait[j].t;
			flg = true;
			j--;
			_wait.erase(_wait.begin());
			break;
		    }
		}
		if (!flg || !_wait.size()) break;
	    }
	    size = _wait.size();
	}
	if (g == 100) continue;
	if (i % 5 == 0) {
	    int cnt, c;
	    bool flg = false;
	    if (size) {
		_wait.push_back(S(g, 0));
		g++;
		continue;
	    }
	    if (g % 5 == 1) cnt = c = 5;
	    else cnt = c = 2;
        
	    for (int j = 0; j < 17; j++) {
		if (seat[j].g == -1) cnt--;
		else cnt = c;
		if (cnt == 0) {
		    flg = true;
		    for (int k = j-c+1; k <= j; k++) {
			seat[k].g = seat[k].g = g;
			seat[k].t = seat[k].t = minute(g);
		    }
		    arr[g] = 0;
		    break;
		}
	    }
	    if (!flg) {
		_wait.push_back(S(g,0));
	    }
	    g++;
	}
    }
}
  
int main()
{
    int N;
    make();
    while (cin >> N) {
	cout << arr[N] << endl;
    }
    return 0;
}

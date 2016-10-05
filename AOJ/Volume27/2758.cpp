#include <bits/stdc++.h>

using namespace std;

int getNum(string s)
{
    if (s == "mamoru") return 0;
    if (s == "tameru") return 1;
    return 2;
}

int main()
{
    int K;
    cin >> K;
    string s;
    vector<int> I(K), N(K);
    for (int i = 0; i < K; i++) {
	cin >> s;
	I[i] = getNum(s);
    }
    for (int i = 0; i < K; i++) {
	cin >> s;
	N[i] = getNum(s);
    }
    int win = 0;
    int it = 0, nt = 0;
    for (int i = 0; i < K; i++) {
	if (I[i] == 1) it++;
	if (N[i] == 1) nt++;
	it = min(it, 5);
	nt = min(nt, 5);
	if (I[i] == 2 && N[i] == 0) {
	    if (it == 0) {
		win = 2;
		break;
	    } else if (it >= 5) {
		win = 1;
		break;
	    }
	} else if (I[i] == 0 && N[i] == 2) {
	    if (nt == 0) {
		win = 1;
		break;
	    } else if (nt >= 5) {
		win = 2;
		break;
	    }
	} else if (I[i] == 2 && N[i] == 1) {
	    if (it == 0) {
		win = 2;
		break;
	    } else {
		win = 1;
		break;
	    }
	} else if (I[i] == 1 && N[i] == 2) {
	    if (nt == 0) {
		win = 1;
		break;
	    } else {
		win = 2;
		break;
	    }
	} else if (I[i] == 2 && N[i] == 2) {
	    if (it == 0 && nt > 0) {
		win = 2;
		break;
	    } else if (it > 0 && nt == 0) {
		win = 1;
		break;
	    } else if (it > 0 && nt > 0) {
		if (it > nt) {
		    win = 1;
		    break;
		} else if (it < nt) {
		    win = 2;
		    break;
		}
	    }
	}
	if (I[i] == 2) it = 0;
	if (N[i] == 2) nt = 0;
    }
    if (win == 0) {
	cout << "Hikiwake-kun" << endl;
    } else if (win == 1) {
	cout << "Isono-kun" << endl;
    } else {
	cout << "Nakajima-kun" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int prev(int x)
{
    while (1) {
        if (x % 10 == 0 || x % 10 == 5) {
            break;
        }
        x--;
    }
    return x;
}

int next(int x)
{
    while (1) {
        if (x % 10 == 0 || x % 10 == 5) {
            break;
        }
        x++;
    }
    return x;
}

int to_min(int a)
{
    int h, m;
    m = a % 100;
    h = a / 100;
    return h * 60 + m;
}

string to_time(int x)
{
    int h = x / 60, m = x % 60;
    string res;
    if (h == 0) {
        res += "00";
    } else if (h <= 9) {
        res += "0" + to_string(h);
    } else {
        res += to_string(h);
    }
    if (m == 0) {
        res += "00";
    } else if (m <= 9) {
        res += "0" + to_string(m);
    } else {
        res += to_string(m);
    }
    return res;
}

int main()
{
    int N, a, b;
    cin >> N;
    int rain[2000] = {};
    for (int i = 0; i < N; i++) {
        scanf("%d-%d", &a, &b);
        a = prev(a);
        b = next(b);
        a = to_min(a);
        b = to_min(b);
        for (int j = a; j <= b; j++) {
            rain[j] = 1;
        }
    }

    for (int i = 0; i < 2000; i++) {
        if (rain[i] > 0) {
            int s = i, t = i;
            while (t < 2000 && rain[t] > 0) {
                t++;
            }
            i = t - 1;
            cout << to_time(s) << "-" << to_time(t-1) << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    double G, V;
    cin >> N >> G >> V;
    N /= 5;
    printf("%.10f\n", N * G / V);
    return 0;
}

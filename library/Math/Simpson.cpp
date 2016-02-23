/*
  シンプソンの公式
 */

#include <iostream>

using namespace std;

double simpson(double l, double r, double f(double), int k = 1){
    double h = (r - l) / (2 * k);
    double fo = 0, fe = 0;
    for (int i = 1; i <= 2 * k - 3; i += 2) {
	fo += f(l + h * i);
	fe += f(l + h * (i + 1));
    }
    return (f(l) + f(r) + 4 * (fo + f(r - h)) + 2 * fe) * h / 3;
}

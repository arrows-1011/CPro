/*
  単純多角形の面積を求める.
 */

#include <bits/stdc++.h>

using namespace std;

double area(const Polygon &a){
    double res = 0;
    for(int i = 0 ; i < (int)a.size() ; i++){
	res += cross(a[i], next(a,i));
    }
    return abs(res) * 0.5;
}

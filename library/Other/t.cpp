#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <ostream>
#include <bitset>
#include <list>
#include <deque>
#include <complex>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <climits>

using namespace std;

#define MAX 100000
#define INF 1e9
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define all(p) (p).begin(),(p).end() 

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

template<typename T>
T sum(T a,T b){
  return a + b;
}
template<typename T> 
T sub(T a,T b){
  return a - b;
}
//typenameはclassに代用可能
template<class T>
T mul(T a,T b){
  return a*b;
}

template<typename T,typename T1,typename T2>
T add(T1 a,T2 b){
  return a + b;
}

int main(){
  cout << add<int,int,int>(1,2) << endl;
  cout << add<double,double,double>(1.2,2.4) << endl;
  cout << add<double,double,int>(1.2,1) << endl;

  return 0;
}

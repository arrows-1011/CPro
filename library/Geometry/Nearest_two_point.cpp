#include <bits/stdc++.h>

using namespace std;

#define MAX_N 500000
#define INF 1e9
typedef pair<double,double> P;

int N;
P A[MAX_N]; 

bool compare_y(const P &a,const P &b){
  return a.second < b.second;
}
 
double closest_pair(P *a,int n){
  if(n <= 1) return INF;
  int m = n / 2;
  double x = a[m].first;
  double d = min(closest_pair(a,m),closest_pair(a+m,n-m));
  inplace_merge(a,a+m,a+n,compare_y);
 
  vector<P> b;
  for(int i = 0 ; i < n ; i++){
    if(fabs(a[i].first - x) >= d) continue;
    for(int j = 0 ; j < (int)b.size() ; j++){
      double dx = a[i].first - b[b.size()-j-1].first;
      double dy = a[i].second - b[b.size()-j-1].second;
      if(dy >= d) break;
      d = min(d,sqrt(dx * dx + dy * dy));
    }
    b.push_back(a[i]);
  }
  return d;
}

void solve(){
  sort(A,A+N);
  printf("%.8f\n",closest_pair(A,N));
}

int main(){
  cin >> N;
  for(int i = 0 ; i < N ; i++){
    scanf("%lf%lf",&A[i].first,&A[i].second);
  }
  solve();
  return 0;
}

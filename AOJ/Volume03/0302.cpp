#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
const int MAX_N = 1<<18;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> P;
 
int n;
int minX[2*MAX_N-1],maxX[2*MAX_N-1];
int minY[2*MAX_N-1],maxY[2*MAX_N-1];
 
struct Data{
    int x,y,b;
    Data(){}
    Data(int x,int y,int b) : x(x),y(y),b(b) {}
    bool operator < (const Data &d)const{
        return b < d.b;
    }
};
 
void init(ll n_){
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0 ; i < 2*n-1 ; i++){
        minX[i] = minY[i] = INT_MAX;
        maxX[i] = maxY[i] = INT_MIN;
    }
}
 
void update(int k,pii p){
    k += n - 1;
    minX[k] = min(minX[k],p.first);
    maxX[k] = max(maxX[k],p.first);
    minY[k] = min(minY[k],p.second);
    maxY[k] = max(maxY[k],p.second);
    while(k > 0){
        k = (k - 1) / 2;
        minX[k] = min(minX[2*k+1],minX[2*k+2]);
        maxX[k] = max(maxX[2*k+1],maxX[2*k+2]);
        minY[k] = min(minY[2*k+1],minY[2*k+2]);
        maxY[k] = max(maxY[2*k+1],maxY[2*k+2]);
    }
}
 
P query(int a,int b,int k,int l,int r){
    if(r <= a || b <= l){
        return P(pii(INT_MAX,INT_MIN),pii(INT_MAX,INT_MIN));
    }
    if(a <= l && r <= b){
        return P(pii(minX[k],maxX[k]),pii(minY[k],maxY[k]));
    }else{
        P vl = query(a,b,2*k+1,l,(l+r)/2);
        P vr = query(a,b,2*k+2,(l+r)/2,r);
        return P(pii(min(vl.F.F,vr.F.F),max(vl.F.S,vr.F.S)),
                 pii(min(vl.S.F,vr.S.F),max(vl.S.S,vr.S.S)));
    }
}
 
ll getArea(P p){
    return (ll)(p.F.S-p.F.F)*(ll)(p.S.S-p.S.F);
}
 
int main(){
    int N,d,x,y,b;
    cin >> N >> d;
    vector<Data> v(N);
    for(int i = 0 ; i < N ; i++){
        cin >> x >> y >> b;
        v[i] = Data(x,y,b);
    }
    sort(v.begin(),v.end());
    init(N);
    for(int i = 0 ; i < N ; i++){
        update(i,pii(v[i].x,v[i].y));
    }
    ll res = 0;
    for(int i = 0, j = 0 ; i < N ; i++){
        int s = v[i].b, t = v[j].b;
        while(j < N && t - s <= d) j++, t = v[j].b;
        j--;
        P p = query(i,j+1,0,0,n);
        res = max(res,getArea(p));
    }
    cout << res << endl;
    return 0;
}

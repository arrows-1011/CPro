#include <bits/stdc++.h>

using namespace std;

#define MAX 300000

struct Suffix_Array {
    int N, k;
    vector<int> sa;
    
    Suffix_Array (const string &S) : N(S.size()), sa(N+1) {
        vector<int> rnk(N+1), tmp(N+1);
        for (int i = 0; i <= N; i++) {
            sa[i] = i;
            rnk[i] = (i < N ? S[i] : -1);
        }
        
        for (k = 1; k <= N; k *= 2) {
            const auto comp = [&](int i, int j) -> bool {
                if (rnk[i] != rnk[j]) {
                    return rnk[i] < rnk[j];
                } else {
                    int ri = (i + k <= N ? rnk[i + k] : -1);
                    int rj = (j + k <= N ? rnk[j + k] : -1);
                    return ri < rj;
                }  
            };
            
            sort(sa.begin(), sa.end(), comp);

            tmp[sa[0]] = 0;
            for (int i = 1; i <= N; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]));
            }

            for (int i = 0; i <= N; i++) {
                rnk[i] = tmp[i];
            }
        } 
    }
    
    int lower_bound(const string &S, const string &T)
    {
        int l = 0, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sa[mid], T.size(), T) < 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return (S.compare(sa[r], T.size(), T) == 0 ? r : -1);
    }

    int upper_bound(const string &S, const string &T)
    {
        int l = 1, r = N+1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sa[mid], T.size(), T) <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return (S.compare(sa[l], T.size(), T) == 0 ? r : -1);
    }
};

struct RMQ {
    int n, dat[2*MAX-1];
  
    void init(int n_)
    {
	n = 1;
	while (n < n_) {
            n *= 2;
        }
	for (int i = 0; i < 2*n-1; i++) {
	    dat[i] = INT_MAX;
	}
    }
  
    void update(int k, int a)
    {
	k += n - 1;
	dat[k] = a;
	while (k > 0) {
	    k = (k - 1) / 2;
	    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
    }

    int query(int a, int b, int k, int l, int r)
    {
	if (r <= a || b <= l) {
            return INT_MAX;
        }
	if (a <= l && r <= b) {
	    return dat[k];
	} else {
	    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
	    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
	    return min(vl, vr);
	}
    }
};

struct RMQ2 {
    int n, dat[2*MAX-1];
  
    void init(int n_)
    {
	n = 1;
	while (n < n_) {
            n *= 2;
        }
	for (int i = 0; i < 2*n-1; i++) {
	    dat[i] = INT_MIN;
	}
    }
  
    void update(int k, int a)
    {
	k += n - 1;
	dat[k] = a;
	while (k > 0) {
	    k = (k - 1) / 2;
	    dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
    }

    int query(int a, int b, int k, int l, int r)
    {
	if (r <= a || b <= l) {
            return INT_MIN;
        }
	if (a <= l && r <= b) {
	    return dat[k];
	} else {
	    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
	    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
	    return max(vl, vr);
	}
    }
};

int main()
{
    ios::sync_with_stdio(0);

    int Q, N;
    string S, R, x, y;
    
    cin >> S >> Q;

    Suffix_Array SA(S);

    N = S.size() + 1;
    RMQ rmq1;
    RMQ2 rmq2;
    rmq1.init(N); rmq2.init(N);
    for (int i = 0; i < N; i++) {
        rmq1.update(i, SA.sa[i]);
        rmq2.update(i, SA.sa[i]);
    }
    
    while (Q--) {
        cin >> x >> y;
        int lb_x = SA.lower_bound(S, x), ub_x = SA.upper_bound(S, x);
        int lb_y = SA.lower_bound(S, y), ub_y = SA.upper_bound(S, y);
        if (lb_x == -1 || ub_x == -1 || lb_y == -1 || ub_y == -1) {
            cout << 0 << endl;
            continue;
        }        
        
        int l = rmq1.query(lb_x, ub_x, 0, 0, rmq1.n);
        int r = rmq2.query(lb_y, ub_y, 0, 0, rmq2.n);
        
        if (l > r || (l <= r && r + (int)y.size() < l + (int)x.size())) {
            cout << 0 << endl;
            continue;
        }
        
        cout << r - l + (int)y.size() << endl;
    }
    return 0;
}

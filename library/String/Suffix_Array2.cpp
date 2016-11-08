#include <iostream>
#include <vector>

using namespace std;

#define MAX 300000

struct Suffix_Array {
    int N, k;
    vector<int> sa;
    
    Suffix_Array (const string& S) : N(S.size()), sa(N + 1) {
        vector<int> rank(N + 1), tmp(N + 1);
        for (int i = 0; i <= N; i++) {
            sa[i] = i;
            rank[i] = (i < N ? S[i] : -1);
        }
        
        for (k = 1; k <= N; k *= 2) {
            const auto comp = [&](int i, int j) -> bool {
                if (rank[i] != rank[j]) {
                    return rank[i] < rank[j];
                } else {
                    int ri = (i + k <= N ? rank[i + k] : -1);
                    int rj = (j + k <= N ? rank[j + k] : -1);
                    return ri < rj;
                }  
            };
            
            sort(sa.begin(), sa.end(), comp);

            tmp[sa[0]] = 0;
            for (int i = 1; i <= N; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]));
            }

            for (int i = 0; i <= N; i++) {
                rank[i] = tmp[i];
            }
        } 
    }
    
    int lower_bound(const string& S, const string& T)
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

    int upper_bound(const string& S, const string& T)
    {
        int l = 1, r = N + 1;
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

    bool contain(const string& S, const string& T)
    {
        int l = 0, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (S.compare(sa[mid], T.size(), T) <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return (S.compare(sa[r], T.size(), T) == 0);
    }
};


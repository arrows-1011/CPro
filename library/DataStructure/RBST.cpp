#include <iostream>
#include <algorithm>

using namespace std;

#define INF (1<<29)
#define mp make_pair

class RBST {
public:
    int cnt, val, mini, add, rev;
    RBST *l, *r;
    RBST (int val = 0) :
	cnt(1), val(val), mini(val), add(0), l(NULL), r(NULL) {}

    int size(RBST *x)
    {
	return (x ? x->cnt : 0);
    }
    
    int get_min(RBST *x)
    {
	return (x ? x->mini + x->add : INF);
    }
    
    RBST *push()
    {
	if (l) l->add += add;
	if (r) r->add += add;
	val += add;
	add = 0;
	if (rev) {
	    swap(l,r);
	    if (l) l->rev ^= 1;
	    if (r) r->rev ^= 1;
	    rev = false;
	}
	return update();
    }

    RBST *update()
    {
	cnt = size(l) + size(r) + 1;
	mini = min(min(get_min(l), get_min(r)),val);
	return this;
    }
    
    RBST *merge(RBST *a, RBST *b)
    {
	if (!a || !b) return (a ? a->push() : b->push());
	a->push(); b->push();
	if ((int)(rand() % (size(a) + size(b))) < size(a)) {
	    a->r = merge(a->r, b);
	    return a->update();
	} else {
	    b->l = merge(a, b->l);
	    return b->update();
	}
    }
    
    /* [0,k) [k,n) */
    pair<RBST*, RBST*> split(RBST *a, int k)
    {
	if (!a) return mp<RBST*, RBST*>(NULL, NULL);
	a->push();
	if (k <= size(a->l)) {
	    pair<RBST*, RBST*> t = split(a->l, k);
	    a->l = t.second;
	    return mp(t.first, a->update());
	} else {
	    pair<RBST*, RBST*> t = split(a->r, k-size(a->l)-1);
	    a->r = t.first;
	    return mp(a->update(), t.second);
	}
    }
};

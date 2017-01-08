/*
  verified AOJ 1508
 */

#include <iostream>

using namespace std;

constexpr int INF = (1 << 29);

class Node {
  public:
    int val;
    Node* lch;
    Node* rch;
    int pri, cnt, sum, min;

    Node(int v, int p) : val{v}, pri{p}, cnt{1}, sum{v}, min{val} {
        lch = rch = nullptr;
    }
};

class Treap {
  private:
    Node* root;

    int count(Node* t)
    {
        return t == nullptr ? 0 : t->cnt;
    }

    int sum(Node* t)
    {
        return t == nullptr ? 0 : t->sum;
    }

    int rmin(Node* t)
    {
        return t != nullptr ? t->min : INF;
    }
    
    Node* update(Node* t)
    {
        t->cnt = count(t->lch) + count(t->rch) + 1;
        t->sum = sum(t->lch) + sum(t->rch) + t->val;
        t->min = min(min(rmin(t->lch), rmin(t->rch)), t->val);
        return t;
    }

    Node* merge(Node* l, Node* r)
    {
        if (l == nullptr || r == nullptr) {
            return (l == nullptr ? r : l);
        }

        if (l->pri > r->pri) {
            l->rch = merge(l->rch, r);
            return update(l);
        } else {
            r->lch = merge(l, r->lch);
            return update(r);
        }
    }
    
    pair<Node*, Node*> split(Node* t, int k)
    {
        if (t == nullptr) {
            return {nullptr, nullptr};
        }

        if (k <= count(t->lch)) {
            auto s = split(t->lch, k);
            t->lch = s.second;
            return {s.first, update(t)};
        } else {
            auto s = split(t->rch, k - count(t->lch) - 1);
            t->rch = s.first;
            return {update(t), s.second};
        }
    }

    Node* insert(Node* t, int k, int val, int pri)
    {
        auto s = split(t, k);
        t = merge(s.first, new Node{val, pri});
        t = merge(t, s.second);
        return update(t);
    }

    Node* erase(Node* t, int k)
    {
        auto s1 = split(t, k + 1);
        auto s2 = split(s1.first, k);
        t = merge(s2.first, s1.second);
        return update(t);
    }

    int range_min(Node* t, int l, int r)
    {
        l = max(l, 0); r = min(r, count(t));
        if (l >= r) return INF;
        if (l == 0 && r == count(t)) {
            return t->min;
        }

        int sl = count(t->lch);
        int res = min(range_min(t->lch, l, r),
                      range_min(t->rch, l - sl - 1, r - sl - 1));

        if (l <= sl && sl < r) {
            res = min(res, t->val);
        }
        
        return res;            
    }
    
  public:
    Treap() : root{nullptr} {}

    int size()
    {
        return count(root);
    }
    
    void insert(int k, int val)
    {
        root = insert(root, k, val, rand());
    }
        
    void erase(int k)
    {
        root = erase(root, k);
    }

    void update(int k, int val)
    {
        erase(k);
        insert(k, val);
    }  
    
    int range_min(int l, int r)
    {
        return range_min(root, l, r + 1);
    }
};

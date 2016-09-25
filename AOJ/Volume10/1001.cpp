#include <bits/stdc++.h>
 
using namespace std;
 
struct Tree {
    Tree *l, *r;
};
 
Tree *tree[2];
 
Tree* make_node()
{
    Tree *t = new Tree;
    t->l = t->r = NULL;
    return t;
}
 
void init()
{    
    tree[0] = make_node();
    tree[1] = make_node();
}
  
bool search_left_node(int &cur, string &s)
{
    int p = 0;
    for (int i = cur; i >= 1; i--) {
        if (s[i] == ')') {
            p++;
        } else if (s[i] == '(') {
            p--;
        }
        if (s[i] == ',' && p == 1) {
            cur = i;
            return 1;
        }
        if (p < 0) return 0;
    }
    return 0;
}
 
bool search_right_node(int &cur, string &s)
{
    int p = 0;
    for (int i = cur; i < (int)s.size()-1; i++) {
        if (s[i] == '(') {
            p++;
        } else if (s[i] == ')') {
            p--;
        }
        if (s[i] == ',' && p == 1) {
            cur = i;
            return 1;
        }
        if (p < 0) return 0;
    }
    return 0;
}
 
void add_left(Tree *t)
{
    t->l = make_node();
}
 
void add_right(Tree *t)
{
    t->r = make_node();
}
 
void dfs(int cur, string &s, Tree *t)
{
    int L = cur - 1, R = cur + 1;
    if (search_left_node(L, s)) {        
        add_left(t);
        dfs(L, s, t->l);
    }
    if (search_right_node(R, s)) {
        add_right(t);
        dfs(R, s, t->r);
    }
}
  
string make_i_tree(Tree *t1, Tree *t2)
{
    string l, r;
    if (t1->l != NULL && t2->l != NULL) {
        l = make_i_tree(t1->l, t2->l);
    } 
        
    if (t1->r != NULL && t2->r != NULL) {
        r = make_i_tree(t1->r, t2->r);
    }
    return "(" + l + "," + r + ")";
}

string make_u_tree(Tree *t1, Tree *t2)
{
    string l, r;
    if (t1->l != NULL || t2->l != NULL) {
        if (t1->l == NULL) add_left(t1);
        if (t2->l == NULL) add_left(t2);
        l = make_u_tree(t1->l, t2->l);
    } 
        
    if (t1->r != NULL || t2->r != NULL) {
        if (t1->r == NULL) add_right(t1);
        if (t2->r == NULL) add_right(t2);
        r = make_u_tree(t1->r, t2->r);
    }
    return "(" + l + "," + r + ")";
}

int get_root(string &s)
{
    int depth = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == '(') depth++;
        else if (s[i] == ')') depth--;
        if (depth == 0 && s[i] == ',') {
            return i;
        }
    }
    return -1;
}

void solve(char order, string &a, string &b)
{
    int cur_a = get_root(a), cur_b = get_root(b);   
    init();
    
    dfs(cur_a, a, tree[0]);
    dfs(cur_b, b, tree[1]);
    
    if (order == 'i') {
        cout << make_i_tree(tree[0], tree[1]) << endl;
    } else {
        cout << make_u_tree(tree[0], tree[1]) << endl;
    }
}
 
int main()
{
    char order;
    string a, b;
    while (cin >> order >> a >> b) {
        solve(order, a, b);
    }
    return 0;
}

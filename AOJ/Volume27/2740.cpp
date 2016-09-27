#include <bits/stdc++.h>
  
using namespace std;
  
struct Tree {
    Tree *l, *r;
    int v;    
};
  
Tree *tree[2], *ntree;
  
Tree* make_node(int v)
{
    Tree *t = new Tree;
    t->l = t->r = NULL;
    t->v = v;
    return t;
}
  
void init(int ra, int rb)
{    
    tree[0] = make_node(ra);
    tree[1] = make_node(rb);
    ntree = make_node(-1);
}
  
int get_num(string &s, int L, int R)
{
    L++; R--;
    string str;
    for (int i = L; i <= R; i++) {
        str += s[i];
    }
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}
  
int get_node_left(int &L, int &R, string &s)
{
    int p = 0;
    for (int i = R; i >= L; i--) {
        if (s[i] == ')') {
            p++;
        } else if (s[i] == '(') {
            p--;
        }
        if (p == 0) {
            if (i - 1 >= 0 && s[i-1] == ']') {
                int l = -1;
                for (int j = i-1; j >= L; j--) {
                    if (s[j] == '[') {
                        l = j;
                        break;
                    }
                }
                L = l-1; R = i;
                return get_num(s, l, i-1);
            }
            return -1;
        }
    }
    return -1;
}
  
int get_node_right(int &L, int &R, string &s)
{
    int p = 0;
    for (int i = L; i <= R; i++) {
        if (s[i] == '(') {
            p++;
        } else if (s[i] == ')') {
            p--;
        }
        if (p == 0) {
            if (i + 1 <= R && s[i+1] == '[') {
                int r = -1;
                for (int j = i+1; j <= R; j++) {
                    if (s[j] == ']') {
                        r = j;
                        break;
                    }
                }
                L = i; R = r+1;
                return get_num(s, i+1, r);
            }
            return -1;
        }
    }    
    return -1;
}
  
void add_left(int v, Tree *t)
{
    t->l = make_node(v);
}
  
void add_right(int v, Tree *t)
{
    t->r = make_node(v);
}
  
void dfs(int L, int R, string &s, Tree *t)
{
    int l = 0, r = s.size()-1;
    L = L - 1; R = R + 1;
    int vl = get_node_left(l, L, s);
    int vr = get_node_right(R, r, s);
    if (vl != -1) {
        add_left(vl, t);
        dfs(l, L, s, t->l);        
    }
    if (vr != -1) {
        add_right(vr, t);
        dfs(R, r, s, t->r);
    }
}
  
void make_sum_tree(Tree *t1, Tree *t2, Tree *t3)
{
    if (t1 != NULL && t2 != NULL) {
        t3->v = t1->v + t2->v;
        if (t1->l != NULL && t2->l != NULL) {
            t3->l = make_node(-1);
            make_sum_tree(t1->l, t2->l, t3->l);
        }
        if (t1->r != NULL && t2->r != NULL) {
            t3->r = make_node(-1);
            make_sum_tree(t1->r, t2->r, t3->r);
        }
    }
}
  
string i2s(int v)
{
    stringstream ss;
    ss << v;
    string s;
    ss >> s;
    return s;
}
  
string make_tree(Tree *t)
{
    string res, l = "()", r = "()";
    if (t != NULL) {
        res = "[" + i2s(t->v) + "]";
    }
    if (t->l != NULL) {
        l = "(" + make_tree(t->l) + ")";
    } 
         
    if (t->r != NULL) {
        r = "(" + make_tree(t->r) + ")";
    }
    return l + res + r;
}
  
void solve(string &a, string &b)
{
    int La = 0, Lb = 0;
    int Ra = a.size()-1, Rb = b.size()-1;
    int root_a = get_node_left(La, Ra, a);
    int root_b = get_node_left(Lb, Rb, b);
    init(root_a, root_b);
    dfs(La, Ra, a, tree[0]);
    dfs(Lb, Rb, b, tree[1]);    
    make_sum_tree(tree[0], tree[1], ntree);
    cout << make_tree(ntree) << endl;
}
  
int main()
{
    string a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}

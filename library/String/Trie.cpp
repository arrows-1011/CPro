#include <bits/stdc++.h>
  
using namespace std;
  
struct Trie {
    bool l;
    Trie *next[26];
  
    Trie() {
	l = false;
	fill(next, next+26, (Trie *)0);
    }
  
    int c(char ch)
    {
	if (islower(ch)) {
	    return ch-'a';
	}
	return -1;
    }
  
    void insert(char *s)
    {
	Trie *t = this;
	for (int i = 0; i < (int)strlen(s); i++) {
	    int v = c(s[i]);
	    if (!t->next[v]) {
		t->next[v] = new Trie();
	    }
	    t = t->next[v];
	}
	t->l = true;
    }

    void insert(Trie *t, char *s, int idx)
    {
        if (idx == (int)strlen(s)) {
            t->l = 1;
            return;
        }
            
        int v = c(s[idx]);
        if (t->next[v] == NULL) {
            t->next[v] = new Trie();
        }
        insert(t->next[v], s, idx + 1);
    }
    
    bool find(char *s)
    {
	Trie *t = this;
	for (int i = 0; i < (int)strlen(s); i++) {
	    int v = c(s[i]);
	    if (!t->next[v]) return false;
	    t = t->next[v];
	}
	return t->l;
    }
};

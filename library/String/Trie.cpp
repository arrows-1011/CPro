#include <iostream>
#include <cctype>
  
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
		t->next[v] = new Trie;
	    }
	    t = t->next[v];
	}
	t->l = true;
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

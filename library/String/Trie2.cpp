#include <bits/stdc++.h>
  
using namespace std;
  
struct Trie {
    bool l;
    Trie* next[26];
  
    Trie() {
	l = false;
	fill(next, next + 26, nullptr);
    }
  
    int c(char ch)
    {
        return (islower(ch) ? (ch - 'a') : -1);
    }
  
    void insert(char* s)
    {
	Trie* t = this;
	for (int i = 0; i < (int)strlen(s); i++) {
	    int v = c(s[i]);
	    if (t->next[v] == nullptr) {
		t->next[v] = new Trie();
	    }
	    t = t->next[v];
	}
	t->l = true;
    }

    void insert(Trie* t, char* s, size_t idx)
    {
        if (idx == strlen(s)) {
            t->l = 1;
            return;
        }
            
        int v = c(s[idx]);
        if (t->next[v] == nullptr) {
            t->next[v] = new Trie();
        }
        insert(t->next[v], s, idx + 1);
    }
    
    bool find(char* s)
    {
	Trie* t = this;
	for (int i = 0; i < (int)strlen(s); i++) {
	    int v = c(s[i]);
	    if (t->next[v] == nullptr) return false;
	    t = t->next[v];
	}
	return t->l;
    }

    bool find(Trie* t, char* s, size_t idx)
    {
        if (idx == strlen(s)) {
            return t->l;
        }
        return find(t->next[c(s[idx])], s, idx + 1);
    }
};

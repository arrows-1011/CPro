#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> Vec;

struct PMA {
    PMA *next[256];
    Vec matched;
    PMA() {
        fill(next, next+256, (PMA*)0);
    }
};

Vec set_union(const Vec &a, const Vec &b)
{
    int i = 0, j = 0, A = a.size(), B = b.size();
    Vec res;
    while (i < A && j < B) {
	if (a[i] == b[j]) {
	    res.push_back(a[i]);
	    i++; j++;
	} else if(a[i] > b[j]) {
	    res.push_back(b[j++]);
	} else {
	    res.push_back(a[i++]);
	}
    }
    for ( ; i < A ; i++) res.push_back(a[i]);
    for ( ; j < B ; j++) res.push_back(b[j]);
    return res;
}

PMA *buildPMA(char *pattern[], int size)
{
    PMA *root = new PMA;
    for (int i = 0; i < size; i++) {
	PMA *t = root;
	for (int j = 0; pattern[i][j] != '\0'; j++) {
	    char c = pattern[i][j];
	    if (t->next[c] == NULL) t->next[c] = new PMA;
	    t = t->next[c];
	}
	t->matched.push_back(i);
    }
    queue<PMA*> Q;
    for (int i = 'a'; i <= 'z'; i++) {
	if (root->next[i]) {
	    root->next[i]->next[0] = root;
	    Q.push(root->next[i]);
	} else {
	    root->next[i] = root;
	}
    }
    while (!Q.empty()) {
	PMA *t = Q.front(); Q.pop();
	for (int i = 'a'; i <= 'z'; i++) {
	    if (t->next[i]) {
		PMA *next = t->next[0];
		while (!next->next[i]) next = next->next[0];
		
                t->next[i]->next[0] = next->next[i];
                
		t->next[i]->matched =
		    set_union(t->next[i]->matched, next->next[i]->matched);
		
                Q.push(t->next[i]);
	    }
	}
    }
    return root;
}

void match(PMA *pma, const char *s, Vec &res)
{
    for (int i = 0; s[i] != '\0'; i++) {
	int c = s[i];
	while (!pma->next[c]) pma = pma->next[0];
	pma = pma->next[c];
	for (int j = 0; j < (int)pma->matched.size(); j++) {
	    res[pma->matched[j]] = true;
	}
    }
}

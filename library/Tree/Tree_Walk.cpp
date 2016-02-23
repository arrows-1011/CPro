/*
  pre orderとin orderが与えられる.
  その情報をもとにpost orderを出力する.
*/

#include <stdio.h>
 
#define MAX 40
 
void solve(int*, int*, int);
 
int n, post[MAX], idx;
 
int main()
{
    int pre[MAX], in[MAX], i;
 
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
	scanf("%d", &pre[i]);
    }
    for (i = 0; i < n; i++) {
	scanf("%d", &in[i]); 
    }
 
    solve(pre, in, n);
 
    for (i = 0; i < n; i++) {
	printf("%d%c", post[i], (i != n-1 ? ' ':'\n'));
    }
 
    return 0;
}
 
void solve(int pre[], int in[], int N)
{
    int i, p = -1;
 
    for (i = 0; i < N; i++) { 
	if (in[i] == pre[0]) {
	    p = i;
	    break;
	}
    }
 
    if (p != 0) {
	solve(pre+1, in, p);
    }
    if (p != N-1) {
	solve(pre+p+1, in+p+1, N-p-1);
    }
    post[idx++] = pre[0]; 
}

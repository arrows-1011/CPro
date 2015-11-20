#include <stdio.h>
#include <ctype.h>
 
int P,Q,R;
char *p;
 
int formula(){
    int l,r;
    char c = *p++;
    if(isdigit(c)) return c-'0';
    if(isupper(c)) return (c == 'P' ? P : c == 'Q' ? Q : R);
    if(c == '-') return 2-formula();
    if(c == '('){
	l = formula();
	if(*p++ == '*'){
	    r = formula();
	    *p++;
	    return (l < r ? l : r);
	}else{
	    r = formula();
	    *p++;
	    return (l > r ? l : r);
	}  
    }
    return 0;
}
 
int main(){
    int ans;
    char s[100];
    while(scanf("%s",s), s[0] != '.'){
	ans = 0; 
	for(P = 0 ; P < 3 ; P++){
	    for(Q = 0 ; Q < 3 ; Q++){
		for(R = 0 ; R < 3 ; R++){
		    p = s;
		    if(formula() == 2) ans++;
		}
	    }
	}
	printf("%d\n",ans);
    }
    return 0;
}

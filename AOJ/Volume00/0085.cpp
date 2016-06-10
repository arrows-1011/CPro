#include <bits/stdc++.h>

using namespace std;   
 
int pt(int n, int m)
{  
    int i; 
    for (i = m-1; i < (m-1)*n; i = (m*i) / (m-1)+1) {}
    return (m * n - i); 
}   
 
int main()
{     
    int n, m;
    while (cin >> n >> m, (n | m)) {
	cout << pt(n, m) << endl;    
    }
    return 0;
}

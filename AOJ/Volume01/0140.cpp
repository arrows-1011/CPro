#include <iostream>
#include <vector>
 
using namespace std;
 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define FOR1(i,a,b) for(int i = a ; i <= b ; i++)
#define FOR2(i,a,b) for(int i = a ; i >= b ; i--)
 
int main(){
    int n;
      
    cin >> n;
    while(n--){
        int s,g;
        vector<int> v;
          
        cin >> s >> g;
        if(s < g){
	    FOR1(i,s,g) v.push_back(i);
        }
        else if(s > g){
            if(s > 5){
		FOR1(i,s,9) v.push_back(i);
                if(g > 5){
		    FOR2(i,5,0) v.push_back(i);
		    FOR1(i,1,g) v.push_back(i);
                }
                else{
		    FOR2(i,5,g) v.push_back(i);
                }
            }
            else if(s <= 5){
		FOR2(i,s,g) v.push_back(i);
            }
        }        
     
	rep(i,(int)v.size()){
            if(!i) cout << v[i];
            else cout << ' ' << v[i];
        }
        cout << endl;
    }
    return 0;
}

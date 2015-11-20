#include <iostream>
#include <vector>
 
using namespace std;
 
#define INF 1e9
 
int main(){
    int P,Q;
    while(cin >> P >> Q, (P | Q)){
	int ind[10];
	int ro[10],rc[10],co[10],cc[10],so[10],sc[10];
	int ro2[10],rc2[10],co2[10],cc2[10],so2[10],sc2[10];
	string s;
	for(int i = 0 ; i < 10 ; i++){
	    ind[i] = 0;
	    ro[i] = rc[i] = 0;
	    co[i] = cc[i] = 0;
	    so[i] = sc[i] = 0;
	}
	for(int i = 0 ; i < P ; i++){
	    cin >> s;
	    bool rd = true;
	    for(int j = 0 ; j < (int)s.size() ; j++){
		if(s[j] == '(') ro[i]++; 
		if(s[j] == ')') rc[i]++; 
		if(s[j] == '{') co[i]++; 
		if(s[j] == '}') cc[i]++; 
		if(s[j] == '[') so[i]++;
		if(s[j] == ']') sc[i]++;
		if(s[j] != '.') rd = false;
		if(rd){ ind[i]++; }
	    }
	}
	for(int i = 1 ; i < P ; i++){
	    ro[i] += ro[i-1];
	    rc[i] += rc[i-1];
	    co[i] += co[i-1];
	    cc[i] += cc[i-1];
	    so[i] += so[i-1];
	    sc[i] += sc[i-1];
	}
	for(int i = 0 ; i < 10 ; i++){
	    ro2[i] = rc2[i] = 0;
	    co2[i] = cc2[i] = 0;
	    so2[i] = sc2[i] = 0;
	}
	for(int i = 0 ; i < Q ; i++){
	    cin >> s;
	    for(int j = 0 ; j < (int)s.size() ; j++){
		if(s[j] == '(') ro2[i]++; 
		if(s[j] == ')') rc2[i]++; 
		if(s[j] == '{') co2[i]++; 
		if(s[j] == '}') cc2[i]++; 
		if(s[j] == '[') so2[i]++; 
		if(s[j] == ']') sc2[i]++; 
	    }
	}
	for(int i = 1 ; i < Q ; i++){
	    ro2[i] += ro2[i-1];
	    rc2[i] += rc2[i-1];
	    co2[i] += co2[i-1];
	    cc2[i] += cc2[i-1];
	    so2[i] += so2[i-1];
	    sc2[i] += sc2[i-1];
	}
	vector<int> res(10,INF);
	res[0] = 0;
	for(int i = 1 ; i < Q ; i++){
	    vector<int> v;
	    for(int R = 1 ; R <= 20 ; R++){
		for(int C = 1 ; C <= 20 ; C++){
		    for(int S = 1 ; S <= 20 ; S++){
			bool ok = true;
			for(int j = 1 ; j < P ; j++){
			    int rd = ro[j-1]-rc[j-1];
			    int cd = co[j-1]-cc[j-1];
			    int sd = so[j-1]-sc[j-1];
			    if(R*rd+C*cd+S*sd != ind[j]){
				ok = false;
				break;
			    }
			}
			if(ok){
			    int rd = ro2[i-1]-rc2[i-1];
			    int cd = co2[i-1]-cc2[i-1];
			    int sd = so2[i-1]-sc2[i-1];
			    int val = R*rd+C*cd+S*sd;
			    if(res[i] == INF){
				res[i] = val;
			    }else{
				if(res[i] != val && res[i] != -1){
				    res[i] = -1;
				}
			    }
			}
		    }
		}
	    }
	}
	for(int i = 0 ; i < Q ; i++){
	    if(i) cout << " "; 
	    cout << res[i];
	}
	cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
int Tree[1<<12],m;
map<int,int> mp;
vector<int> order;
string::iterator it;
 
vector<int> getOrder(int x,int m){
    vector<int> res;
    while(x > 0){
        res.push_back(x%3);
        x /= 3;
    }
    while((int)res.size() != m){
        res.push_back(0);
    }
    return res;
}
 
int getBit(int v,vector<int> &bit){
    if(Tree[v] != -1){
        return bit[Tree[v]];
    }
    int S = -1;
    int l = getBit(2*v+1, bit);
    int r = getBit(2*v+2, bit);
    switch(order[mp[v]]){
    case 0:
        S = l & r;
        break;
    case 1:
        S = l | r;
        break;
    case 2:
        S = (l | r) - (l & r);
        break;
    };
    return S;
}
 
bool check(vector<int> &bit){
    return (getBit(0,bit) == (1<<4)-1);
}
 
int makeTree(int v){
    if(*it == '('){
        ++it;
        char cl = *it;
        int l = makeTree(2*v+1);
        if(isdigit(cl)){
            Tree[2*v+1] = l;
        }
        ++it;
        char cr = *it;
        int r = makeTree(2*v+2);
        if(isdigit(cr)){
            Tree[2*v+2] = r;
        }
        ++it;
    }else if(isdigit(*it)){
        int num = ((*it - '0') - 1);
        ++it;
        return num;
    }
    return -1;
}
 
void dfs(int v){
    if(Tree[v] == -1){
        mp[v] = m++;
        dfs(2*v+1);
        dfs(2*v+2);
    }
}
 
int main(){
    string s;
    while(getline(cin,s), s != "END"){
        int N,x;
        cin >> N;
        vector<int> bit(N, 0);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < 4 ; j++){
                cin >> x;
                if(x == 1) bit[i] |= 1<<j;
            }
        }
        int res = 0;
        memset(Tree,-1,sizeof(Tree));
        it = s.begin();
        makeTree(0); m = 0; dfs(0);
        int n = pow(3., m);
        for(int i = 0 ; i < n ; i++){
            order = getOrder(i, m);
            if(check(bit)) res++;
        }
        cout << res << endl;
        cin.ignore();
    }
    return 0;
}

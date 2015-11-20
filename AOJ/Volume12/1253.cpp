#include <bits/stdc++.h>
 
using namespace std;
 
class Dice{
private:
    void roll(int a,int b,int c,int d){
        swap(x[a],x[b]);
        swap(x[b],x[d]);
        swap(x[c],x[d]);
    }
public:
    int x[6];
    Dice(){
        for(int i = 0 ; i < 6 ; i++){
            x[i] = i+1;
        }
    }
    void roll_N(){ roll(0,1,4,5); }
    void roll_E(){ roll(0,3,2,5); }
    void rotation(){ roll(1,2,3,4); }
    void roll(int top,int front){
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                roll_N();
                if(top == x[0]) goto next;
            }
            roll_E();
        }
    next:
        for(int i = 0 ; i < 4 ; i++){
            rotation();
            if(front == x[1]) break; 
        }
    }
    void clear(){ memset(x,0,sizeof(x)); }  
}; 
 
bool can[60];
Dice d[3][3][3],d2[7][7];
int bit[27];
 
int calc(){
    int sum = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            sum += d[i][j][2].x[2];
        }
    }
    return sum;
}
 
bool check(int v){
    int a = v/9, b = (v%9)/3, c = (v%9)%3;
    int top = d[a][b][c].x[0],front = d[a][b][c].x[1];
    for(int i = 0 ; i < 6 ; i++){
        if(d[a][b][c].x[i] != d2[top][front].x[i]){
            return false;
        }
    }
    return true;
}
 
void solve(int v,int p,int S){
    if(v == 27){
        can[calc()] = 1;
        return;
    }
    if(p == 6){
        if(!check(v)) return;
        if(S == (1<<7)-1){
            solve(v+1,0,bit[v+1]);
        }
        return;
    }
    int a = v/9, b = (v%9)/3, c = (v%9)%3;
    if(a-1 >= 0 && p == 0){
        if(d[a][b][c].x[p] == 0){
            int x = 7 - d[a-1][b][c].x[5];
            if(S >> x & 1) return;
            d[a][b][c].x[p] = x;
            int x2 = d[a][b][c].x[5-p];
            if(x2 == 0 || x + x2 == 7){
                solve(v,p+1,S|(1<<x));
            }
            d[a][b][c].x[p] = 0;
        }else{
            if(d[a][b][c].x[p] + d[a-1][b][c].x[5] == 7){
                solve(v,p+1,S);
            }
        }
        return;
    }
    if(b-1 >= 0 && p == 4){
        if(d[a][b][c].x[p] == 0){
            int x = 7 - d[a][b-1][c].x[1];
            if(S >> x & 1) return;
            d[a][b][c].x[p] = x;
            int x2 = d[a][b][c].x[5-p];
            if(x2 == 0 || x + x2 == 7){
                solve(v,p+1,S|(1<<x));
            }
            d[a][b][c].x[p] = 0;
        }else{
            if(d[a][b][c].x[p] + d[a][b-1][c].x[1] == 7){
                solve(v,p+1,S);     
            }
        }
        return;
    }
    if(c-1 >= 0 && p == 3){
        if(d[a][b][c].x[p] == 0){
            int x = 7 - d[a][b][c-1].x[2];
            if(S >> x & 1) return;
            d[a][b][c].x[p] = x;
            int x2 = d[a][b][c].x[5-p];
            if(x2 == 0 || x + x2 == 7){
                solve(v,p+1,S|(1<<x));
            }
            d[a][b][c].x[p] = 0;
        }else{
            if(d[a][b][c].x[p] + d[a][b][c-1].x[2] == 7){
                solve(v,p+1,S);
            }
        }
        return;
    }
     
    if(d[a][b][c].x[p] == 0){
        if(d[a][b][c].x[5-p] != 0){
            int x = 7 - d[a][b][c].x[5-p];
            if(S >> x & 1) return;
            d[a][b][c].x[p] = x;
            solve(v,p+1,S|(1<<x));
            d[a][b][c].x[p] = 0;
        }else{
            for(int i = 0 ; i < 6 ; i++){
                d[a][b][c].x[p] = i+1;
                int x = d[a][b][c].x[5-p];
                if(!(S >> (i+1) & 1) &&
                   (x == 0 || x + d[a][b][c].x[p] == 7)){
                    solve(v,p+1,S|(1<<(i+1)));
                }
                d[a][b][c].x[p] = 0;
            }
        }
    }else{
        int x = d[a][b][c].x[5-p];
        if(x + d[a][b][c].x[p] == 7){
            solve(v,p+1,S);
        }
    }
}
 
void print(){
    bool sp = false;
    for(int i = 0 ; i < 60 ; i++){
        if(can[i]){
            if(sp) cout << " ";
            sp = true;
            cout << i;
        }
    }
    if(!sp) cout << 0;
    cout << endl;
}
 
void init(){
    fill(bit,bit+27,1);
    memset(can,0,sizeof(can));
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                d[i][j][k].clear();
            }
        }
    }
     
    Dice dice;
    for(int i = 1 ; i <= 6 ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if(i == j) continue;
            dice.roll(i,j);
            d2[i][j] = dice;        
        }
    }
}
 
int main(){
    int N;
    cin >> N;
    while(N--){
        init();
        int in;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                cin >> in;
                if(in != 0){
                    d[0][i][j].x[0] = in;
                    d[0][i][j].x[5] = 7-in;
                    bit[3*i+j] |= 1<<in;
                    bit[3*i+j] |= 1<<(7-in);
                }
            }
        }
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                cin >> in;
                if(in != 0){
                    d[i][2][j].x[1] = in;
                    d[i][2][j].x[4] = 7-in;
                    bit[9*i+6+j] |= 1<<in;
                    bit[9*i+6+j] |= 1<<(7-in);
                }
            }
        }
        solve(0,0,bit[0]);
        print();
    }
    return 0;
}

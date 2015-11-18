#include <bits/stdc++.h>

using namespace std;

template<class T>
class Dice{
private:
  void roll(int a,int b,int c,int d){
    swap(x[a],x[b]);
    swap(x[b],x[d]);
    swap(x[c],x[d]);
  }
public:
  T x[6];
  void roll_N(){ roll(0,1,4,5); }
  void roll_E(){ roll(0,3,2,5); }
  void roll_S(){ roll(0,4,1,5); }
  void roll_W(){ roll(0,2,3,5); }
  void rotation(){ roll(1,2,3,4); }
  void roll(int top,int front){
    for(int i = 0 ; i < 2 ; i++){
      for(int j = 0 ; j < 4 ; j++){
        roll_N();
        if(top == x[0]){ goto next; }
      }
      roll_E();
    }
     next:
    for(int i = 0 ; i < 4 ; i++){
      rotation();
      if(front == x[1]){ break; }
    }
  }
  bool operator == (Dice &d){
    for(int i = 0 ; i < 4 ; i++){
      for(int j = 0 ; j < 4 ; j++){
        d.roll_N();
        bool equals = true;
        for(int k = 0 ; k < 6 ; k++){
          if(x[k] != d.x[k]){
            equals = false;
            break;
          }
        }
        if(equals){ return true; }
      }
      for(int j = 0 ; j < 4 ; j++){
        d.roll_E();
        bool equals = true;
        for(int k = 0 ; k < 6 ; k++){
          if(x[k] != d.x[k]){
            equals = false;
            break;
          }
        }
        if(equals){ return true; }
      }
      d.rotation();
    }
    return false;
  }
  bool operator < (const Dice &d)const{
    for(int i = 0 ; i < 6 ; i++){
      if(x[i] != d.x[i]){ return x[i] < d.x[i]; }
    }
    return false;
  }
};

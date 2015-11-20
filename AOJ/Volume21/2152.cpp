#include <bits/stdc++.h>
  
using namespace std;
  
typedef pair<int,int> P;
vector<P> vec;
  
void change(int p, int S, int l){
    vector<P> tmp;
    int Next = vec[p].second - S;
  
    for(int i = 0 ; i < p ; i++){
	tmp.push_back(vec[i]);
    }
  
    tmp.push_back(P(l, S));
    tmp.push_back(P(-1,Next));
  
    for(int i = p+1 ; i < vec.size() ; i++){
	tmp.push_back(vec[i]);
    }
    vec = tmp;
}
  
void Wri(){
    int len = vec.size(), l, S;
  
    cin >> l >> S;
  
    if(len == 0){
	vec.push_back(P(l,S));
	return;
    }
  
    for(int i = 0 ; i < len ; i++){
	if(vec[i].first == -1){
	    if(S - vec[i].second >= 0){
		vec[i].first = l;
		S -= vec[i].second;
	    }else{
		change(i, S, l);
		return;
	    }
	}
    }
  
    if(S > 0){
	vec.push_back(P(l,S));
    }
}
  
void Del(){
    int len = vec.size(), l;
  
    cin >> l;
    if(len == 0){
	return;
    }
  
    for(int i = 0 ; i < len ; i++){
	if(vec[i].first == l){
	    vec[i].first = -1;
	}
    }
}
  
int Ref(){
    long long cnt = 0;
    int len = vec.size(), l, num = vec[0].first;
  
    cin >> l;
    if(len == 0){
	return -1;
    }
  
    for(int i = 0 ; i < len ; i++){
	cnt += vec[i].second;
	num = vec[i].first;
      
	if(cnt > l){
	    return num;
	}
    }
  
    if(cnt <= l){
	return -1;
    }else{
	return vec[len-1].first;
    }
}
  
int main(){
    int N;
    char ch;
  
    while(cin >> N, N){
	vec.clear();
	for(int i = 0 ; i < N ; i++){
	    cin >> ch;
  
	    switch(ch){
	    case 'W':
		Wri();
		break;
	    case 'D':
		Del();
		break;
	    default:
		cout << Ref() << endl;
		break;
	    }
	}
	cout << endl;
    }
    return 0;
}

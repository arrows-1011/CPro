#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long Int;
 
class Fraction{
public:
    Int numerator,denominator;
};
 
void reduce(Fraction &);
Int gcd(Int,Int);
 
ostream &operator << (ostream &os,Fraction f){
    reduce(f);
    if(f.numerator == 0){
	os << "0";
    }else if(f.denominator == 1){
	os << f.numerator;
    }else{
	os << f.numerator << "/" << f.denominator;
    }
    return os;
}
 
Int gcd(Int a,Int b){
    return (b == 0 ? a : gcd(b,a%b));
}
 
Int lcm(Int a,Int b){
    return a*b/gcd(a,b);
}
 
void reduce(Fraction &f){
    Int x = gcd(f.numerator,f.denominator);
    f.numerator /= x;
    f.denominator /= x;
}
 
Fraction sub(Fraction f,Int num,Int den){
    Fraction g = {num,den}; reduce(g);
    Int nd = lcm(f.denominator,g.denominator);
    f.numerator *= (nd/f.denominator);
    g.numerator *= (nd/g.denominator);
    f.denominator = g.denominator = nd;
    f.numerator -= g.numerator;
    return f;
}
 
Fraction add(Fraction f,Int num,Int den){
    Fraction g = {num,den}; reduce(g);
    Int nd = lcm(f.denominator,g.denominator);
    f.numerator *= (nd/f.denominator);
    g.numerator *= (nd/g.denominator);
    f.denominator = g.denominator = nd;
    f.numerator += g.numerator;
    return f;
}
 
int main(){
    string in;
 
    while(cin >> in, in != "#"){
	string s;
	int size = 0;
	for(int i = 0 ; i < (int)in.size() ; size++){
	    if(in[i] == 'n'){
		s += 'n';
		i += 5;
	    }else{
		s += 'w';
		i += 4;
	    }
	}
	reverse(s.begin(),s.end());
	Fraction f;
	int n = 1;
	if(s[0] == 'n'){
	    f.numerator = 0;
	    f.denominator = 1;
	}else{
	    f.numerator = 90;
	    f.denominator = 1;
	}
	for(int i = 1 ; i < size ; i++,n++){
	    if(s[i] == 'n'){
		f = sub(f,90,(Int)pow(2.,n));
	    }else{
		f = add(f,90,(Int)pow(2.,n));
	    }
	    reduce(f);
	}
	cout << f << endl;
    }
    return 0;
}

#include <iostream>
 
using namespace std;

using ll = long long;

class Fraction {
  public:
    ll numerator, denominator;

    Fraction() {
	numerator = denominator = 1;
    }

    Fraction(ll n, ll d) {
	numerator = n;
	denominator = d;
    }

    ll gcd(ll a, ll b)
    {
	return (b == 0 ? a : gcd(b, a % b));
    }
 
    ll lcm(ll a, ll b)
    {
	return a / gcd(a, b) * b;
    }
 
    Fraction operator - (Fraction g)
    {
	Fraction f = *this;
	f.reduce_d(g);
	f.numerator -= g.numerator;
	return f;
    }

    Fraction operator + (Fraction g)
    {
	Fraction f = *this;
	f.reduce_d(g);
	f.numerator += g.numerator;
	return f;
    }

    Fraction operator * (Fraction f)
    {
	Fraction res;
	res.numerator = numerator * f.numerator;
	res.denominator = denominator * f.denominator;
	res.reduce_n();
	return res;
    }

    Fraction operator / (Fraction f)
    {
	Fraction res;
	res.numerator = numerator * f.denominator;
	res.denominator = denominator * f.numerator;
	res.reduce_n();
	return res;
    }

    bool operator == (const Fraction& f)
    {
	return (numerator == f.numerator &&
		denominator == f.denominator);
    }

    void reduce_n()
    {
	ll x = gcd(numerator, denominator);
	numerator /= x;
	denominator /= x;
    }
  
    void reduce_d(Fraction& f)
    {
	reduce_n(); f.reduce_n();
	ll nd = lcm(denominator, f.denominator);
	numerator *= (nd / denominator);
	f.numerator *= (nd / f.denominator);
	denominator = f.denominator = nd;
    }
};

ostream& operator << (ostream& os, Fraction f)
{
    f.reduce_n();
  
    int sign = 1;
    if (f.numerator < 0) {
	sign *= (-1);
	f.numerator *= (-1);
    }
    if (f.denominator < 0) {
	sign *= (-1);
	f.denominator *= (-1);
    }
    if (f.numerator == 0) {
	os << "0";
    } else if(f.denominator == 1) {
	if (sign == -1) {
            os << "-";
        }
	os << f.numerator;
    } else {
	if (sign == -1) {
            os << "-";
        }
	os << f.numerator << "/" << f.denominator;
    }
    return os;
}

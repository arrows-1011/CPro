#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = (1e-10);

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x{x}, y{y} {}
    
    Point operator + (const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator - (const Point p) const
    {
        return Point(x - p.x, y - p.y);
    }

    Point operator * (const double& k) const
    {
        return Point(x * k, y * k);
    }
    
    Point operator / (const double& k) const
    {
        return Point(x / k, y / k);
    }
};

using Vector = Point;

double dot(const Point& a, const Point& b)
{
    return a.x * b.x + a.y * b.y;
}


double cross(const Point& a, const Point& b)
{
    return a.x * b.y - b.x * a.y;
}

double norm(const Point& p)
{
    return dot(p, p);
}

double abs(const Point& p)
{
    return sqrt(norm(p));
}

struct Line {
    Point s, t;
    Line() {}
    Line(Point s, Point t) : s{s}, t{t} {}
};

Point proj(const Line& s, const Point& p)
{
    Vector b = s.t - s.s;
    double t = dot(p - s.s, b) / norm(b);
    return s.s + b * t;
}

Point refl(const Line& s, const Point& p)
{
    return p + (proj(s, p) - p) * 2.0;
}

Point crosspoint(const Line& a, const Line& b)
{    
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    if (abs(d) < EPS) return b.s;
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

struct Type {
    bool is_point;
    Line l;

    Type() {}
    Type(bool is_point, Line l) :
        is_point{is_point}, l{l} {}
};

struct Parse {
    string s;
    string::iterator it;

    Parse (const string& t) : s{t} {
        it = s.begin();
    }

    double number()
    {
        bool minus = (*it == '-');
        double num = (*it != '-' ? *it - '0' : 0);
        ++it;
        while (isdigit(*it)) {
            num *= 10;
            num += *it - '0';
            ++it;
        }
        if (minus) num *= -1;

        return num;        
    }
    
    Type fact()
    {
        ++it;
        if (isdigit(*it) || *it == '-') {
            double a = number();
            ++it;
            double b = number();
            ++it;
            return {1, Line{Point(a, b), Point{}}};            
        } else {
            Type res = expr();            
            ++it;
            return res;
        }
    }
    
    Type expr()
    {
        Type l = fact(); 
        while (*it == '@') {
            ++it;
            Type r = fact();
            if (l.is_point == 1 && r.is_point == 1) {
                l = {0, Line{l.l.s, r.l.s}};
            } else if (l.is_point == 1 && r.is_point == 0) {
                l = {1, Line{refl(r.l, l.l.s), Point{}}};
            } else if (l.is_point == 0 && r.is_point == 1) {
                l = {1, Line{refl(l.l, r.l.s), Point{}}};
            } else if (l.is_point == 0 && r.is_point == 0) {
                l = {1, Line{crosspoint(l.l, r.l), Point{}}};                
            }
        }        
        return l;
    }
};

int main()
{
    string s;
    while (1) {
        cin >> s;
        if (s == "#") {
            break;
        }
        Parse p{s};
        Type res = p.expr();
        printf("%.15f %.15f\n", res.l.s.x, res.l.s.y);
    }        
    return 0;
}

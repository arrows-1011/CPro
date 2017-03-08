#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = 1e-8;
constexpr double INF = 1LL << 55;

struct Point3D {
    double x, y, z;
    Point3D(){}
    Point3D(double x, double y, double z) : x{x}, y{y}, z{z} {}
  
    Point3D operator + (const Point3D& p) const
    {
        return Point3D(x + p.x, y + p.y, z + p.z);
    }
    
    Point3D operator - (const Point3D& p) const
    {
        return Point3D(x - p.x, y - p.y, z - p.z);
    }
    
    Point3D operator * (double k) const
    {
        return Point3D(x * k, y * k, z * k);
    }    
    
    Point3D operator / (double k) const
    {
        return Point3D(x / k, y / k, z / k);
    }    
};

using Vector3D = Point3D;

istream& operator >> (istream& is, Point3D& p)
{
    return is >> p.x >> p.y >> p.z;
}

double dot(const Point3D& a, const Point3D& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double norm(const Point3D& p)
{
    return dot(p, p);
}

double abs(const Point3D& p)
{
    return sqrt(norm(p));
}

double cross(const Point3D& a, const Point3D& b)
{
    return abs(Point3D(a.y * b.z - a.z * b.y,
                       a.z * b.x - a.x * b.z,
                       a.x * b.y - a.y * b.x));
}

double dist(const Point3D& a, const Point3D& b)
{
    return abs(a - b);
}

constexpr int COUNTER_CLOCKWISE = +1;
constexpr int CLOCKWISE         = -1;
constexpr int ONLINE_BACK       = +2;
constexpr int ONLINE_FRONT      = -2;
constexpr int ON_SEGMENT        = +0;
using Vector3D = Point3D;
 
int ccw(const Point3D& p0, const Point3D& p1, const Point3D& p2)
{
    Vector3D a = p1 - p0;
    Vector3D b = p2 - p0;
    if (abs(cross(a, b)) > EPS)  return COUNTER_CLOCKWISE;
    if (abs(cross(a, b)) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS)        return ONLINE_BACK;
    if (norm(a) < norm(b))       return ONLINE_FRONT;
    return ON_SEGMENT;
}

struct Line {
    Point3D s, t;
    Line() {}
    Line(Point3D s, Point3D t) : s{s}, t{t} {}
};

Point3D proj(const Line &l, const Point3D &p)
{
    Point3D b = l.t - l.s;
    double t = dot(p - l.s, b) / norm(b);
    return l.s + b * t;
}

Point3D refl(const Line& l, const Point3D& p)
{    
    return p + (proj(l, p) - p) * 2.0;
}

double distance_LP(const Line& l, const Point3D& p)
{
    return abs(p - proj(l, p));
}

struct Sphere {
    Point3D p;
    double r;
    Sphere() {}
    Sphere(Point3D p, double r) : p{p}, r{r} {}
};

istream& operator >> (istream& is, Sphere& sp)
{
    return is >> sp.p >> sp.r;
}

bool intersect_SL(const Sphere& s, const Line& l)
{
    return distance_LP(l, s.p) <= s.r + EPS;
}

Point3D crosspoint_SL(const Sphere& s, const Line& l)
{
    Point3D x = proj(l, s.p);
    Vector3D vp = x - s.p;
    Vector3D uv = (l.t - l.s) / abs(l.t - l.s);
    double t = sqrt(s.r * s.r - norm(vp));
    return x - uv * t;
}

int main()
{
    int N;
    while (cin >> N, N > 0) {
        Point3D p, pp{0, 0, 0};
        cin >> p;
        vector<Sphere> sp(N);
        for (int i = 0; i < N; i++) {
            cin >> sp[i];
        }

        Line l{pp, p};
        
        bool update = 1;
        while (update) {
            update = 0;
            
            double min = INF;
            int min_idx = -1;
            Point3D np{};
            
            for (int i = 0; i < N; i++) {
                if (!intersect_SL(sp[i], l)) continue;
                Point3D cp = crosspoint_SL(sp[i], l);

                double d = dist(pp, cp);
                
                if (d < min &&
                    (ccw(l.s, l.t, cp) == ON_SEGMENT || ccw(l.s, l.t, cp) == ONLINE_FRONT)) {
                    min = d;
                    min_idx = i;
                    np = cp;
                }
            }

            if (min_idx != -1) {
                update = 1;

                l = Line{np, refl({np, sp[min_idx].p}, pp)};
                pp = np;
            }
        }
        
        printf("%.15f %.15f %.15f\n", pp.x, pp.y, pp.z);
    }
    return 0;
}

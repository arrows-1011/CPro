#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS (1e-9)
 
struct Point3D {
    double x, y, z;
    Point3D(){}
    Point3D(double x, double y, double z) :
        x(x), y(y), z(z) {}
 
    Point3D operator + (const Point3D &p) const {
        return Point3D(x + p.x, y + p.y, z + p.z);
    }
 
    Point3D operator - (const Point3D &p) const {
        return Point3D(x - p.x, y - p.y, z - p.z);
    }
   
    Point3D operator * (double k) const {
        return Point3D(x * k, y * k, z * k);
    }
 
    Point3D operator / (double k) const {
        return Point3D(x / k, y / k, z / k);
    }
};
 
typedef Point3D Vector;
 
double dot(const Point3D &a, const Point3D &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
 
double norm(const Point3D &p)
{
    return dot(p, p);
}
 
double abs(const Point3D &p)
{
    return sqrt(norm(p));
}
 
double cross(const Point3D &a, const Point3D &b)
{
    return abs(Point3D(a.y * b.z - a.z * b.y, 
                       a.z * b.x - a.x * b.z, 
                       a.x * b.y - a.y * b.x));
}
 
struct Sphere {
    Point3D p;
    double r;
    Sphere(){}
    Sphere(Point3D p, double r) : p(p), r(r) {}
};
 
int ccw(const Point3D &p0, const Point3D &p1, const Point3D &p2)
{
    Vector a = p1 - p0, b = p2 - p0;
    if (abs(cross(a, b)) > EPS) return +1;
    if (abs(cross(a, b)) < -EPS) return -1;
    if (dot(a, b) < -EPS) return +2;
    if (norm(a) < norm(b)) return -2;
    return +0;
}
 
struct Segment {
    Point3D s, t;
    Segment () {}
    Segment(Point3D s, Point3D t) :
        s(s), t(t) {}
};
 
Point3D projection(const Segment &s, const Point3D &p)
{
    Point3D b = s.t - s.s;
    double t = dot(p - s.s, b) / norm(b);
    return s.s + b * t;
}
 
double distanceSP(const Segment &s, const Point3D &p)
{
    return abs(p - projection(s, p));
}
 
bool is_intersectSS(const Sphere &c, const Segment &l)
{
    vector<Point3D> vec;
    double d = distanceSP(l, c.p);
    if (d < c.r) {
        Point3D p = projection(l, c.p);
        Point3D v = (l.t - l.s) / abs(l.t - l.s);
        d = sqrt(c.r * c.r - d * d);
        vec.push_back(p - v * d);
        vec.push_back(p + v * d);
        for (int i = 0; i < (int)vec.size(); i++) {
            if (ccw(l.s, l.t, vec[i]) == 0) {
                return true;
            }
        }
    }
    return false;
}
 
struct Light {
    Point3D p;
    double b;
    Light(){}
    Light(Point3D p, double b) : p(p), b(b) {}
};
 
double get_point(const Point3D &E, const Light &T)
{
    return T.b / ((T.p.x - E.x)*(T.p.x - E.x) + (T.p.y - E.y)*(T.p.y - E.y) + (T.p.z - E.z)*(T.p.z - E.z));
}
 
void merge(set<int> &u, set<int> &v)
{
    for (set<int>::iterator it = v.begin(); it != v.end(); ++it) {
        u.insert(*it);
    }
}

int main()
{
    int N, M, R;
    while (cin >> N >> M >> R, N) {
        vector<Sphere> sphs(N);
        for (int i = 0; i < N; i++) {
            cin >> sphs[i].p.x >> sphs[i].p.y >> sphs[i].p.z >> sphs[i].r;
        }
        vector<Light> ligs(M);
        for (int i = 0; i < M; i++) {
            cin >> ligs[i].p.x >> ligs[i].p.y >> ligs[i].p.z >> ligs[i].b;
        }
 
        Point3D E;
        cin >> E.x >> E.y >> E.z;    
        
        double res = 0;
        for (int i = 0; i < (1<<M); i++) {
            double point = 0;
            for (int j = 0; j < M; j++) {
                if (!(i >> j & 1)) continue;
                point += get_point(E, ligs[j]);
            }

            if (point < res) continue;
            
            set<int> used;
            for (int j = 0; j < M; j++) {
                if (!(i >> j & 1)) continue;
                Segment s(E, ligs[j].p);
                for (int k = 0; k < N; k++) {
                    if (is_intersectSS(sphs[k], s)) {
                        used.insert(k);
                    }
                }
                if ((int)used.size() > R) {
                    break;
                }                               
            }
            if ((int)used.size() <= R) {
                res = point;
            }
        }
        printf("%.10f\n", res);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = 1e-10;

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y) : x{x}, y{y} {}

    Point operator - (const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }
};

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

constexpr int COUNTER_CLOCKWISE = +1;
constexpr int CLOCKWISE         = -1;
constexpr int ONLINE_BACK       = +2;
constexpr int ONLINE_FRONT      = -2;
constexpr int ON_SEGMENT        = +0;
using Vector = Point;

int ccw(const Point& p0, const Point& p1, const Point& p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS)  return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS)   return ONLINE_BACK;
    if (norm(a) < norm(b))  return ONLINE_FRONT;
    return ON_SEGMENT;
}

using Polygon = vector<Point>;

bool sortY(Point p1, Point p2)
{
    if (p1.y != p2.y) {
	return (p1.y - p2.y < -EPS);
    } else { 
	return (p1.x - p2.x < -EPS);
    }
}

Polygon convex_hull(Polygon &ps)
{
    int N = ps.size(), j = 0;
    Polygon pg(N * 2);
    sort(ps.begin(), ps.end(), sortY);
    for (int i = 0; i < N; i++) {
        while (j > 1 && cross(pg[j - 1] - pg[j - 2], ps[i] - pg[j - 1]) <= 0) {
            j--;
        }
        pg[j++] = ps[i];
    }
    int k = j;
    for (int i = N - 2; i >= 0; i--) {
        while (j > k && cross(pg[j - 1] - pg[j - 2], ps[i] - pg[j - 1]) <= 0) {
            j--;
        }
        pg[j++] = ps[i];
    }
    pg.resize(j - 1);
    return pg;
}

double area(const Polygon& pg)
{
    int N = pg.size();
    double res = 0;
    for (int i = 0; i < N; i++) {
	res += cross(pg[i], pg[(i + 1) % N]);
    }
    return abs(res) / 2.0;
}

bool pass_snake(const vector<Point>& ps)
{
    int N = ps.size();
    Polygon p;
    double curr = 0, prev = 0;
    
    for (int i = 0; i < N; i++) {
        p.emplace_back(ps[i]);
        
        if (i >= 2) {            
            p = convex_hull(p);
            curr = area(p);

            if (abs(curr - prev) < EPS) {
                return 0;
            }
        
            prev = curr;
        }
    }
    
    return 1;
}

int main()
{
    int N;
    cin >> N;
    vector<Point> ps(N);
    for (int i = 0; i < N; i++) {
        cin >> ps[i].x >> ps[i].y;
    }
    
    bool poss = 1;
    for (int i = 0; i < 2; i++) {
        poss &= pass_snake(ps);
        reverse(ps.begin(), ps.end());
    }

    cout << (poss ? "Possible" : "Impossible") << endl;
    return 0;
}

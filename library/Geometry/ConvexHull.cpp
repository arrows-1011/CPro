/*
  凸包を求める.
  凸包とは、点集合Pの全ての点を含む最小の凸多角形のこと.
  O(N log N)
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define PI acos(-1)

struct Point{
  double x,y;

  Point(){}
  Point(double x,double y) : x(x),y(y) {}

  Point operator + (const Point &p)const{
    return Point(x + p.x , y + p.y);
  }

  Point operator - (const Point &p)const{
    return Point(x - p.x , y - p.y);
  }

  Point operator * (const double &k)const{
    return Point(x * k , y * k);
  }

  Point operator / (const double &k)const{
    return Point(x / k , y / k);
  }

  double dot(const Point &p)const{
    return x*p.x + y*p.y;
  }

  double cross(const Point &p)const{
    return x*p.y - p.x*y;
  }

  double dist(const Point &p)const{
    return sqrt(pow(x-p.x,2) + pow(y-p.y,2));
  }

  double norm(){
    return x*x + y*y;
  }

  double Abs(){
    return sqrt(norm());
  }
};

#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
typedef Point Vector;

int ccw(Point p0,Point p1,Point p2){
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if(a.cross(b) > EPS){ return COUNTER_CLOCKWISE; }
  if(a.cross(b) < -EPS){ return CLOCKWISE; }
  if(a.dot(b) < -EPS){ return ONLINE_BACK; }
  if(a.norm() < b.norm()){ return ONLINE_FRONT; }
  return ON_SEGMENT;
}

bool sortX(Point p1,Point p2){
  if(p1.x != p2.x){ 
    return (p1.x - p2.x < -EPS);
  }else{
    return (p1.y - p2.y < -EPS);
  }
}

bool sortY(Point p1,Point p2){
  if(p1.y != p2.y){
    return (p1.y - p2.y < -EPS);
  }else{ 
    return (p1.x - p2.x < -EPS);
  }
}

typedef vector<Point> Polygon;

Polygon convex_hull(Polygon &ps){
  int N = ps.size(),j = 0;
  Polygon pg(N*2);
  sort(ps.begin(),ps.end(),sortY);
  for(int i = 0 ; i < N ; i++,j++){
    while(j >= 2 && ccw(pg[j-2],pg[j-1],ps[i]) == -1){
      j--;
    }
    pg[j] = ps[i];
  }
  int k = j+1;
  for(int i = N-2 ; i >= 0 ; i--,j++){
    while(j >= k && ccw(pg[j-2],pg[j-1],ps[i]) == -1){
      j--;
    }
    pg[j] = ps[i];
  }
  pg.resize(j-1);
  return pg;
}

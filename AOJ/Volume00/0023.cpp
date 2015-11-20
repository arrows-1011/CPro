#include <iostream>
#include <cmath>

using namespace std;

struct data1{
    double x,y,r;
} circle1;
     
struct data2{
    double x,y,r;
} circle2;

double distance(double px,double py,double qx,double qy){
    return sqrt(pow(py-qy,2)+pow(px-qx,2));
}

int main(){
    int n;
 
    cin >> n;
    while(n--){
        cin >> circle1.x >> circle1.y >> circle1.r;
        cin >> circle2.x >> circle2.y >> circle2.r;
         
        double d = distance(circle1.x,circle1.y,circle2.x,circle2.y);
         
        if(circle1.r + circle2.r < d){
	    cout << "0" << endl;
        }else if(circle2.r + d < circle1.r){
	    cout << "2" << endl;
        }else if(circle1.r + d < circle2.r){
	    cout << "-2" << endl;
        }else{
	    cout << "1" << endl;
	}
    }
    return 0;
}

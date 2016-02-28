#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated, BoxesDestroyed;

class Box
{
  private:
    int l, b, h;
    
  public:
    Box(){
        l = b = h = 0;
        ++BoxesCreated;
    }

    Box(int length, int breadth, int height){
        l = length;
        b = breadth;
        h = height;
        ++BoxesCreated;
    }

    Box(const Box &B){
        l = B.l;
        b = B.b;
        h = B.h;
        ++BoxesCreated;
    }

    ~Box(){
        ++BoxesDestroyed;
    }
    
    int getLength(){
        return l;
    }

    int getBreadth(){
        return b;
    }

    int getHeight(){
        return h;
    }

    long long CalculateVolume(){
        return (long long)l * (long long)b * (long long)h;
    }
};

bool operator < (Box A, Box B) {
    int al = A.getLength();
    int ab = A.getBreadth();
    int ah = A.getHeight();

    int bl = B.getLength();
    int bb = B.getBreadth();
    int bh = B.getHeight();

    if (al != bl) {
        return al < bl;
    } else if (ab != bb) {
        return ab < bb;
    } else if(ah != bh) {
        return ah < bh;
    }
    return 0;
}

ostream& operator << (ostream &os, Box &B){
    int l = B.getLength();
    int b = B.getBreadth();
    int h = B.getHeight();
    return os << l << " " << b << " " << h;
}

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0 ; i < n ; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cout << temp << endl;
        }
        if (type == 2) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                cout << "Lesser" << endl;
            } else {
                cout << "Greater" << endl;
            }
        }
        if (type == 4) {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5) {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout << "Boxes Created : " << BoxesCreated << endl
         << "Boxes Destroyed : " << BoxesDestroyed << endl;
    return 0;
}

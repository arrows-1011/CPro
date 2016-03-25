#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

#define EPS 1e-3
#define INF (1<<29)
#define equals(a, b) (fabs(a - b) < EPS)

struct Country {
    int f, a, x, y, i;
    Country(){}
    Country(int f, int a, int x, int y, int i) :
        f(f), a(a), x(x), y(y), i(i) {}
};

double get_distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    int N, f, a, t, x, y;    
    std::cin >> N;
    std::vector<Country> country[2];
    for (int i = 0; i < N; i++) {
        std::cin >> f >> a >> t >> x >> y;
        country[t].push_back(Country(f, a, x, y, i));
    }
    
    double max_dist[2], min_time[2];
    for (int i = 0; i < 2; i++) {
        size_t size = country[i].size();
        max_dist[i] = -1;
        min_time[i] = INF;
        if (size > 1) {         
            for (size_t j = 0; j < size-1; j++) {            
                Country c1 = country[i][j], c2 = country[i][j+1];
                if (c1.a == c2.a || c2.i - c1.i != 1) {
                    continue;
                }                
                double ndist = get_distance(c1.x, c1.y, c2.x, c2.y);
                double ntime = (c2.f - c1.f) / 60.0;
                if (ndist > max_dist[i]) {
                    max_dist[i] = ndist;                    
                    min_time[i] = ntime;
                } else if (equals(ndist, max_dist[i])) {
                    if (ntime < min_time[i]) {
                        min_time[i] = ntime;
                    }
                }
            }
        }
        if (max_dist[i] == -1) {
            std::cout << -1 << " " << -1 << std::endl;
        } else {
            printf("%.10f %.10f\n", max_dist[i], min_time[i]);
        }
    }
    return 0;
}

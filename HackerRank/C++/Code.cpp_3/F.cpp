#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Workshop
{
    int start_time, duration;    
};

struct Available_Workshops
{
    int N;
    Workshop *arr;
};

Available_Workshops* initialize(int *start_time,
                                int *duration,
                                int N){
    Available_Workshops *aw = new Available_Workshops;
    aw->arr = new Workshop[N];
    aw->N = N;
    for (int i = 0 ; i < N ; i++) {
        aw->arr[i].start_time = start_time[i];
        aw->arr[i].duration = duration[i];
    }
    return aw;
}


int CalculateMaxWorkshops(Available_Workshops *ptr){
    vector<pair<int,int> > v(ptr->N);
    for (int i = 0 ; i < ptr->N ; i++) {
        v[i].first = ptr->arr[i].start_time + ptr->arr[i].duration;
        v[i].second = ptr->arr[i].start_time;
    }
    sort(v.begin(), v.end());
    int mx = 0, t = 0;
    for (int i = 0 ; i < ptr->N ; i++) {
        if (t <= v[i].second) {
            ++mx;
            t = v[i].first;
        }
    }
    return mx;
}

int main()
{
    int n;
    cin >> n;
    int start_time[n], duration[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> start_time[i];
    }
    for (int i = 0 ; i < n ; i++) {
        cin >> duration[i];
    }
    
    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

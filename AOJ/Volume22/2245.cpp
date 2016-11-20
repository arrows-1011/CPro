#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

bool is_goal(const string& c)
{
    bool front = 0, back = 0;
    if (c[6] == '*' || c[7] == '*' || c[8] == '*') {
        front = 1;
    }

    if (c[24] == '*' || c[25] == '*' || c[26] == '*') {
        back = 1;
    }
    
    return front & back;
}

string rotate(const string& c, int dir)
{
    string nc = c;
    char tmp;
    vector<int> d, e, id;
    
    switch (dir) {
        case 0: // left
            d  = {-3, +1, +3, -1};
            e  = {+1, +3, -1, -3};            
            id = {33, 36, 11, 53};
            
            tmp   = nc[0];
            nc[0] = nc[2];
            nc[2] = nc[8];
            nc[8] = nc[6];
            nc[6] = tmp;
            
            tmp   = nc[1];
            nc[1] = nc[5];
            nc[5] = nc[7];
            nc[7] = nc[3];
            nc[3] = tmp;

            tmp    = nc[18];
            nc[18] = nc[24];
            nc[24] = nc[26];
            nc[26] = nc[20];
            nc[20] = tmp;

            tmp    = nc[19];
            nc[19] = nc[21];
            nc[21] = nc[25];
            nc[25] = nc[23];
            nc[23] = tmp;            
            break;
        case 1: // back
            d  = {-3, +3, +3, +3};
            e  = {+1, -1, -1, -1};
            id = {24, 38, 2, 47};

            tmp    = nc[9];
            nc[9]  = nc[15];
            nc[15] = nc[17];
            nc[17] = nc[11];
            nc[11] = tmp;

            tmp    = nc[10];
            nc[10] = nc[12];
            nc[12] = nc[16];
            nc[16] = nc[14];
            nc[14] = tmp;

            tmp    = nc[27];
            nc[27] = nc[29];
            nc[29] = nc[35];
            nc[35] = nc[33];
            nc[33] = tmp;

            tmp    = nc[28];
            nc[28] = nc[32];
            nc[32] = nc[34];
            nc[34] = nc[30];
            nc[30] = tmp;            
            break;
        case 2: // right
            d  = {-3, -1, +3, +1};
            e  = {+1, -3, -1, +3};
            id = {15, 44, 29, 45};

            tmp   = nc[0];
            nc[0] = nc[6];
            nc[6] = nc[8];
            nc[8] = nc[2];
            nc[2] = tmp;

            tmp   = nc[1];
            nc[1] = nc[3];
            nc[3] = nc[7];
            nc[7] = nc[5];
            nc[5] = tmp;

            tmp    = nc[18];
            nc[18] = nc[20];
            nc[20] = nc[26];
            nc[26] = nc[24];
            nc[24] = tmp;

            tmp    = nc[19];
            nc[19] = nc[23];
            nc[23] = nc[25];
            nc[25] = nc[21];
            nc[21] = tmp;            
            break;
        case 3: // front            
            d  = {-3, -3, +3, -3};
            e  = {+1, +1, -1, +1};
            id = {6, 42, 20, 51};
            
            tmp    = nc[9];
            nc[9]  = nc[11];
            nc[11] = nc[17];
            nc[17] = nc[15];
            nc[15] = tmp;

            tmp    = nc[10];
            nc[10] = nc[14];
            nc[14] = nc[16];
            nc[16] = nc[12];
            nc[12] = tmp;

            tmp    = nc[27];
            nc[27] = nc[33];
            nc[33] = nc[35];
            nc[35] = nc[29];
            nc[29] = tmp;

            tmp    = nc[28];
            nc[28] = nc[30];
            nc[30] = nc[34];
            nc[34] = nc[32];
            nc[32] = tmp;            
            break;
    }
    
    for (int i = 0; i < 3; i++) {
        auto nid = id;
        for (int j = 0; j < 3; j++) {
            tmp        = nc[nid[0]];
            nc[nid[0]] = nc[nid[1]];
            nc[nid[1]] = nc[nid[2]];
            nc[nid[2]] = nc[nid[3]];
            nc[nid[3]] = tmp;
            for (int k = 0; k < 4; k++) {
                nid[k] += d[k];
            }
        }
        for (int j = 0; j < 4; j++) {
            id[j] += e[j];
        }
    }
                 
    return nc;
}

int bfs(const string& cube)
{
    queue<string> que;
    que.push(cube);

    map<string, int> d;
    d[cube] = 0;

    while (!que.empty()) {
        auto c = que.front(); que.pop();
        if (is_goal(c)) {
            return d[c];
        }

        for (int i = 0; i < 4; i++) {
            auto nc = rotate(c, i);
            if (d.count(nc) == 0) {
                d[nc] = d[c] + 1;
                que.push(nc);
            }               
        }
    }   
    return -1;
}

int main()
{
    string s[3];
    while (cin >> s[0], s[0] != "#") {
        string cube;
        for (int i = 0; i < 6; i++) {
            for (int j = (i == 0); j < 3; j++) {
                cin >> s[j];
            }
            for (int j = 0; j < 3; j++) {
                cube += s[j];
            }
        }
        cout << bfs(cube) << endl;
    }        
    return 0;
}

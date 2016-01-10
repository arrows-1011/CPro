#include <iostream>
#include <vector>

using namespace std;

const string face[9][5] =
{
    {
        {"....."},
        {"...|."},
        {"....."},
        {"...|."},
        {"..-.."}
    },
            
    {
        {"..-.."},
        {"...|."},
        {"..-.."},
        {".|..."},
        {"..-.."}
    },

    {
        {"..-.."},
        {"...|."},
        {"..-.."},
        {"...|."},
        {"..-.."}
    },

    {
        {"....."},
        {".|.|."},
        {"..-.."},
        {"...|."},
        {"....."}
    },

    {
        {"..-.."},
        {".|..."},
        {"..-.."},
        {"...|."},
        {"..-.."}
    },

    {
        {"..-.."},
        {".|..."},
        {"..-.."},
        {".|.|."},
        {"..-.."}
    },

    {
        {"..-.."},
        {"...|."},
        {"....."},
        {"...|."},
        {"....."}
    },

    {
        {"..-.."},
        {".|.|."},
        {"..-.."},
        {".|.|."},
        {"..-.."}
    },

    {
        {"..-.."},
        {".|.|."},
        {"..-.."},
        {"...|."},
        {"..-.."}
    }
};

typedef vector<int> vi;
typedef vector<string> vs;

vs rotate90(vs v)
{
    vs v90(5);
    for(int i = 0 ; i < 5 ; i++){
        string s;
        for(int j = 0 ; j < 5 ; j++){
            char t = v[j][4-i];
            if(t == '|') t = '-';
            else if(t == '-') t = '|';
            s += t;
        }
        v90[i] = s;
    }
    return v90;
}

vs mirror_lr(vs v)
{
    vs v_lr(5);
    for(int i = 0 ; i < 5 ; i++){
        string s;
        for(int j = 0 ; j < 5 ; j++){
            s += v[i][4-j];
        }
        v_lr[i] = s;
    }
    return v_lr;
}

vs mirror_ud(vs v)
{
    vs v_ud(5);
    for(int i = 0 ; i < 5 ; i++){
        string s;
        for(int j = 0 ; j < 5 ; j++){
            s += v[4-i][j];
        }
        v_ud[i] = s;
    }
    return v_ud;
}

int main()
{
    string s[21];
    while(cin >> s[0], s[0] != "0")
    {
        for(int i = 1 ; i < 21 ; i++){
            cin >> s[i];
        }
        vs d[2][6];
        const int dx[6] = {8, -7, 7, 7, 7, -14};
        const int dy[6] = {1, 7, 0, 0, 0, 7};
        int x = 0, y = 0;
        for(int i = 0 ; i < 6 ; i++)
        {
            x += dx[i]; y += dy[i];
            for(int j = 0 ; j < 5 ; j++)
            {
                string t1, t2;
                for(int k = 0 ; k < 5 ; k++)
                {
                    t1 += s[y+j][x+k];
                    t2 += s[y+j][x+k+29];
                }
                d[0][i].push_back(t1);
                d[1][i].push_back(t2);
            }
        }
        for(int i = 0 ; i < 6 ; i++)
        {
            for(int j = 0 ; j < 2 ; j++)
            {
                if(i == 3){
                    d[j][i] = rotate90(d[j][i]);
                }
                if(i == 1){
                    for(int k = 0 ; k < 3 ; k++){
                        d[j][i] = rotate90(d[j][i]);
                    }
                }                  
                d[j][i] = mirror_lr(d[j][i]);
                if(i == 5){
                    d[j][i] = mirror_ud(d[j][i]);
                }
            }
        }

        auto getNum = [=](vs v[6])
            {
                vi nums(6);
                for(int i = 0 ; i < 6 ; i++)
                {
                    for(int f = 0 ; f < 9 ; f++)
                    {
                        bool found = 1;
                        for(int j = 0 ; j < 5 ; j++){
                            if(v[i][j] != face[f][j]){
                                found = 0;
                                break;
                            }                           
                        }
                        if(found){
                            nums[i] = f+1;
                            break;
                        }
                    }
                }                   
                return nums;
            };
        
        vi v1 = getNum(d[0]);
        vi v2 = getNum(d[1]);

        int h = 0, l = 0;
        for(int i = 0 ; i < 6 ; i++){
            for(int j = 0 ; j < 6 ; j++){
                if(v1[i] > v2[j]) h++;
                if(v1[i] < v2[j]) l++;
            }
        }
        cout << (h >= l ? "HIGH" : "LOW") << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Panel {
    string name;
    int x1, y1, x2, y2;
    vector<Panel> child;
    
    Panel(){}    
    Panel(string name, int x1, int y1, int x2, int y2) :
        name(name), x1(x1), y1(y1), x2(x2), y2(y2) {}
};

string s;
int idx;

string get_name()
{
    string name;
    ++idx;
    while (s[idx] != '>') {
        name += s[idx];
        ++idx;
    }
    ++idx;
    return name;
}

int s2i(string &str)
{
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

int get_val()
{
    string val;
    while (isdigit(s[idx])) {
        val += s[idx];
        ++idx;
    }
    return s2i(val);
}

void parse(Panel &p)
{
    while (s[idx] == '<' && s[idx+1] != '/') {
        string name = get_name();
        int x1 = get_val(); ++idx;
        int y1 = get_val(); ++idx;
        int x2 = get_val(); ++idx;
        int y2 = get_val();
        Panel panel(name, x1, y1, x2, y2);
        parse(panel);
        p.child.push_back(panel);
        while (s[idx] != '>') {
            idx++;
        }
        idx++;
    }    
}

bool get_panel(int x, int y, const Panel &p)
{
    for (int i = 0; i < (int)p.child.size(); i++) {
        Panel np = p.child[i];
        if (np.x1 <= x && x <= np.x2 && np.y1 <= y && y <= np.y2) {
            if (!get_panel(x, y, np)) {
                cout << np.name << " " << np.child.size() << endl;
            }
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, x, y;
    while (cin >> n >> s, n) {
        Panel p;
        p.name = "#"; p.x1 = p.y1 = -1; p.x2 = p.y2 = 10001;
        idx = 0;
        parse(p);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (!get_panel(x, y, p)) {
                cout << "OUT OF MAIN PANEL 1" << endl;
            }
        }
    }
    return 0;
}

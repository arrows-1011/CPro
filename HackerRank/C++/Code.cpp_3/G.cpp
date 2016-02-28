#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    vector<string> line(N);
    stack<string> tags;

    map<string, map<string, string> > eles;
    map<string, vector<string> > next;
    int depth = 0;

    tags.push("#ROOT#");
    
    for (int i = 0 ; i < N ; i++) {
        getline(cin, line[i]);
        string tag;
        stringstream ss(line[i]);
        ss >> tag;
        tag = tag.substr(1);
            
        if (tag[0] == '/') {
            tags.pop();
            depth--;
        } else {
            if (tag[tag.size()-1] == '>') {
                tag.pop_back();
            }
            next[tags.top()].push_back(tag);    
            tags.push(tag);
            string attr, eq, value;
            while (ss >> attr) {
                ss >> eq;
                ss >> value;
                
                value = value.substr(1);
                value.pop_back();
                if (value[value.size()-1] == '\"') {
                    value.pop_back();
                }
                
                eles[tag][attr] = value;
            }
        }
    }

    tags.pop();
    
    auto search = [](vector<string> next, string s){
        for (auto str : next) {
            if (str == s) {
                return true;
            }
        }
        return false;
    };
    
    string str;
    for (int i = 0 ; i < Q ; i++) {
        cin >> str;
        size_t idx = 0, size = str.size();
        string s, prev = "#ROOT#";
        
        bool found = 1;
        for ( ; idx < size ; idx++) {
            if (str[idx] == '.' || str[idx] == '~') {
                if (!search(next[prev], s)) {
                    cout << "Not Found!" << endl;
                    found = 0;
                    break;
                }
                prev = s;
                if (str[idx] == '~') {
                    idx++;
                    break;
                }
                s.clear();
                idx++;
            }
            s += str[idx];
        }

        if (!found) {
            continue;
        }
        
        string value;
        for ( ; idx < size ; idx++) {
            value += str[idx];
        }
        if (eles[s].count(value) > 0) {
            cout << eles[s][value] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
        
    }
    return 0;
}

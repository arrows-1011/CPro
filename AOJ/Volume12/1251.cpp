#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

struct Dir
{
    string name;
    set<string> files;
    Dir *par;
    map<string, Dir> children;

    Dir(){
	par = NULL;
	children.clear();
        files.clear();
    }

    void add(vector<string> path)
    {
        Dir *d = this;
        size_t idx = 0;
        while(idx < path.size() && d->children.count(path[idx]) > 0){
            d = &d->children[path[idx]];
            idx++;
        }
        while(idx < path.size()-1){
            Dir _dir;
            _dir.par = d;
            _dir.name = path[idx];
                
            d->children[path[idx]] = _dir;
            d = &d->children[path[idx]];
            idx++;
        }        
        d->files.insert(path[idx]);
    }

    vector<string> getAbsPath(vector<string> path)
    {
        Dir *now = this;
        vector<string> absPath;
        for(size_t i = 0 ; i < path.size()-1 ; i++){
            if(path[i] == ".") continue;
            if(path[i] == ".."){
                if(now->name == "root") return vector<string>();
                now = now->par;
                absPath.pop_back();
            }else{
                if(now->children.count(path[i]) == 0){
                    return vector<string>();
                }
                now = &now->children[path[i]];
                absPath.push_back(path[i]);
            }
        }

        if(now->files.count(path[path.size()-1]) > 0){
            absPath.push_back(path[path.size()-1]);
        }else{
            return vector<string>();
        }
        return absPath;   
    }
};

vector<string> getPath(string s)
{
    s = s.substr(1);
    if(s.size() == 0){
        vector<string> v;
        v.push_back("index.html");
        return v;
    }
        
    if(s[s.size()-1] == '/'){
        s += "index.html/";
    }else{
        s += "/";
    }
    
    string str;
    stringstream ss(s);
    vector<string> res;
    while(getline(ss, str, '/')){
	res.push_back(str);
    }
    return res;
}

int main()
{
    int N, M;    
    while(cin >> N >> M, N){
	string str;
	Dir root;
        root.name = "root";
	for(int i = 0 ; i < N ; i++){
	    cin >> str;
	    root.add(getPath(str));
	}

	string a, b;
	for(int i = 0 ; i < M ; i++){
	    cin >> a >> b;
            vector<string> pa[2];
            pa[0] = pa[1] = getPath(a);
            pa[1].push_back("index.html");
            
            vector<string> pb[2];
            pb[0] = pb[1] = getPath(b);
            pb[1].push_back("index.html");
            
            pa[0] = root.getAbsPath(pa[0]);
            pa[1] = root.getAbsPath(pa[1]);
            pb[0] = root.getAbsPath(pb[0]);
            pb[1] = root.getAbsPath(pb[1]);
           
            bool flg = 0;
            if(a[a.size()-1] == '/' && pa[1].size() > 0){
                pa[1].pop_back();
                if(pa[0].size() == 0) flg = 1;
            }

            if(b[b.size()-1] == '/' && pb[1].size() > 0){
                pb[1].pop_back();
                if(pb[0].size() == 0) flg = 1;
            }

            if(flg){
                cout << "not found" << endl;
                continue;
            }
            
            bool equals = 0, found = 0;
            for(int i = 0 ; i < 2 ; i++){
                for(int j = 0 ; j < 2 ; j++){
                    if(pa[i].size() == 0 ||
                       pb[j].size() == 0){
                        continue;
                    }
                    found = 1;
                    if(pa[i] == pb[j]){
                        equals = 1;
                    }
                }
            }
            
            if(!found){
                cout << "not found" << endl;
            }else{
                cout << (equals ? "yes" : "no") << endl;
            }
	}
    }
    return 0;
}

/*
1 4
/index.html/index.html
/
/index.html/index.html
/index.html
/index.html/index.html
/..
/index.html/../..
/index.html/
/index.html/index.html/..
0 0

このケースの2つ目の
/index.html
/index.html/index.html
はなぜ同じなのか?

おそらく、
/index.html のindex.html
は、
/index.html とファイルとみるか
/index.html/index.html とディレクトリとみるか
の2通りある.
 */

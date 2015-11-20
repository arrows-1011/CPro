#include <bits/stdc++.h>
 
using namespace std;
 
class Book{
public:
    string title,author;
    int date;
};
 
int getDate(string &s){
    for(int i = 0 ; i < (int)s.size() ; i++){
	if(s[i] == '/'){
	    s[i] = ' ';
	}
    }
    int y,m,d;
    stringstream ss(s);
    ss >> y; ss >> m; ss >> d;
    return y*10000 + m*100 + d;
}
 
int main(){
    int N;
    string str;
    bool blank = false;
    cin >> N;
    vector<Book> books(N);
    for(int i = 0 ; i < N ; i++){
	cin >> books[i].title >> books[i].author >> str;
	books[i].date = getDate(str);
    }
    int Q;
    cin >> Q;
    while(Q--){
	if(blank) cout << endl;
	blank = true;
	string s[4];
	int S = 0;
	for(int i = 0 ; i < 4 ; i++){
	    cin >> s[i];
	    if(s[i] == "*"){
		S |= (1<<i);
	    }
	}
	vector<string> res;
	for(int i = 0 ; i < N ; i++){
	    bool ok = true;
	    for(int j = 0 ; j < 4 ; j++){
		if(S >> j & 1) continue;
		if(j == 0){
		    if(books[i].title.find(s[j]) == string::npos){
			ok = false;
		    }
		}else if(j == 1){
		    if(books[i].author.find(s[j]) == string::npos){
			ok = false;
		    }
		}else if(j == 2){
		    int date = getDate(s[j]);
		    if(date > books[i].date){
			ok = false;
		    }
		}else{
		    int date = getDate(s[j]);
		    if(books[i].date > date){
			ok = false;
		    }
		}
	    }
	    if(ok){
		res.push_back(books[i].title);
	    }
	}
	for(auto x : res){
	    cout << x << endl;
	}
    }
    return 0;
}

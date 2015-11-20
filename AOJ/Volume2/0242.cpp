#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N;
    char ch;
 
    while(cin >> N, N){
	bool found[26];
	map<char,map<string,int> > data;
	string str,word;
	set<string> st;
 
	cin.ignore();
	memset(found, false, sizeof(found));
	for(int i = 0 ; i < N ; i++){
	    getline(cin,str);
	    stringstream s(str);
	    while(s >> word){
		if(st.find(word) == st.end()){
		    st.insert(word);
		    data[word[0]][word] = 1;
		    found[word[0]-'a'] = true;
		}else{
		    ++data[word[0]][word];
		}
	    }
	}
	cin >> ch;
	if(!found[ch-'a']){
	    cout << "NA" << endl;
	}else{
	    bool space = false;
	    map<string,int> m = data[ch];
	    map<string,int>::iterator it;
	    vector<pair<int,string> > vec;
	    for(it = m.begin() ; it != m.end() ; ++it){
		vec.push_back(pair<int,string>(-it->second,it->first));
	    }
	    sort(vec.begin(),vec.end());
	    for(int i = 0 ; i < vec.size(); i++){
		if(i == 5) break;
		if(space) cout << " ";
		cout << vec[i].second;
		space = true;
	    }
	    cout << endl;
	}    
    }
    return 0;
}

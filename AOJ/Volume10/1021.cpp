#include <bits/stdc++.h>
 
using namespace std;
 
struct Emacs{
    int line,column;
    string buffer;
    vector<string> text;
 
    void editText(){
	for(int i = 0 ; i < (int)text.size() ; i++){
	    if(isEmptyLine(i)){ text[i].empty(); }
	}
    }
 
    void order(char command){
	editText();
	switch(command){
	case 'a': funcA(); break;
	case 'e': funcE(); break;
	case 'p': funcP(); break;
	case 'n': funcN(); break;
	case 'f': funcF(); break;
	case 'b': funcB(); break;
	case 'd': funcD(); break;
	case 'k': funcK(); break;
	case 'y': funcY(); break;
	}
    }
 
    bool isEmptyLine(int l){
	for(int i = 0 ; i < (int)text[l].size() ; i++){
	    if(text[l][i] != ' '){ return false; }
	}
	return true;
    }
 
    void funcA(){
	column = 0;
    }
   
    void funcE(){
	column = text[line].size();
    }
 
    void funcP(){
	if(line > 0){ line--; }
	column = 0;
    }
 
    void funcN(){
	if(line+1 < (int)text.size()){ line++; }
	column = 0;
    }
 
    void funcF(){
	if(column == (int)text[line].size()){
	    funcN();
	}else{
	    column++;
	}
    }
   
    void funcB(){
	if(column == 0){
	    if(line != 0){
		line--;
		column = text[line].size();
	    }
	}else{
	    column--;
	}
    }
 
    void funcD(){
	if(text[line].empty()){
	    int len = text.size();
	    vector<string> ntext(len-1);
	    for(int i = 0 ; i < line ; i++){
		ntext[i] = text[i];
	    }
	    for(int i = line ; i < len-1 ; i++){
		ntext[i] = text[i+1];
	    }
	    text = ntext;
	    return;
	}
	if(0 <= column && column < (int)text[line].size()){
	    text[line] = text[line].substr(0,column) + text[line].substr(column+1);
	}else{
	    int len = text.size();
	    if(line+1 < len){
		vector<string> ntext(len-1);
		for(int i = 0 ; i < line-1 ; i++){
		    ntext[i] = text[i];
		}
		ntext[line] = text[line] + text[line+1];
		for(int i = line+2 ; i < len ; i++){
		    ntext[i-1] = text[i];
		}
		text = ntext;
	    }
	}
    }
 
    void funcK(){
	int len = text[line].size();
	if(text[line].empty()){
	    buffer = "\n";
	    int len = text.size();
	    vector<string> ntext(len-1);
	    for(int i = 0 ; i < line ; i++){
		ntext[i] = text[i];
	    }
	    for(int i = line ; i < len-1 ; i++){
		ntext[i] = text[i+1];
	    }
	    text = ntext;
	    return;
	}
	if(column == len){
	    int len2 = text.size();
	    if(line+1 < len2){
		buffer = "\n";
		vector<string> ntext(len2-1);
		for(int i = 0 ; i < line ; i++){
		    ntext[i] = text[i];
		}
		ntext[line] = text[line] + text[line+1];
		for(int i = line+1 ; i < len2-1 ; i++){
		    ntext[i] = text[i+1];
		}
		text = ntext;
	    }
	}else{
	    buffer.clear();
	    for(int i = column ; i < len ; i++){
		buffer += text[line][i];
	    }
	    text[line].resize(column);
	}
    }
 
    void funcY(){
	if(buffer.empty()){ return; }
	if(buffer == "\n"){
	    string str = text[line];
	    string str2 = str.substr(column);
	    text[line] = str.substr(0,column);
	    int size = text.size();
	    text.resize(size+1);
	    for(int i = size ; i > line+1 ; i--){
		text[i] = text[i-1];
	    }
	    text[line+1] = str2;
	    funcN();
	}else{
	    string str = text[line];
	    str = str.substr(0,column) + buffer + str.substr(column);
	    text[line] = str;
	    column += buffer.size();
	}
    }
 
    void print(){
	int len = text.size();
	for(int i = 0 ; i < len ; i++){
	    cout << text[i] << endl;
	}
    }
};
 
int main(){
    Emacs emacs;
    string str;
    while(getline(cin,str), str != "END_OF_TEXT"){
	emacs.text.push_back(str);
    }
    emacs.line = emacs.column = 0;
    char command;
    while(cin >> command, command != '-'){
	emacs.order(command);
    }
    emacs.print();
    return 0;
}

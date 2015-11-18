#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> vec;

    // 降順ソート
    sort(vec.begin(),vec.end(),greater<int>());

    // 重複を取り除く
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());

    // mergeし結果はc
    vector<int> a = {1,2,3,4}, b = {5,6,8,2}, c;
    merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));

    // 連結
    vector<int> d = {1,2,3}, e = {4,5,6};
    // dの後ろにeを連結する
    d.insert(d.end(),e.begin(),e.end());
    // eの後ろにdを連結する
    d.insert(d.begin(),e.begin(),e.end());
    
    return 0;
}

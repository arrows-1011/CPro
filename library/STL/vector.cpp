#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec;

    // 降順ソート
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    // 重複を取り除く
    std::sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    // mergeし結果はc
    std::vector<int> a = {1, 2, 3, 4}, b = {5, 6, 8, 2}, c;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));

    // 連結
    std::vector<int> d = {1, 2, 3}, e = {4, 5, 6};
    // dの後ろにeを連結する
    d.insert(d.end(), e.begin(), e.end());
    // eの後ろにdを連結する
    d.insert(d.begin(), e.begin(), e.end());
    
    return 0;
}

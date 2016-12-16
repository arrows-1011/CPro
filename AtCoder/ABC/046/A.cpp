#include <iostream>
#include <set>
 
int main()
{
    int a;
    std::set<int> st;
    for (int i = 0; i < 3; i++) {
        std::cin >> a;
        st.insert(a);
    }
    std::cout << st.size() << std::endl;
    return 0;
}

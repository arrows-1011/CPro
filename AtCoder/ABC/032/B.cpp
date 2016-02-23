#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string s;
    size_t len;
    cin >> s >> len;
    
    auto f = [=](){
        if (s.size() < len) {
            return 0;
        }
        std::set<std::string> passwords;
        for (size_t i = 0; i <= s.size()-len; i++) {
            std::string password;
            for (size_t j = 0; j < len; j++) {
                password += s[i+j];
            }
            passwords.insert(password);
        }
        return (int)passwords.size();
    };
    cout << f() << endl;
    return 0;
}

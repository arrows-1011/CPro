#include <iostream>
#include <vector>
 
bool in_field(int x, int y, int W, int H)
{
    return 0 <= x && x < W && 0 <= y && y < H;
}
 
int main()
{
    int H, W;
    std::cin >> H >> W;
 
    std::vector<std::string> s(H);
    for (int i = 0; i < H; i++) {
        std::cin >> s[i];
    }
     
    int seat_cnt = 0;
    for (int i = 1; i < H; i++) {        
        for (int j = 0; j < W; j++) {
            bool ok = (s[i][j] == '-');
            for (int dj : {-1, 1}) {
                int nj = j + dj;
                if (in_field(nj, i, W, H) && s[i][nj] != '-') {
                    ok = 0;
                }
            }
            constexpr int di[] = {-1, -1, -1, +0, +0, +1, +1, +1};
            constexpr int dj[] = {-1, +0, +1, +0, +0, -1, +0, +1};
            for (int k = 0; k < 8; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (in_field(nj, ni, W, H) && s[ni][nj] == 'x') {
                    ok = 0;
                }
            }
 
            seat_cnt += ok;
        }
    }
 
    std::cout << seat_cnt << std::endl;
    return 0;
}

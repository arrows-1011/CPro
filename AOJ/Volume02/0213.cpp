#include <iostream>
#include <vector>

using vec = std::vector<int>;
using Land = std::vector<std::vector<int>>;

int W, H, N;
Land s;
std::vector<Land> res;

bool check(int h, int w, int a, int b, int num)
{
    if (h + a > H || w + b > W) {
        return false;
    }
    for (int i = h; i < h + a; i++) {
        for (int j = w; j < w + b; j++) {
            if (s[i][j] != 0 && s[i][j] != num) {
                return false;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (h <= i && i < h + a && w <= j && j < w + b) {
                continue;
            }
            if (s[i][j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

void paint(int h, int w, int a, int b, int num)
{
    for (int i = h; i < h + a; i++) {
        for (int j = w; j < w + b; j++) {
            s[i][j] = num;
        }
    }
}

void dfs(int idx, const vec &b, const vec &k)
{
    if (idx == N) {
        res.emplace_back(s);        
        return;
    }    
    
    for (int i = 1; i <= k[idx]; i++) {
        int j = k[idx] / i;
        if (i * j != k[idx]) continue;
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {                
                if (check(h, w, i, j, b[idx])) {
                    auto tmp = s;
                    paint(h, w, i, j, b[idx]);
                    dfs(idx + 1, b, k);
                    s = tmp;
                }
            }
        }
    }
}

void print(Land &l)
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j > 0) std::cout << " ";            
            std::cout << l[i][j];
        }
        std::cout << std::endl;
    }
}

void init()
{
    s.assign(H, std::vector<int>(W));
    res.clear();
}

int main()
{
    while (std::cin >> W >> H >> N, W) {
        init();
        vec b(N), k(N);
        for (int i = 0; i < N; i++) {
            std::cin >> b[i] >> k[i];
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                std::cin >> s[i][j];
            }
        }

        dfs(0, b, k);

        if (res.size() != 1) {
            std::cout << "NA" << std::endl;
        } else {
            print(res[0]);
        }
    }
    return 0;
}

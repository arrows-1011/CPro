#include <iostream>
#include <vector>
#include <cstring>

constexpr int LEFT  = 0;
constexpr int UP    = 1;
constexpr int RIGHT = 2;
constexpr int DOWN  = 3;

class Maze {
  public:
    int H, W;
    int x, y, gx, gy;
    int dir;
    std::vector<std::string> data;

    Maze() {}
    
    Maze(int H, int W,
         int x, int y, int gx, int gy,
         int dir,
         std::vector<std::string> data)
        : H{H}, W{W}, x{x}, y{y}, gx{gx}, gy{gy},
          dir{dir},
          data{data} {}    
};

constexpr int MAX_H = 50;
constexpr int MAX_W = 50;
constexpr int MAX_D = 4;
constexpr int MAX_C = 1000;

bool visited[MAX_H][MAX_W][MAX_D][MAX_C + 1];

class Solver {
  private:
    Maze maze;
    
  public:
    Solver(Maze maze) : maze{maze} {
        memset(visited, 0, sizeof(visited));
    }

    void check_visited(const char *p)
    {
        int x = maze.x, y = maze.y, d = maze.dir;
        int c = strlen(p);
        if (visited[y][x][d][c]) {
            throw -1;
        }
        visited[y][x][d][c] = true;
    }
    
    void increment(const char *p, int &step)
    {
        check_visited(p);
        step++;
    }

    bool is_goal()
    {
        return maze.x == maze.gx && maze.y == maze.gy;
    }
    
    bool is_move_char(const char *p)
    {
        return *p == '<' || *p == '^' || *p == '>' || *p == 'v';
    }
    
    const char *move(const char *p)
    {
        static int step = 0;
        increment(p, step);
        
        char c = *p++;
        int dir = maze.dir;
        switch (c) {
            case '^':
            case 'v': {
                constexpr int dx[] = {-1, 0, 1, 0};
                constexpr int dy[] = {0, -1, 0, 1};
            
                int nx = maze.x + (c == '^' ? dx[dir] : dx[(dir + 2) % 4]);
                int ny = maze.y + (c == '^' ? dy[dir] : dy[(dir + 2) % 4]);

                if (maze.data[ny][nx] != '#') {
                    maze.x = nx; maze.y = ny;
                }            
                break;
            }
            
            case '<':
                maze.dir = (dir + 3) % 4;
                break;
            
            case '>':
                maze.dir = (dir + 1) % 4;
                break;
        }
        
        if (is_goal()) {
            throw step;
        }
        
        return p;
    }
    
    std::pair<bool, const char *> cond(const char *p)
    {
        bool state = false;
        char np = *p++;
        const int x = maze.x, y = maze.y, dir = maze.dir;        
        if (np == '~') {
            state = true;
            np = *p++;
        }
        
        switch (np) {
            case 'W':
                state = (dir == LEFT  ? !state : state);
                break;
            
            case 'N':
                state = (dir == UP    ? !state : state);
                break;
            
            case 'E':
                state = (dir == RIGHT ? !state : state);
                break;
            
            case 'S':
                state = (dir == DOWN  ? !state : state);
                break;
            
            case 'C': {
                constexpr int dx[] = {-1, 0, 1, 0};
                constexpr int dy[] = {0, -1, 0, 1};
                state = (maze.data[y + dy[dir]][x + dx[dir]] == '#' ?
                         !state : state);
                break;
            }
            
            case 'T':
                state = !state;
                break;
        }
        return {state, p};
    }

    const char *skip(const char *p, const char par)
    {
        int depth = 1;        
        char ppar = (par == '[' ? ']' : '}');
        
        while (depth != 0) {
            if (*p == par) {
                depth++;
            } else if (*p == ppar) {
                depth--;
            }
            p++;
        }
        return p;
    }
    
    const char *if_statement(const char *p)
    {       
        p++;
        auto ret = cond(p);
        if (ret.first) {
            p = prog(ret.second);
            p++;
        } else {
            p = skip(p, '[');
        }
        return p;
    }

    const char *while_statement(const char *p)
    {
        p++;            
        while (true) {
            check_visited(p);
            
            auto ret = cond(p);
            if (!ret.first) {
                p = skip(p, '{');
                break;
            }
            ret.second = prog(ret.second);
        }
        return p;
    }

    const char *state(const char *p)
    {
        if (*p == '[') {
            p = if_statement(p);
        } else if (*p == '{') {
            p = while_statement(p);
        } else if (is_move_char(p)) {
            p = move(p);
        }
        return p;
    }
    
    const char *prog(const char *p)
    {
        while (*p == '[' || *p == '{' || is_move_char(p)) {
            p = state(p);
        }
        return p;
    }

    void run(const char *p)
    {
        int res = -1;
        try {
            p = prog(p);
        } catch (int ret) {
            res = ret;
        }
        std::cout << res << std::endl;
    }
};

int main()
{
    int H, W;
    int sx{}, sy{}, gx{}, gy{};
    std::cin >> H >> W;
    std::vector<std::string> data(H);
    for (int i = 0; i < H; i++) {
        std::cin >> data[i];
        for (int j = 0; j < W; j++) {
            if (data[i][j] == 's') {
                sx = j; sy = i;
                data[i][j] = '.';
            }
            if (data[i][j] == 'g') {
                gx = j; gy = i;
                data[i][j] = '.';
            }
        }
    }
    
    std::string p;
    std::cin >> p;

    Solver solver{Maze{H, W, sx, sy, gx, gy, UP, data}};
    solver.run(p.c_str());
    return 0;
}

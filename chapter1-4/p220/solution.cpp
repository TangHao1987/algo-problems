#include<bits/stdc++.h>

using namespace std;

#define for_(i,a,b) for (int i = (a); i < (b); ++i)
#define for0(i,a) for_(i,0,a)

struct Point {
    int x, y;

    Point(int x, int y):x(x), y(y){}
};

ostream& operator << (ostream &out, const Point& p)  {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

const Point DIR []  = {Point(1, 0), Point(1, 1), Point(0, 1), Point(-1, 1), Point(-1, 0), Point(-1, -1), Point(0, -1), Point(1, -1)};
const int D = 8;
char board[D][D];

inline char other(char side) {
    return side == 'W' ? 'B' : 'W';
}

inline bool inRange(int x, int y) {
    return x >= 0 and y >= 0 and x < D and y < D;
}
inline bool checkOrMove(int i, int j, char side, bool move) {
    if (board[i][j] != '-') return false;
    bool legal = false;
    for(auto &p : DIR) {
        int x = i + p.x;
        int y = j + p.y;

        if (!inRange(x, y) or board[x][y] == '-' or board[x][y] == side) continue;

        do {
            x += p.x; y += p.y;
        }
        while(inRange(x, y) and board[x][y] == other(side));
       
        if (inRange(x, y) and board[x][y] == side) {
            legal = true;
            if (move) {
                int mx = i, my = j;
                while (mx != x or my != y) {
                    board[mx][my] = side;
                    mx += p.x; my += p.y;
                } 
            }
        }
    }
    return legal;
}

inline void getMoves(vector<Point> &vp, char side) {
    for0(i, D) {
        for0(j, D) {
            if (checkOrMove(i, j, side, false)) vp.emplace_back(i + 1, j + 1);
        }
    }
}
inline void listSteps(char side) {
    vector<Point> vp;
    getMoves(vp, side);
    if (vp.empty()) {
        puts("No legal move.");
    } else {
        for0(i, vp.size()) cout << vp[i] << (i < vp.size() - 1 ?  ' ' : '\n');
    }
}

inline void check() {
    int b =0, w = 0;
     for0(i, D) {
        for0(j, D) {
           if (board[i][j] == 'B') b++;
           if (board[i][j] == 'W') w++; 
        }
    }
    printf("Black - %2d White - %2d\n", b, w);
}

inline void makeMove(char cx, char cy, char &side) {
    int x = cx - '1', y = cy - '1';
    if (!checkOrMove(x, y, side, false)) side = other(side);
    checkOrMove(x, y, side, true);
    side = other(side);
    check();
}

inline void printBoard() {
    for0(i, D) {
        for0(j, D) putchar(board[i][j]);  
        printf("\n");
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        getchar();
        for0(i, D) {
            for0(j, D) board[i][j] = getchar();  
            getchar();
        }
        char side; cin >> side;

        string instr;
        while(cin >> instr) {
            if (instr[0] == 'Q') {
                printBoard();
                if (t > 0) puts("");
                break;
            }
            switch(instr[0]) {
                case 'L':
                    listSteps(side);
                    break;
                case 'M':
                    makeMove(instr[1], instr[2], side);
                    break;
            }
        }
    }
}
#include<bits/stdc++.h>

using namespace std;

char board[10][9];

const pair<int, int> DIR [] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const int HM [4][3][2]=  {
 {{0, 1}, {-1, 2}, {1, 2}},
 {{1, 0}, {2, 1}, {2, -1}},
 {{0, -1}, {-1, -2}, {1, -2}},
 {{-1, 0}, {-2, 1}, {-2, -1}},
};
struct Piece {
    Piece(char name, int x, int y): x(x), y(y), name(name) {}

    char name;
    int x, y;
};

inline bool canMove(int x, int y) {
    return !board[x][y] || board[x][y] == 'B' || board[x][y] == 'A';
}

void printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) printf("%2c", board[i][j] ? board[i][j] : '0');
        puts("");
    }
}

void markGeneral(Piece &p) {
    for (int r = p.x - 1; r >= 0; r--) {
        if (!canMove(r, p.y)) break;
        board[r][p.y] = 'A';
    }
}

void markChariot(Piece &p) {
    for (int r = p.x - 1; r >= 0; r--) {
        if (!canMove(r, p.y)) break;
        board[r][p.y] = 'A';
    }

    for (int r = p.x + 1; r <= 9; r++) {
        if (!canMove(r, p.y)) break;
        board[r][p.y] = 'A';
    }

    for (int c = p.y - 1; c >= 0; c--) {
        if (!canMove(p.x, c)) break;
        board[p.x][c] = 'A';
    }

    for (int c = p.y + 1; c <= 8; c++) {
       if (!canMove(p.x, c)) break;
        board[p.x][c] = 'A';
    }
}

void markHorse(Piece &p) {
    for (int i = 0; i < 4; i++) {
        int x = p.x + HM[i][0][0];
        int y = p.y + HM[i][0][1];
        if (x < 0 || x > 9 || y < 0 || y > 8 || !canMove(x, y)) continue;
        
        for (int j = 1; j <= 2; j++) {
            x = p.x + HM[i][j][0];
            y = p.y + HM[i][j][1];
            if (x < 0 || x > 9 || y < 0 || y > 8 || !canMove(x, y)) continue;
            board[x][y] = 'A';
        }
    }
}

void markCannon(Piece &p) {
    int jumped = 0;
    for (int r = p.x - 1; r >= 0; r--) {
        if (!canMove(r, p.y)) {
            if (jumped) break; 
            jumped = 1;
            continue;
        }
        if (jumped) board[r][p.y] = 'A';
    }
    jumped = 0;
    for (int r = p.x + 1; r <= 9; r++) {
        if (!canMove(r, p.y)) {
            if (jumped) break; 
            jumped = 1;
            continue;
        }
        if (jumped) board[r][p.y] = 'A';
    }
    jumped = 0;
    for (int c = p.y - 1; c >= 0; c--) {
        if (!canMove(p.x, c)) {
            if (jumped) break; 
            jumped = 1;
            continue;
        }
        if (jumped) board[p.x][c] = 'A';
    }
    jumped = 0;
    for (int c = p.y + 1; c <= 8; c++) {
        if (!canMove(p.x, c)) {
            if (jumped) break; 
            jumped = 1;
            continue;
        }
        if (jumped) board[p.x][c] = 'A';
    }
}

int main() {
    for(;;) {
        memset(board, 0, sizeof(board));

        int n, br, bc;
        cin >> n >> br >> bc;
        if (n == 0) return 0;

        br--;
        bc--;

        vector<Piece> pieces;
        for (int i = 0; i < n; i++) {
            char name; int x, y;
            cin >> name >> x >> y;
            x--; y--;
            pieces.emplace_back(name, x, y);
        }


        
        int win = true;
        for (auto &d : DIR) {
            int r = br + d.first;
            int c = bc + d.second;
            if (!(r >= 0 && r <= 2 && c >= 3 && c <= 5)) continue; 
            
            for (auto & p: pieces) board[p.x][p.y] = p.name;
            board[r][c] = 'B';
            for (auto &p : pieces) {
                if (p.x == r and p.y == c) continue;
                switch(p.name) {
                    case 'G':
                        markGeneral(p);
                        break;
                    case 'R':
                        markChariot(p);
                        break;
                    case 'H':
                        markHorse(p);
                        break;
                    case 'C':
                        markCannon(p);
                        break;
                }
            }
            // printBoard();
            if (board[r][c] == 'B') {
                win = false;
                break;
            }
        }
          
        cout << (win ? "YES" : "NO") << endl;
        getchar();
    }
}
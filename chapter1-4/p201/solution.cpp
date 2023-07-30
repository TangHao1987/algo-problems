#include<bits/stdc++.h>

using namespace std;

int board[10][10];

inline bool checkSquare(int i, int j, int sz) {
    for (int k = 0; k < sz; k++) {
        if((board[i][j + k] & 1) == 0) return false;
        if((board[i + sz][j + k] & 1) == 0) return false;
        if(((board[i+k][j] >> 1) & 1) == 0) return false;
        if(((board[i+k][j + sz] >> 1) & 1) == 0) return false;
    }
    return true;
}

inline void printBoard(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n, m, mx_size, hasRes, sqcnt, count = 1;

    while(cin >> n >> m) {
        if (count > 1) puts("\n**********************************\n");
        printf("Problem #%d\n\n", count++);
        
        memset(board, 0, sizeof(board));
        while(m--) {
            char d; int x, y;
            cin >> d >> x >> y;
            if (d == 'V') swap(x, y);
            board[x][y] |= (d == 'H' ? 1 : 2);
        }
        // printBoard(n);
        mx_size = n - 1;
        hasRes = false;
        for(int sz = 1; sz <= mx_size; sz++) {
            sqcnt = 0;
            for (int i = 1; i <= n - sz; i++) {
                for (int j = 1; j <= n - sz; j++) {
                    if(checkSquare(i, j, sz)) {
                        hasRes = true;
                        sqcnt++;    
                    }
                }
            }
            if (sqcnt) printf("%d square (s) of size %d\n", sqcnt, sz);
        }
        if (!hasRes) puts("No completed squares can be found.");
    }
}

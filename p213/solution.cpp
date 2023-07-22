#include <iostream>
#include <string.h>
char code[8][1 << 8];

int readcode() {
    memset(code, 0, sizeof(code));
    int c;
    int sz = 1, sz1 = 0;
    for(;;) {
        c = getchar();
        if (c == EOF || c == '\n' || c == '\r') return code[1][0];
        code[sz][sz1++] = c;
        if (sz1 == (1 << sz) - 1) {
            sz++;
            sz1 = 0;
        }
    }
}

void printcode() {
    for (int i = 1; i < 8; i++) {
        if (!code[i][0]) return;
        int j = 0;
        while (code[i][j] != 0) printf("%c ", code[i][j++]);
        printf("\n");
    }
}
int readInt(int size) {
    int v = 0;
    while(size--) {
        int c;
        do { c= getchar(); } while (c == '\n' || c == '\r');
        v = v * 2 + c - '0';
    }
    return v;
}

int main() {
    for(;;) {
        if(!readcode()) return 0;
        // printcode();
        for(;;) {
            int header = readInt(3);
            if (!header) break;
            for(;;) {
                int msg = readInt(header);
                if (msg == (1 << header) - 1) break;
                printf("%c", code[header][msg]);
            }
        }
        getchar();
        printf("\n");
    }
}

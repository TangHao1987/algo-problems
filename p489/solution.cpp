#include <iostream>
#include <string.h>

#define maxn 100

const int STROKES = 7;
char a[maxn], b[maxn];
int left, chance;
int win, lose;

int guess(char ch) {
    bool found = false;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == ch) {
            left--;
            a[i] = ' ';
            found = true;
        } 
    }
    if (!found) chance--;

    if (chance == 0) lose = 1;
    if (left == 0) win = 1;
    return lose | win;  
}

int main() {
    int rnd;
    while(scanf("%d%s%s", &rnd, &a, &b) == 3 && rnd != -1) {
        win = lose = 0;
        left = strlen(a);
        chance = STROKES;
        for (int i = 0; i < strlen(b); i++) {
            if(guess(b[i])) break;
        }
        printf("Round %d\n", rnd);
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }    
    return 0;
}
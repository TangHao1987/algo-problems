#include<iostream>
#include<string.h>
#include <vector>
#include <algorithm>

#define MAXN 105

using namespace std;

char msg[MAXN], emsg[MAXN];


int main() {
    memset(msg, 0, sizeof(msg));
    memset(emsg, 0, sizeof(emsg));
    while(scanf("%s%s", emsg, msg) == 2) {
        vector<int> c1(26, 0), c2(26, 0);
        for (int i = 0; i < strlen(msg); i++) c1[msg[i] - 'A']++;
        for (int i = 0; i < strlen(emsg); i++) c2[emsg[i] - 'A']++;
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        int match = 1;
        for (int i = 0; i < 26; i++) if(c1[i] != c2[i]) match = 0;

        printf(match ? "YES\n" : "NO\n");
    }
}

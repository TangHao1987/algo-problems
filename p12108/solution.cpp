#include <bits/stdc++.h>

#define for_(i,a,b) for (int i = (a); i < (b); ++i)
#define for0(i,a) for_(i,0,a)
#define rof_(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rof0(i,a) rof_(i,0,a)
#define rep(a) for0(_,a)
#define each(a,x) for (auto& a: x)

#define MAXN 10000

using namespace std;
 
using ll = long long;
using db = long double; // or double if tight TL
using str = string;

int stud [10][4];
int t;

int GetAwaked() {
    int awaked = 0;
    for0 (i, t) {
        if (stud[i][3]) {
            awaked++;
        } else if (stud[i][2] <= stud[i][0]) {
            awaked++; 
        }
    }
    return awaked;
}

void Mark(int waked) {
    bool keepAwake = waked * 2 >= t;
    for0 (i, t) {
        if(stud[i][2] <= stud[i][0] && keepAwake) stud[i][3] = 1;
        int idx = stud[i][2];
        int cycle = stud[i][0] + stud[i][1];
        idx = idx % cycle + 1;
        stud[i][2] = idx;
    }
}

int main() {
    int kcase = 1;
    while(cin >> t && t > 0) {
        memset(stud, 0, sizeof(stud));
        for0(i, t) scanf("%d%d%d", &stud[i][0], &stud[i][1], &stud[i][2]);
        int ans = -1;
        for_(i, 1, MAXN) {
            int waked = GetAwaked();
            if (waked == t) {
                ans = i;
                break;
            }
            Mark(waked);
        }
        cout << "Case " << kcase++ << ": " << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ui = unsigned int;
using str = string;

#define for_(i,a,b) for (int i = (a); i < (b); ++i)
#define for0(i,a) for_(i,0,a)


inline ui getVal() {
    int p [4];
    scanf("%d.%d.%d.%d", &p[0], &p[1], &p[2], &p[3]);
    ui val = 0;
    for0(i, 4) val = (val << 8) + p[i];
    return val;
}

inline string toIpAddr(ui val) {
    str addr = "";
    const int mask = (1 << 8) - 1;

    for0(i, 4) {
        if (i > 0) addr = "." + addr;
        addr = to_string(val & mask) + addr;
        val >>= 8;
    }
    return addr;
}

int main() {
    int m;
    while(cin >> m) {
        int net, mask = -1; ll maski = 1;
        for0(i, m) {
            auto val = getVal();
            if (i == 0) {
                net = val;
            } else {
                while((mask & val) != net) {
                    mask -= maski;
                    net &= mask; 
                    maski <<= 1;
                }
            }
        }
        cout << toIpAddr(net) << endl;
        cout << toIpAddr(mask) << endl;
    }
    return 0;
}
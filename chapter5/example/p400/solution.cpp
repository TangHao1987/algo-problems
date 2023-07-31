#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define for_(i,a,b) for (int i = (a); i < (b); ++i)
#define for0(i,a) for_(i,0,a)
#define rof_(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rof0(i,a) rof_(i,0,a)
#define rep(a) for0(_,a)
#define each(a,x) for (auto& a: x)

#define MAXC 60

int main() {
    int n; 
    while(cin >> n && n) {
        vector<string> files;
        size_t l = 0;
        rep(n) {
            str file; 
            cin >> file;
            l = max(l, file.length());
            files.push_back(file);
        }
        int c = (MAXC + 2) / (static_cast<int>(l) + 2);
        sor(files);
        int r = (n + c - 1) / c; 
        
        rep(60) putchar('-');
        putchar('\n');

        for0(i, r) {
            for0(j, c) {
                if (j*r + i >= n) break; 
                str file = files.at(j*r + i);
                for(char& c : file) putchar(c);
                int space = l - static_cast<int>(file.length());
                rep(space) putchar(' ');
                if (j % c < c - 1) rep(2) putchar(' ');
            }
            putchar('\n');
        }
    }
    return 0;
}
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

int main() {
    int n, q, kcase = 1;
    while(cin >> n >> q && n && q) {
        vi marbles(n);
        each(marble, marbles) cin >> marble;
        sor(marbles);
        printf("CASE# %d:\n", kcase++);
        rep(q) {
            int iq; cin >> iq;
            auto p = lower_bound(all(marbles), iq);
            if (*p != iq) {
                printf("%d not found\n", iq);
            } else {
                printf("%d found at %d\n", iq, p - marbles.begin() + 1);
            }
        }
    }
}

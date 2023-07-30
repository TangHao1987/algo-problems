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
    int a, b, n,  kcase = 1;
    while(cin >> a >> b && a > 0 && b > 0) {
        n = a * b;
        vector<ll> vals(n);
        for(auto &e : vals) cin >> e;
        sor(vals);
        ll sinked = -1;
        double level, percent, water; cin >> water;
        for_(i, 1, n) {
            ll area = 100 * i;
            ll elevation = (vals[i] - vals[i - 1]) * area;
            if (elevation <= water) {
                water -= elevation;
            } else {
                level = vals[i - 1] + ((double) water / area);
                sinked = i;
                break;  
            }
        }
        if (sinked < 0) {
            sinked = n;
            level = vals[n - 1] + ((double) water / (n * 100));
        }

        percent = (double) sinked / n * 100;

        printf("Region %d\n", kcase++);
        printf("Water level is %.2lf meters.\n", level); 
        printf("%.2lf percent of the region is under water.\n\n", percent);
    } 
}
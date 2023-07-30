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

str disks[10];
int d,s,b, ti;
char type;

bool CheckAndFix(int r) {
    for (int j = 0; j < s; j++) {
        int si = -1;
        int val = 0;
        int pos = s*r;
        for (int i = 0; i < d; i++) {
            if (disks[i][pos + j] == 'x') {
                if (si != -1) return false;
                si = i;
                continue;
             }
             val ^= (disks[i][pos + j] - '0');
        }
        // fix si if available   
        if (si >= 0) {
            disks[si][pos+j] = '0' + ti^val;
        }
        else if (val != ti) return false;
    }
     return true;
}

void GetContent() {
    int val = 0;
    int c = 0;
    ll size = 0; 
    for0(i, b) {
        int pos = i*s;
        for0(j, d) {
            if ((i % d) == j) continue; 
            size += s;
            for_(k, pos, pos + s) {
                val = val * 2 + disks[j][k] - '0';
                c++;
                if (c == 4) {
                    printf("%X", val);
                    val = 0;
                    c = 0;
                }
            }
        }
    }
    if (c > 0) {
        while (c++ < 4) val = val * 2; 
        printf("%X", val);
    }
}

int main()
{
    int counter = 1;
    while(cin >> d >> s >> b >> type && d > 0) {
        ti = type == 'E' ? 0 : 1;
        str data;
        for0(i, d) {
            cin >> disks[i];
        }
        bool valid = true;
        for0(j, b) {
            if (!CheckAndFix(j)) {
                valid = false;
                break;
            }
        }

        cout << "Disk set " << counter++ << " is ";
        if (valid) {
            cout << "valid, contents are: ";
            GetContent();
            cout << endl;
        } else {
            cout << "invalid." << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string color;
    while(cin >> color) {
        string s1, s2;
        s1 = color.substr(0, 6);
        s2 = color.substr(6);
        
        bool matching [] = {false, false, false};
        bool res = true;
        for (int i = 0; i < 3; i++) {
            char c11 = s1[i], c12 = s1[5 - i];
            bool found = false;
            for (int j = 0; j < 3; j++) {
                if (matching[j]) continue;
                char c21 = s2[j], c22 = s2[5 - j];
                if ((c11 == c21 and c12 == c22) or (c11 == c22 and c12 == c21)) {
                    matching[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found) {
                res = false;
                break;
            }
        }
        cout << (res ? "YES" : "NO") << endl;
    }
}


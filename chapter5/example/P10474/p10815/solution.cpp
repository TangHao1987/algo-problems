/******************************************************************************

UVa10815
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1756

, a word is defined as a consecutive sequence of alphabets,
length >= 1, lower and upper case

case insensitive

5000 line * 200 characters

print lower case
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line, word;
    set<string> words;
    while(getline(cin, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]);
            } else {
                line[i] = ' ';
            }
        }
        stringstream ss(line);
        
        while(ss >> word) {
            words.insert(word);
        }
    }
    for (auto &w : words) printf("%s\n", w.c_str());
    return 0;
}


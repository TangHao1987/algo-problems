/******************************************************************************

P540

https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=481

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef deque<int> Queue;
unordered_map<int, int> team_map;
unordered_map<int, Queue> q_map;
Queue main_q;

void Enqueue() {
    int m; cin >> m;
    int qi = team_map[m];
    if (q_map[qi].empty()) main_q.push_back(qi);
    q_map[qi].push_back(m);
}
void Dequeue() {
    if (main_q.empty()) return;
    int qi = main_q.front();
    cout << q_map[qi].front() << endl;
    q_map[qi].pop_front();
    if (q_map[qi].empty()) main_q.pop_front();
}

int main()
{
    int t, k = 1;
    while(cin >> t && t) {
        team_map.clear();
        q_map.clear();
        main_q.clear();
        while(t--) {
            q_map.emplace(t, initializer_list<int>());
            int m_count; cin >> m_count;
            while(m_count--) {
                int member; cin >> member;
                team_map[member] = t;
            }
        }
        
        cout << "Scenario #" << k++ << endl;

        string cmd;
        while(cin >> cmd) {
            if (cmd == "STOP") break;
            if (cmd == "ENQUEUE") Enqueue();
            if (cmd == "DEQUEUE") Dequeue();
        }
        cout << endl;
    }
}


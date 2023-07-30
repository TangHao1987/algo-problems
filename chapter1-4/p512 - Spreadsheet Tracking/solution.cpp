#include<bits/stdc++.h>

#define ERORR 0.00001

using namespace std;

struct Stu {
    int cid;
    string sid, name;
    int rank, cs, ms, es, ps, ts;

    bool operator<(const Stu& st) {
        return ts > st.ts;
    }
};

struct Stat {
    int ts = 0;
    int fail = 0;
    int pass = 0;
};

vector<Stu> stus;
unordered_set<string> sids;

inline void printMainMenu() {
    cout << "Welcome to Student Performance Management System (SPMS)." << endl << endl;
    cout << "1 - Add" << endl;
    cout << "2 - Remove" << endl;
    cout << "3 - Query" << endl;
    cout << "4 - Show ranking" << endl;
    cout << "5 - Show Statistics" << endl;
    cout << "0 - Exit" << endl<<endl;
}


inline void printAddTitle() {
    cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
}

inline void rerank() {
    vector<Stu> ranks(stus);
    sort(ranks.begin(), ranks.end());
    int cur_rank = 1;
    int rank = 1;
    unordered_map<string, int> rank_map;
    
    for(int rank = 1; rank <= ranks.size(); rank++) {
        if (rank > 1 && ranks[rank - 1].ts < ranks[rank - 2].ts) cur_rank = rank;
        rank_map[ranks[rank - 1].sid] = cur_rank;
    }
    
    for(auto &st : stus) {
        st.rank = rank_map[st.sid];
    }
}

inline void printStat(const Stat &stat, const string &name) {
    cout << name << endl;
    double ave = (double) stat.ts / (stat.pass + stat.fail) + ERORR;
    printf("Average Score: %.2lf\n", ave); 
    printf("Number of passed students: %d\n", stat.pass);
    printf("Number of failed students: %d\n\n", stat.fail);
}

void add() {
     printAddTitle();
    // 0011223344 1 John 79 98 91 100
    // sid cid name cs ms es ps
    
    
    while(true) {
        string sid; cin >> sid;
        if (sid == "0") break;
        Stu st;
        st.sid = sid;
        if (!(cin >> st.cid >> st.name >> st.cs >> st.ms >> st.es >> st.ps)) {
            cout << "Input error" << endl;
        }
        if (sids.find(st.sid) != sids.end()) {
            cout << "Duplicated SID." << endl;
        } else {
            st.ts = st.cs + st.ms + st.es + st.ps;
            stus.push_back(st);
            sids.insert(sid);
        }
        printAddTitle();
    }
    rerank();
}

inline void printRemoveAndQueryTitle() {
    cout << "Please enter SID or name. Enter 0 to finish." << endl;
}

void remove() {
    printRemoveAndQueryTitle();
    string id_name;
    unordered_set<string> idset;
    while(cin >> id_name && id_name != "0") {
        idset.insert(id_name);
        auto it = stus.begin();
        int cnt = 0;
        while(it != stus.end()) {
            auto stu = *it;
            if (idset.count(stu.name) || idset.count(stu.sid)) {
                it = stus.erase(it);
                sids.erase(stu.sid);
                cnt++;
            } else { it++; }
        }
        printf("%d student(s) removed.\n", cnt);
        printRemoveAndQueryTitle();
    }
    rerank();
}

void query() {
    printRemoveAndQueryTitle();
    string id_name;
    while(cin >> id_name && id_name != "0") {
        // 3 2423475629 2 John 60 80 30 99 269 67.25
        for (auto &stu : stus) {
            if (stu.sid == id_name || stu.name == id_name) {
                double eva_score = (double) stu.ts / 4 + ERORR; 
                // rank sid cid name cs ms es ps ts eva
                printf("%d %s %d %s %d %d %d %d %d %.2lf\n", stu.rank, stu.sid.c_str(), stu.cid, stu.name.c_str(), stu.cs, stu.ms, stu.es, stu.ps, stu.ts, eva_score);
            }
        }
        printRemoveAndQueryTitle();
    }
}

void statistics() {
    Stat chinese, math, english, programming;
    int passed [5] = {0};
    cout << "Please enter class ID, 0 for the whole statistics." << endl;
    int cid;
    cin >> cid;
    for (auto &st : stus) {
        if (cid != 0 && st.cid != cid) continue;
        int p = 0;
        chinese.ts += st.cs;
        if (st.cs >= 60) { p++; chinese.pass++; } else {chinese.fail++; }
        math.ts += st.ms;
        if (st.ms >= 60) { p++; math.pass++; } else math.fail++;
        english.ts += st.es;
        if (st.es >= 60) { p++; english.pass++; } else english.fail++;
        programming.ts += st.ps;
        if (st.ps >= 60) { p++; programming.pass++; } else programming.fail++;
        passed[p]++;
    }

    printStat(chinese, "Chinese");
    printStat(math, "Mathematics");
    printStat(english, "English");
    printStat(programming, "Programming");

    printf("Overall:\n");
    printf("Number of students who passed all subjects: %d\n", passed[4]);
    printf("Number of students who passed 3 or more subjects: %d\n", passed[3] + passed[4]);
    printf("Number of students who passed 2 or more subjects: %d\n", passed[2] + passed[3] + passed[4]);
    printf("Number of students who passed 1 or more subjects: %d\n", passed[1] + passed[2] + passed[3] + passed[4]);
    printf("Number of students who failed all subjects: %d\n\n", passed[0]);
}

int main() {
    printMainMenu();
    int input;
    stus.clear();
    sids.clear();
    while(cin >> input) {
        switch (input)
        {
        case 1:
            add();
            break;
        case 2:
            remove();
            break;
        case 3:
            query();
            break;
        case 4:
            cout << "Showing the ranklist hurts students’ self-esteem. Don’t do that." << endl;
            break;
        case 5:
            statistics();
            break;
        case 0: 
            return 0;
        default:
            cout << "Invalid input" << endl;
        }
        printMainMenu();
    }
}

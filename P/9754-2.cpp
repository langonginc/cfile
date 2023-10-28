#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;

struct Member {
    string name;
    string type;
    ll offset;
    Member () {}
    Member (string n, string t, ll o) {
        name = n, type = t, offset = o;
    }
};

map <string, ll> StructLength;
map <string, ll> StructAlign;
map <string, ll> StructIndex;

vector <Member> member[maxn];
int memberCount = 3;

Member VarStack[maxn];
int varTop = -1;

ll maxAddr = 0;

void init () {
    StructLength.insert({ "byte", 1 });
    StructLength.insert({ "short", 2 });
    StructLength.insert({ "int", 4 });
    StructLength.insert({ "long", 8 });
    StructAlign.insert({ "byte", 1 });
    StructAlign.insert({ "short", 2 });
    StructAlign.insert({ "int", 4 });
    StructAlign.insert({ "long", 8 });
    StructIndex.insert({ "byte", 0 });
    StructIndex.insert({ "short", 1 });
    StructIndex.insert({ "int", 2 });
    StructIndex.insert({ "long", 3 });
}

void newStruct () {
    memberCount++;
    string name;
    int k;
    cin >> name >> k;
    ll align = 0, size = 0;
    for (int i = 1; i <= k; i ++) {
        string t, n;
        cin >> t >> n;
        ll thisAlign = StructAlign[t];
        ll thisLength = StructLength[t];
        align = max(align, thisAlign);
        if (size % thisAlign != 0) {
            size = (size / thisAlign + 1) * thisAlign;
        }
        member[memberCount].push_back(Member(n, t, size));
        size += thisLength;
    }
    if (size % align != 0) {
        size = (size / align + 1) * align;
    }
    StructAlign.insert ({ name, align });
    StructLength.insert ({ name, size });
    StructIndex.insert ({ name, memberCount });
    cout << size << " " << align << endl;
}

void newElement () {
    string type, name;
    cin >> type >> name;
    ll size = StructLength[type];
    ll align = StructAlign[type];
    if (maxAddr % align != 0) {
        maxAddr = (maxAddr / align + 1) * align;
    }
    VarStack[++varTop] = Member(name, type, maxAddr);
    cout << maxAddr << endl;
    maxAddr += size;
}

vector <string> split (string str) {
    vector <string> ans;
    ans.clear();
    string substr = "";
    for (int i = 0; i < str.length(); i ++) {
        if (str[i] == '.') {
            ans.push_back(substr);
            substr = "";
        } else {
            substr += str[i];
        }
    }
    ans.push_back(substr);
    return ans;
}

void queryName () {
    string str;
    cin >> str;
    vector <string> path = split(str);
    ll offset = 0;
    string type = "";
    for (int i = 0; i <= varTop; i ++) {
        if (path[0].compare(VarStack[i].name) == 0) {
            offset += VarStack[i].offset;
            type = VarStack[i].type;
            break;
        }
    }
    for (int i = 1; i < path.size(); i ++) {
        int id = StructIndex[type];
        for (int j = 0; j < member[id].size(); j ++) {
            if (path[i].compare(member[id][j].name) == 0) {
                offset += member[id][j].offset;
                type = member[id][j].type;
                break;
            }
        }
    }
    cout << offset << endl;
}

void queryAddr () {
    string ans = "";
    bool flag = false;
    ll addr;
    cin >> addr;
    string type;
    for (int i = varTop; i >= 0; i --) {
        if (VarStack[i].offset <= addr) {
            type = VarStack[i].type;
            ans = VarStack[i].name;
            addr -= VarStack[i].offset;
            break;
        } 
    }
    while (true) {
        int id = StructIndex[type];
        if (id <= 3) {
            if (addr < StructLength[type]) {
                flag = true;
            }
            break;
        }
        for (int i = member[id].size() - 1; i >= 0 ; i --) {
            if (member[id][i].offset <= addr) {
                type = member[id][i].type;
                ans += ".";
                ans += member[id][i].name;
                addr -= member[id][i].offset;
                break;
            }
        }
    }
    cout << (flag ? ans : "ERR") << endl;
}

int n;

int main () {
    init();
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int op;
        cin >> op;
        if (op == 1) {
            newStruct();
        } else if (op == 2) {
            newElement();
        } else if (op == 3) {
            queryName();
        } else if (op == 4) {
            queryAddr();
        }
    }
    return 0;
}

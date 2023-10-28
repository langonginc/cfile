#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 105;

struct Element {
    int id, type;
    ll addr;
    ll length;
    vector<int> child;
    string name;

    Element (int _id, int _type, ll _addr, ll _length, string _name, vector<int> _child) {
        id = _id, type = _type, addr = _addr, length = _length, name = _name, child = _child;
    }
};

struct StructInfo {
    int id;
    string name;
    vector<pair<int, string>> child;
    ll length, takeLength;

    StructInfo (int _id, string _name, vector<pair<int, string>> _ch, ll _length, ll _tl) {
        id = _id, name = _name, child = _ch, length = _length, takeLength = _tl;
    }
};

int maxStructId, maxElementId;
ll maxAddr;
vector<StructInfo> structList;
map<string, int> structName;
vector<Element> elementList;
map<string, int> elementName;
map<ll, string> elementTake;

inline ll toGe0 (ll x, ll y) {
    ll ans = x - y;
    while (ans < 0) ans += x;
    if (x <= 0) exit(2);
    return ans;
}

int dfsGenerate (int structId, ll startAddr, string name, string dirname, ll leftAddr) {
    vector<int>ch;
    ll tmpStartAddr = startAddr;
    ll tmpLength = 0;
    for (int i = 0; i < structList[structId].child.size(); i ++) {
        int v = structList[structId].child[i].first;
        string n = structList[structId].child[i].second;
        printf ("TempStart = %lld, TempLength = %lld, LeftLength = %lld\n", tmpStartAddr, tmpLength, toGe0(structList[structId].takeLength, tmpLength));
        int chId = dfsGenerate(v, tmpStartAddr, n, dirname + string(".") + n, toGe0(structList[structId].takeLength, tmpLength));
        tmpStartAddr = elementList[chId].addr + elementList[chId].length;
        if (tmpLength + elementList[chId].length >= structList[structId].takeLength)
            tmpLength = elementList[chId].length;
        else tmpLength += elementList[chId].length;
        ch.push_back(chId);
    }
    ll length = structList[structId].length;
    ll thisStartAddr = 0;
    if (leftAddr - structList[structId].takeLength >= 0) {
        thisStartAddr = startAddr;
    } else {
        thisStartAddr = startAddr + leftAddr;
    }
    elementList.push_back(Element(++maxElementId, structId, thisStartAddr, length, name, ch));
    elementName.insert({dirname, maxElementId});
    cout << "ID: " << maxElementId << ", DIR: " << dirname << ", START ADDR: " << thisStartAddr << " " << length << endl;
    if (structId <= 3) {
        // cout << "YES" << endl;
        for (ll i = thisStartAddr; i <= thisStartAddr + length; i ++)
            elementTake.insert({i, dirname});
    }
    return maxElementId;
}

int main () {
    vector<pair<int, string>> emptyVector;
    structList.push_back(StructInfo(0, "byte", emptyVector, 1, 1));
    structList.push_back(StructInfo(1, "short", emptyVector, 2, 2));
    structList.push_back(StructInfo(2, "int", emptyVector, 4, 4));
    structList.push_back(StructInfo(3, "long", emptyVector, 8, 8));
    structName.insert({"byte", 0});
    structName.insert({"short", 1});
    structName.insert({"int", 2});
    structName.insert({"long", 3});
    maxStructId = 3, maxElementId = -1, maxAddr = 0;

    int n, op, k;
    char s[15], ti[15], ni[15];
    int tmpt[105];
    scanf ("%d\n", &n);
    ll a;
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &op);
        if (op == 1) {
            scanf ("%s%d", s, &k);
            string str = string(s);
            vector<pair<int, string>>ch;
            ll maxLength = 0, sumLength = 0, thisLength = 0;
            for (int j = 1; j <= k; j ++) {
                scanf ("%s%s", ti, ni);
                int Ti = structName[ti];
                tmpt[j] = Ti;
                // printf ("Ti = %d, Length = %lld\n", Ti, structList[Ti].length);
                string Ni = string (ni);
                maxLength = max (maxLength, structList[Ti].takeLength);
                ch.push_back({Ti, Ni});
            }
            {
                for (int j = 1; j <= k; j ++) {
                    printf ("OP1 Add: %lld, ", structList[tmpt[j]].length);
                    thisLength += structList[tmpt[j]].length;
                    if (thisLength >= maxLength) {
                        sumLength += (thisLength/maxLength) * maxLength;
                        if (thisLength % maxLength == 0) {
                            thisLength = 0;
                        } else{
                            thisLength = structList[tmpt[j]].length % maxLength;
                            if (structList[tmpt[j]].length >= maxLength) sumLength += maxLength;
                        }
                    }
                    printf ("ans: %lld, left: %lld\n", sumLength, thisLength);
                }
            }
            // {
            //     for (int j = 1; j <= k; j ++) {
            //         thisLength += structList[tmpt[j]].length;
            //         if (thisLength >= maxLength) {
            //             sumLength += (thisLength/maxLength) * maxLength;
            //             if (thisLength % maxLength != 0) sumLength += maxLength;
            //             thisLength = 0;
            //         }
            //     }
            // }
            if (thisLength > 0) sumLength += maxLength;
            structList.push_back(StructInfo(++maxStructId, str, ch, sumLength, maxLength));
            structName.insert({str, maxStructId});
            printf ("%lld %lld\n", sumLength, maxLength);
        } else if (op == 2) {
            scanf ("%s%s", ti, ni);
            int Ti = structName[ti];
            string Ni = string (ni);
            dfsGenerate(Ti, maxAddr, Ni, Ni, 0);
            printf ("%lld\n", maxAddr);
            maxAddr += structList[Ti].length;
        } else if (op == 3) {
            scanf ("%s", s);
            int id = elementName[string(s)];
            printf ("%lld\n", elementList[id].addr);
        } else if (op == 4) {
            scanf ("%lld", &a);
            if (elementTake[a] == "") printf ("ERR\n");
            else cout << elementTake[a] << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define Mkp make_pair
#define All(x) (x).begin(), (x).end()
using db = double;
using ll = long long;
using ull = unsigned long long;
using pII = pair<int, int>;
using pLL = pair<ll, ll>;
// head

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string t;
        for (auto& c : s) {
            t += c;
            if (t.size() == k) {
                res.push_back(t);
                t = "";
            }
        }

        if (!t.empty()) {
            t += string(k - (t.size()), fill);
            res.push_back(t);
        }

        return res;
    }
};

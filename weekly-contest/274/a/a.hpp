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
    bool checkString(const string& s) {
        int f = 0;
        for (const auto& c : s) {
            if (c == 'a') {
                if (f)
                    return false;
            }

            if (c == 'b') {
                f = 1;
            }
        }

        return true;
    }
};

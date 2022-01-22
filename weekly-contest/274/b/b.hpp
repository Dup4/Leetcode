#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif

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
    int numberOfBeams(const vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int res = 0;
        int pre = 0;
        int now = 0;
        for (int i = 0; i < n; i++) {
            now = 0;
            for (int j = 0; j < m; j++) {
                now += (bank[i][j] == '1');
            }
            res += now * pre;
            if (now) {
                pre = now;
            }
        }

        return res;
    }
};

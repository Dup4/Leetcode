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
    int minimumCost(vector<int>& cost) {
        sort(All(cost));
        int res = 0;
        while (cost.size() >= 3) {
            res += cost.back();
            cost.pop_back();
            res += cost.back();
            cost.pop_back();
            cost.pop_back();
        }

        for (auto& c : cost) {
            res += c;
        }

        return res;
    }
};

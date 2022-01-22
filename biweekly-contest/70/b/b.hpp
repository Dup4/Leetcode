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

const ll INF = 0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll Max = -INF;
        ll Min = INF;
        ll ret = 0;

        for (auto& a : differences) {
            ret += a;
            Max = max(Max, ret);
            Min = min(Min, ret);
        }

        ll _lower = lower;
        ll _upper = upper;

        if (Min < 0) {
            _lower -= Min;
        }

        if (Max > 0) {
            _upper -= Max;
        }

        return max(0ll, _upper - _lower + 1);
    }
};

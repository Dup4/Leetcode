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
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        ll tot = 0;
        for (auto& b : batteries) tot += b;

        auto ok = [&](ll x) {
            ll sum = 0;
            for (auto& b : batteries) {
                sum += min(1ll * b, x);
            }

            return sum >= x * n;
        };

        ll l = 0, r = tot / n, res = 0;
        while (r - l >= 0) {
            ll mid = (l + r) >> 1;
            if (ok(mid)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};

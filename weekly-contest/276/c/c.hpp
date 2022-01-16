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
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> ans(n + 5, 0);
        for (int i = 0; i < n; i++) {
            int m = i + 1 + questions[i][1];
            if (m > n) {
                m = n;
            }
            if (i) {
                ans[i] = max(ans[i], ans[i - 1]);
            }
            ans[m] = max(ans[m], ans[i] + questions[i][0]);
        }

        ll res = 0;
        for (auto& a : ans) res = max(res, a);
        return res;
    }
};

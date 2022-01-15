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
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int m = 0;
        for (auto& a : nums) m += a;

        vector<int> sum(n * 2 + 1, 0);
        for (int i = 1; i <= n * 2; i++) {
            sum[i] = sum[i - 1] + (nums[(i - 1) % n] == 0);
        }

        int res = n;
        for (int i = 0; i < n; i++) {
            res = min(res, sum[i + m] - sum[i]);
        }

        return res;
    }
};

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

constexpr int N = 110;
vector<bool> has;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        size_t n = matrix.size();

        constexpr auto ok = [](const vector<bool>& has) {
            size_t n = has.size();
            for (int i = 1; i < n; ++i) {
                if (!has[i]) {
                    return false;
                }
            }

            return true;
        };

        for (int i = 0; i < n; i++) {
            has = vector<bool>(n + 1, false);
            for (int j = 0; j < n; j++) {
                has[matrix[i][j]] = 1;
            }

            if (!ok(has)) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            has = vector<bool>(n + 1, false);
            for (int j = 0; j < n; j++) {
                has[matrix[j][i]] = 1;
            }

            if (!ok(has)) {
                return false;
            }
        }

        return true;
    }
};

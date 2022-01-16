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
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while (target > 1 && maxDoubles) {
            ++res;
            if (target & 1) {
                --target;
            } else {
                --maxDoubles;
                target /= 2;
            }
        }

        return res + (target - 1);
    }
};

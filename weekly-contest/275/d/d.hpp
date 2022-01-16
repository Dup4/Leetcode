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

struct node {
    int a;
    int b;
};

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<node> node_list;
        for (int i = 0; i < n; i++) {
            node_list.emplace_back(node{.a = plantTime[i], .b = growTime[i]});
        }

        sort(All(node_list), [&](const node& a, const node& b) {
            return a.b > b.b;
        });

        int res = 0;
        int sum = 0;
        for (auto& a : node_list) {
            res = max(res, sum + a.a + a.b);
            sum += a.a;
        }

        return res;
    }
};

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

struct node {
    int x, y, w, price;

    bool operator<(const node& other) const {
        if (w != other.w) {
            return w > other.w;
        }

        if (price != other.price) {
            return price > other.price;
        }

        if (x != other.x) {
            return x > other.x;
        }

        return y > other.y;
    }
};

int dir[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
};

class Solution {
public:
    vector<vector<int>> highestRankedKItems(
            vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int sx = start[0], sy = start[1];

        priority_queue<node> pq;
        pq.push({sx, sy, 0, grid[sx][sy]});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> res;

        vis[sx][sy] = 1;

        while (!pq.empty() && res.size() < k) {
            node t = pq.top();
            pq.pop();

            if (t.price >= pricing[0] && t.price <= pricing[1]) {
                res.emplace_back(vector<int>{t.x, t.y});
            }

            for (int i = 0; i < 4; i++) {
                int nx = t.x + dir[i][0];
                int ny = t.y + dir[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                if (vis[nx][ny] == 1) {
                    continue;
                }

                vis[nx][ny] = 1;
                if (grid[nx][ny] == 0) {
                    continue;
                }

                pq.push({nx, ny, t.w + 1, grid[nx][ny]});
            }
        }

        return res;
    }
};

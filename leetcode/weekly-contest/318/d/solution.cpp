#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define bitcnt(x) (__builtin_popcountll(x))
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define MP make_pair

using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using VLL = std::vector<ll>;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
    return a > b ? a = b, 1 : 0;
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

const ll INF = 0x3f3f3f3f;

const int N = 4e3 + 10;

struct edge {
    int to, capacity, cost, rev;
    edge() {}
    edge(int to, int _capacity, int _cost, int _rev) : to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};

struct Min_Cost_Max_Flow {
    int V;
    ll H[N + 5], dis[N + 5], PreV[N + 5], PreE[N + 5];
    vector<edge> G[N + 5];

    void Init(int n) {
        V = n;
        for (int i = 0; i <= V; ++i) G[i].clear();
    }

    void addedge(int from, int to, int cap, int cost) {
        G[from].push_back(edge(to, cap, cost, G[to].size()));
        G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
    }

    ll Min_cost_max_flow(int s, int t, ll f, int &flow) {
        ll res = 0;
        fill(H, H + 1 + V, 0);
        while (f) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            fill(dis, dis + 1 + V, INF);
            dis[s] = 0;
            q.push(pair<int, int>(0, s));
            while (!q.empty()) {
                pair<int, int> now = q.top();
                q.pop();
                int v = now.second;
                if (dis[v] < now.first)
                    continue;
                for (int i = 0, sze = (int)G[v].size(); i < sze; ++i) {
                    edge &e = G[v][i];
                    if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
                        dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
                        PreV[e.to] = v;
                        PreE[e.to] = i;
                        q.push(pair<int, int>(dis[e.to], e.to));
                    }
                }
            }
            if (dis[t] == INF)
                break;
            for (int i = 0; i <= V; ++i) H[i] += dis[i];
            int d = f;
            for (int v = t; v != s; v = PreV[v]) d = min(d, G[PreV[v]][PreE[v]].capacity);
            f -= d;
            flow += d;
            res += d * H[t];
            for (int v = t; v != s; v = PreV[v]) {
                edge &e = G[PreV[v]][PreE[v]];
                e.capacity -= d;
                G[v][e.rev].capacity += d;
            }
        }
        return res;
    }
} MCMF;

class Solution {
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        int n = int(robot.size());
        int m = int(factory.size());
        int t = n + m + 10;

        MCMF.Init(t);

        int st = 0;
        int ed = t;

        for (int i = 1; i <= n; i++) {
            MCMF.addedge(st, i, 1, 0);
        }

        for (int j = 1; j <= m; j++) {
            MCMF.addedge(n + j, ed, factory[j - 1][1], 0);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                MCMF.addedge(i, n + j, 1, abs(robot[i - 1] - factory[j - 1][0]));
            }
        }

        int flow = 0;
        ll res = MCMF.Min_cost_max_flow(st, ed, INF, flow);

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif

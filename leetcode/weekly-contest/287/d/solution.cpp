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
const ll mod = 1e9 + 7;

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

class Encrypter {
public:
    string mp[280];
    vector<string> d;
    map<string, vector<char>> mpv;

    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary) {
        for (int i = 0; i < keys.size(); i++) {
            mp[keys[i]] = values[i];

            if (mpv.count(values[i]) == 0) {
                mpv[values[i]] = vector<char>();
            }

            mpv[values[i]].push_back(keys[i]);
        }

        d = dictionary;
    }

    string encrypt(string word1) {
        string res = "";
        for (const auto &c : word1) {
            res += mp[c];
        }
        return res;
    }

    int decrypt(string word2) {
        auto p = vector<int>(d.size(), 0);

        auto check = [](char c, vector<char> &cc) {
            for (const char &_c : cc) {
                if (c == _c) {
                    return true;
                }
            }

            return false;
        };

        for (int j = 0; j < word2.length(); j += 2) {
            for (int i = 0; i < d.size(); i++) {
                if (p[i] == -1 || p[i] >= d[i].size()) {
                    p[i] = -1;
                    continue;
                }

                if (check(d[i][p[i]], mpv[word2.substr(j, 2)])) {
                    ++p[i];
                } else {
                    p[i] = -1;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < d.size(); i++) {
            // cout << p[i] << endl;
            if (p[i] == d[i].size()) {
                ++res;
            }
        }

        return res;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */

#ifdef LOCAL

int main() {
    return 0;
}

#endif

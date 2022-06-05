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

struct node {
    char c;
    node *nx;
    node *pre;
    node(char c) : c(c), nx(nullptr), pre(nullptr) {}
    ~node() {}
};

class TextEditor {
public:
    node *head, *tail, *cur;
    TextEditor() {
        head = new node('@');
        tail = new node('#');
        cur = head;
        head->nx = tail;
        tail->pre = head;
    }

    ~TextEditor() {
        while (head->c != '#') {
            auto *tmp = head;
            head = head->nx;
            delete tmp;
        }

        if (head) {
            delete head;
        }
    }

    void addText(string text) {
        for (auto c : text) {
            node *n = new node(c);
            n->pre = cur;
            n->nx = cur->nx;
            cur->nx->pre = n;
            cur->nx = n;
            cur = n;
        }
    }

    int deleteText(int k) {
        int res = 0;
        auto *nx = cur->nx;
        for (int i = 0; i < k && cur->c != '@'; i++) {
            ++res;
            auto *tmp = cur;
            cur = cur->pre;
            delete tmp;
        }

        cur->nx = nx;
        nx->pre = cur;

        return res;
    }

    string cursorLeft(int k) {
        for (int i = 0; i < k && cur->c != '@'; i++) {
            cur = cur->pre;
        }

        return getString();
    }

    string cursorRight(int k) {
        for (int i = 0; i < k && cur->nx->c != '#'; i++) {
            cur = cur->nx;
        }

        return getString();
    }

    string getString() {
        string res = "";
        auto *tmp = cur;
        for (int i = 0; i < 10 && tmp->c != '@'; i++) {
            res += tmp->c;
            tmp = tmp->pre;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

#ifdef LOCAL

int main() {
    return 0;
}

#endif

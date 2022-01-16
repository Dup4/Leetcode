#pragma once
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
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<int, bool> hs;

        for (auto& s : startWords) {
            int mask = 0;
            for (auto& c : s) mask |= (1 << (c - 'a'));
            hs[mask] = 1;
        }

        int res = 0;
        for (auto& s : targetWords) {
            int mask = 0;
            for (auto& c : s) mask |= (1 << (c - 'a'));
            for (int i = 0; i < 26; i++) {
                if (((mask >> i) & 1) == 1)
                    if (hs.count(mask ^ (1 << i))) {
                        res++;
                        break;
                    }
            }
        }

        return res;
    }
};

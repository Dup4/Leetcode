#include <bits/stdc++.h>
#include <debug.hpp>
using namespace std;

int main() {
    assert_eq(vector<int>{1, 2, 3}, vector<int>{1, 2, 3});
    assert_eq(string("abc"), string("abc"));
    assert_eq("abc", "abc");

    pt(string("DD"), "AA", 1, 2, "AA", vector<int>{1, 2, 3}, map<int, int>{{1, 1}, {2, 2}});
    pt(vector<int>{1, 2, 3});

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;

    dbg(a, b, c, d, e, f);
}

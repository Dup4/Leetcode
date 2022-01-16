#include <bits/stdc++.h>
#include <debug.hpp>
#include <weekly-contest/274/a/a.hpp>
using namespace std;

int main() {
    auto s = Solution();

    assert_eq(s.checkString("aaabbb"), true);
    assert_eq(s.checkString("abab"), false);
    assert_eq(s.checkString("bbb"), true);

    return 0;
}

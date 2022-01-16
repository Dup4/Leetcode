#pragma once
#include <bits/stdc++.h>
using namespace std;

constexpr char* COLOR_GREEN = "\033[0;32m";
constexpr char* COLOR_RED = "\033[0;31m";
constexpr char* COLOR_END = "\033[0m";

void err() {
    cout << "\033[39;0m" << endl;
}

template <class T, class... Ts>
void err(const T& arg, const Ts&... args) {
    cout << arg << ' ';
    err(args...);
}

template <template <typename...> class T, typename t, typename... A>
void err(const T<t>& arg, const A&... args) {
    for (const auto& v : arg) cout << v << ' ';
    err(args...);
}

#define dbg(x...)                             \
    {                                         \
        cout << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    }

void ptt() {
    cout << endl;
}

template <class T, class... Ts>
void ptt(const T& arg, const Ts&... args) {
    cout << ' ' << arg;
    ptt(args...);
}

template <class T, class... Ts>
void pt(const T& arg, const Ts&... args) {
    cout << arg;
    ptt(args...);
}

void pt() {}

template <template <typename...> class T, typename t, typename... A>
void pt(const T<t>& arg, const A&... args) {
    for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1];
    pt(args...);
}

// template <typename T>
// void assert_eq() {}

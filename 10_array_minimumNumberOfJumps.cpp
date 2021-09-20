#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <chrono>
#include <complex>
#include <condition_variable>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

#define ll long long int
#define endl '\n'
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff(i, x, n) for (ll i = x; i < n; i++)
#define fa(x, a) for (auto x : a)
#define vec vector<ll>
#define all(a) a.begin(), a.end()

using namespace std;

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return (a.second < b.second);
}

ll minJumpsDP(vec &a, ll n) {
    if (n <= 1) {
        return 0;
    }

    if (a[0] == 0) {
        return -1;
    }
    vec jumps(n, LLONG_MAX);
    jumps[0] = 0;
    ff(i, 1, n) {
        f(j, i) {
            if (i <= j + a[j]) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }
    return jumps[n - 1] <= n ? jumps[n - 1] : -1;
}

ll minJumps(vec &arr, ll n) {
    if (n <= 1) {
        return 0;
    }
    if (arr[0] == 0) {
        return -1;
    }

    ll maxReach{arr[0]}, step{arr[0]}, jumps{1};

    ff(i, 1, n) {
        if (i == n - 1) {
            return jumps;
        }

        maxReach = max(maxReach, i + arr[i]);  // 4 {9}

        step--;

        if (step == 0) {
            jumps++;

            if (maxReach - i <= 0) {
                return -1;
            }

            step = maxReach - i;
        }
    }

    return -1;
}

void solve() {
    ll n;
    cin >> n;
    vec a(n);
    f(i, n) cin >> a[i];

    cout << minJumps(a, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

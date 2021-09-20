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

bool sortByEndingTime(vec &a, vec &b) {
    if (a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

vector<vec> merge(vector<vec> &intervals, ll n) {
    sort(all(intervals), sortByEndingTime);

    vector<vec> answers;

    ll start = intervals[0][0];
    ll end = intervals[0][1];

    ll i = 0;
    while (i < n) {
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
            if (i == n - 1) {
                answers.push_back({start, end});
            }
        }

        else {
            answers.push_back({start, end});

            start = intervals[i][0];
            end = intervals[i][1];

            if (i == n - 1) {
                answers.push_back({start, end});
            }
        }

        i++;
    }
    return answers;
}

void solve() {
    ll n;
    cin >> n;

    vector<vec> intervals;

    f(i, n) {
        ll start, end;
        cin >> start >> end;

        intervals.push_back({start, end});
    }

    // fa(x, intervals) { cout << x[0] << "->" << x[1] << ' '; }

    // cout << endl;

    vector<vec> answers = merge(intervals, n);

    fa(x, answers) { cout << x[0] << "->" << x[1] << ' '; }

    cout << endl;
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

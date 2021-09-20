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

ll merge(vec &a, ll left, ll mid, ll right) {
    ll const subArray1 = mid - left + 1;
    ll const subArray2 = right - mid;

    ll best = 0;

    vec leftArr(subArray1), rightArr(subArray2);

    f(i, subArray1) leftArr[i] = a[left + i];
    f(i, subArray2) rightArr[i] = a[mid + 1 + i];

    ll i = 0, j = 0;

    while (i < subArray1 && j < subArray2) {
        if (leftArr[i] <= rightArr[j]) {
            if (best == 0) {
                best = rightArr[subArray2 - 1] - leftArr[i];
            }

            a[left] = leftArr[i];
            i++;
        } else {
            a[left] = rightArr[j];
            j++;
        }
        left++;
    }

    while (i < subArray1) {
        a[left++] = leftArr[i++];
    }
    while (j < subArray2) {
        a[left++] = rightArr[j++];
    }

    return best;
}

ll mergesort(vec &a, ll left, ll right) {
    ll best = 0;
    if (left >= right) {
        return best;
    }

    ll mid = left + (right - left) / 2;

    best = max(best, mergesort(a, left, mid));
    best = max(best, mergesort(a, mid + 1, right));
    best = max(best, merge(a, left, mid, right));

    return best;
}

ll faster(vec &a, ll n) {
    ll ans = 0;
    ll mi = INT_MAX;

    for (ll x : a) {
        mi = min(x, mi);
        ans = max(ans, x - mi);
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vec a(n);
    f(i, n) cin >> a[i];

    /********* Divide And Conquer *********/
    /**
     * The modified sort algo works on the principle that that the
     * best profit will be the maximum of following three arrays
     * 1> Left Sorted Array
     * 2> Right Sorted Array
     * 3> The merged array of both above arrays
     */
    // cout << mergesort(a, 0, n - 1) << endl;

    /********* Much Faster Algo *********/

    cout << faster(a, n) << endl;
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
